from cs50 import get_int

# user input for integer greater than 0
while True:
    ccNumber = get_int("Number: ")
    if ccNumber >= 0:
        break

# count number of digits
ccNumberString = str(ccNumber)
numDigits = len(ccNumberString)

# to maximize efficiency, let's just check up front if the number of digits is a valid length for a ccNumber.
if numDigits not in(13, 15, 16):
    print("INVALID")
    exit()

# make a duplicate of ccNumber to iterate through
ccNumberIterator = ccNumber
# strip off the first digit of the iterator
ccNumberIterator //= 10
# if ccNumber was 12345, it should be stripped to 1234


firstDigitSetSum = 0
secondDigitSetSum = 0
currentDigit = 0

# for the first set of digits, multiply by two and add the sum of the products' digits together.
for digit in range(numDigits - 1):
    # `numDigits - 1` because we stripped off the last digit
    currentDigit = ccNumberIterator % 10
    ccNumberIterator //= 100
    currentDigit *= 2

    # add the digits of the current product. There will be a maximum of two digits, so the following works:
    currentDigit = (currentDigit // 10) + (currentDigit % 10)
    firstDigitSetSum += currentDigit

    # if we have exhausted all digits from first digit set
    if ccNumberIterator == 0:
        break

# rest ccNumberIterator and currentDigit
ccNumberIterator = ccNumber
currentDigit = 0

# for the second set of digits
for digit in range(numDigits):
    currentDigit = ccNumberIterator % 10
    ccNumberIterator //= 100
    secondDigitSetSum += currentDigit
    if ccNumberIterator == 0:
        break

finalSum = firstDigitSetSum + secondDigitSetSum

firstTwoDigits = int(str(ccNumber)[:2])

# if final digit of finalSum != 0, INVALID
if finalSum % 10 != 0:
    print("INVALID")
    exit()

# AMEX (15 digits, start w 34 or 37)
if numDigits == 15:
    if firstTwoDigits == 34 or firstTwoDigits == 37:
        print("AMEX")
        exit()
    else:
        print("INVALID")
        exit()
# MasterCard (16 digits, start with 51, 52, 53, 54, or 55)
elif numDigits == 16:
    if firstTwoDigits in(51, 52, 53, 54, 55):
        print("MASTERCARD")
        exit()
    elif firstTwoDigits // 10 == 4:
        print("VISA")
        exit()
# Visa (13 and 16 digit numbers, start with 4)
elif numDigits == 13 and firstTwoDigits // 10 == 4:
    print("MASTERCARD")
    exit()