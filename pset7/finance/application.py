import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    # total cash left for user
    cashdb = db.execute("SELECT cash FROM users WHERE id = :id", id = session["user_id"])
    cash = int(cashdb[0]["cash"])

    # query db for table with userid, cash, symbol, name, shares
    rows = db.execute("SELECT users.id, portfolio.symbol, portfolio.name, portfolio.shares, portfolio.price, portfolio.total "
                      "FROM users "
                      "INNER JOIN portfolio ON users.id = :id",
                      id = session["user_id"])

    # update rows to ensure proper stock pricing and formatting, as well as figuring out the total
    total = 0
    for row in rows:
        quote = lookup(row["symbol"])
        price = float(quote["price"])
        shares = row["shares"]
        row["price"] = usd(price)
        row["total"] = usd(price * shares)
        total += price * shares
    # figure out total value of portfolio stocks + cash left


    return render_template("index.html", rows = rows, cash = usd(cash), total = usd(total + cash))

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    if request.method == "POST":
        quote = lookup(request.form.get("symbol"))
        if not quote:
            return apology("Invalid symbol.")

        # set relevant variables
        symbol = quote["symbol"]
        name = quote["name"]
        price = float(quote["price"])
        shares = int(request.form.get("shares"))

        # request user table
        rows = db.execute("SELECT cash FROM users WHERE id = :id", id = session["user_id"])

        # if not enough cash, return apology, else, continue
        cash = float(rows[0]["cash"])
        if cash < price * shares:
            return apology("Not enough cash!")

        # if if gets to this point, we can create a transaction for it in our ledger db called "history"
        db.execute("INSERT INTO history (userid, symbol, shares, transactionprice) VALUES (:userid, :symbol, :shares, :price)",
                    userid = session["user_id"], symbol = symbol, shares = shares, price = price)

        # check if the user has a row in the portfolio with their ID and this stock's symbol in it.
        symbolRow = db.execute("SELECT symbol FROM portfolio WHERE userid = :userid AND symbol = :symbol",
                                userid = session["user_id"], symbol = symbol)

        # if this query didn't succeed, insert a new row into their portfolio with this transaction.
        if not symbolRow:
            db.execute("INSERT INTO portfolio (userid, symbol, name, shares, price)"
                       "VALUES (:userid, :symbol, :name, :shares, :price)",
                        userid = session["user_id"], symbol = symbol, name = name, shares = shares, price = price)
        # else, add shares to initial shares
        else:
            db.execute("UPDATE portfolio SET shares = shares + :shares WHERE userid = :userid AND symbol = :symbol",
                       shares = shares, userid = session["user_id"], symbol = symbol)

        # withdraw money for transaction
        db.execute("UPDATE users SET cash = cash - :cost WHERE id = :userid",
                    cost = shares * price, userid = session["user_id"])



        # back to home directory
        return redirect("/")

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    ## DISPLAY DATABASE CONTAINING HISTORY OF TRANSACTIONS
    rows = db.execute("SELECT symbol, shares, transactionprice, transacted FROM history WHERE userid = :id",
                      id = session['user_id'])

    # make sure transactionprice is in USD
    for row in rows:
        row["transactionprice"] = usd(row["transactionprice"])

    return render_template("history.html", rows = rows)

@app.route("/deposit", methods=["GET", "POST"])
@login_required
def deposit():
    """Deposit more money into account"""

    if request.method == "POST":
        # get deposit amount
        depositAmount = float(request.form.get("amount"))

        # it's going to have to be a positive number, so we can just insert it straight into our database.
        rows = db.execute("UPDATE users SET cash = cash + :cash WHERE id = :id ", cash = depositAmount, id = session['user_id'])
        return redirect('/')
    else:
        return render_template("deposit.html")

@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    if request.method == 'POST':

        quote = lookup(request.form.get("symbol"))
        if not quote:
            return apology("Invalid symbol.")
        return render_template("quoted.html", name = quote["name"], symbol = quote["symbol"], price = quote["price"])

    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    session.clear()

    if request.method == 'POST':
        if request.form.get("username") == '':
            return apology("Missing username!")

        if request.form.get("password") == '':
            return apology("Missing password!")

        if request.form.get("password (again)") == '':
            return apology("Please confirm password!")

        if request.form.get("password") != request.form.get("password (again)"):
            return apology("Passwords do not match!")

        hashed_password = generate_password_hash(request.form.get("password"))

        result = db.execute("INSERT INTO users (username, hash) VALUES(:username, :password)",
                           username = request.form.get("username"), password = hashed_password)
        if not result:
            return apology("Username already taken.")

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    else:
        return render_template("register.html")



@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method =="POST":
        symbol = request.form.get("symbol")
        shares = int(request.form.get("shares"))
        quote = lookup(symbol)
        currentPrice = float(quote["price"])

        # check if we have enough shares of this symbol to sell. If not, apologize. Else, sell.
        # if we sell and the shares remaining for a stock is 0, delete the row from our portfolio.
        rows = db.execute("SELECT shares FROM portfolio WHERE userid = :userid AND symbol =:symbol",
                          symbol = symbol, userid = session["user_id"])

        if int(rows[0]["shares"]) < shares:
            return apology("Not enough shares.")
        # removes money from account and potentially removes row from db if 0 shares left
        else:
            # if if gets to this point, we can create a transaction for it in our ledger db called "history"
            db.execute("INSERT INTO history (userid, symbol, shares, transactionprice) VALUES (:userid, :symbol, :shares, :price)",
                        userid = session["user_id"], symbol = symbol, shares = -shares, price = currentPrice)

            db.execute("UPDATE portfolio SET shares = shares - :shares WHERE userid = :userid AND symbol =:symbol",
                              shares = shares, userid = session["user_id"], symbol = symbol)

            rows = db.execute("SELECT shares FROM portfolio WHERE userid = :userid AND symbol =:symbol",
                               userid = session["user_id"], symbol = symbol)

            if int(rows[0]["shares"]) == 0:
                db.execute("DELETE FROM portfolio WHERE userid = :userid AND symbol = :symbol",
                            userid = session["user_id"], symbol = symbol)

        # add money to user account from sale of stock
        value = shares * currentPrice
        rows = db.execute("UPDATE users SET cash = cash + :cash WHERE id = :id", id = session["user_id"], cash = value)

        # redirect home
        return redirect("/")

    else:
        rows = db.execute("SELECT symbol, shares FROM portfolio WHERE userid = :userid",
                          userid = session["user_id"])
        return render_template("sell.html", rows = rows)

def errorhandler(e):
    """Handle error"""
    return apology(e.name, e.code)


# listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
