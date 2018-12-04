# cs50-projects
Collection of my solutions to Harvard's CS50 problem sets. Below are some short descriptions of each problem set's specifications along with links to their more detailed specifications.

# Problem Set 1: C

## [hello.c](https://docs.cs50.net/2018/x/psets/1/pset1.html):
Implement a program that prints out a simple greeting to the user, per the below.
```
$ ./hello
hello, world
```

## [mario.c](https://docs.cs50.net/2018/x/psets/1/mario/more/mario.html)
Implement a program that prints out a double half-pyramid of a specified height, per the below.
```
$ ./mario
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
```

## [credit.c](https://docs.cs50.net/2018/x/psets/1/credit/credit.html)
Implement a program that determines whether a provided credit card number is valid according to Luhn’s algorithm and prints the card's respective financial service.
```
$ ./credit
Number: 378282246310005
AMEX
```

# Problem Set 2: Crypto

## [caesar.c](https://docs.cs50.net/2018/x/psets/2/caesar/caesar.html)
Implement a program that encrypts messages using Caesar’s cipher, per the below.
```
$ ./caesar 13
plaintext:  HELLO
ciphertext: URYYB
```

## [vigenere.c](https://docs.cs50.net/2018/x/psets/2/vigenere/vigenere.html)
Implement a program that encrypts messages using Vigenère’s cipher, per the below.
```
$ ./vigenere ABC
plaintext:  HELLO
ciphertext: HFNLP
```

## [crack.c](https://docs.cs50.net/2018/x/psets/2/crack/crack.html)
Implement a program that cracks passwords, per the below.
```
$ ./crack 50fkUxYHbnXGw
rofl
```

# Problem Set 3: [Music](https://docs.cs50.net/2018/x/psets/3/music/music.html)

## `bday.txt`
In bday.txt, type the ASCII representation of Happy Birthday, translating its sheet music, above, to the machine-readable representation prescribed herein. You should find that the song begins with:
```
D4@1/8
D4@1/8
E4@1/4
D4@1/4
G4@1/4
F#4@1/2
```
## `helpers.c`
### `is_rest`
Complete the implementation of is_rest in helpers.c. Recall that blank lines represent rests in our machine-readable format. And recall that synthesize will call this function in order to determine if one of the lines a user has typed in is indeed blank.

## `duration`
Complete the implementation of duration in helpers.c. Recall that this function should take as input as a string a fraction and convert it into some integral number of eighths. You may assume that duration will only be passed a string formatted as X/Y, whereby each of X and Y is a positive decimal digit, and Y is, moreover, a power of 2.

## `frequency`
Finally, complete the implementation of frequency in helpers.c. Recall that this function should take as input as a string a note (e.g., A4) and return its corresponding frequency in hertz as an int.

# Problem Set 4: Forensics

## [Whodunit](https://docs.cs50.net/2018/x/psets/4/whodunit/whodunit.html)
Answer some questions and then implement a program that reveals a hidden message in a BMP, per the below.
```
$ ./whodunit clue.bmp verdict.bmp
```
## [Resize](https://docs.cs50.net/2018/x/psets/4/resize/more/resize.html)
Implement a program that resizes BMPs, per the below.
```
$ ./resize .25 large.bmp small.bmp
$ ./resize 4 small.bmp large.bmp
```

## [Recover](https://docs.cs50.net/2018/x/psets/4/recover/recover.html)
Implement a program that recovers JPEGs from a forensic image, per the below.
```
$ ./recover card.raw
```

# Problem Set 5: Mispellings 

## [Speller](https://docs.cs50.net/problems/speller/speller.html)
Implement a program that spell-checks a file, per the below.
```
$ ./speller texts/austinpowers.txt
MISSPELLED WORDS

[...]
Bigglesworth
[...]
Virtucon
[...]
friggin'
[...]
trippy
[...]

WORDS MISSPELLED:
WORDS IN DICTIONARY:
WORDS IN TEXT:
TIME IN load:
TIME IN check:
TIME IN size:
TIME IN unload:
TIME IN TOTAL:
```
# Problem Set 6: Déjà vu

## [Sentimental](https://docs.cs50.net/2018/x/psets/6/sentimental/sentimental)
Port `hello.c` to `hello.py`.

Port `mario.c` to `mario.py`.

Port `cash.c` to `cash.py` or `credit.c` to `credit.py`.

## [Similarities](https://docs.cs50.net/2018/x/psets/6/similarities/less/similarities.html)
* `substrings` is the only part missing from this solution.

## `helpers.py`
### `lines`
Implement lines in such a way that, given two strings, a and b, it returns a list of the lines that are, identically, in both a and b. The list should not contain any duplicates. Assume that lines in a and b will be be separated by \n, but the strings in the returned  list should not end in \n. If both a and b contain one or more blank lines (i.e., a \n immediately preceded by no other characters), the returned list should include an empty string (i.e., "").

### `sentences`
Implement sentences in such a way that, given two strings, a and b, it returns a list of the unique English sentences that are, identically, present in both a and b. The list should not contain any duplicates. Use sent_tokenize from the Natural Language Toolkit to "tokenize" (i.e., separate) each string into a list of sentences. It can be imported with:

`from nltk.tokenize import sent_tokenize`
Per its documentation, sent_tokenize, given a str as input, returns a list of English sentences therein. It assumes that its input is indeed English text (and not, e.g., code, which might coincidentally have periods too).

### `substrings`
Implement substrings in such a way that, given two strings, a and b, and an integer, n, it returns a list of all substrings of length n that are, identically, present in both a and b. The list should not contain any duplicates.

### `templates/index.html`
Implement templates/index.html in such a way that it contains an HTML form via which a user can submit:

a file called `file1`

a file called `file2`

a value of lines, sentences, or substrings for an input called algorithm

a number called `length`

# Problem Set 7: [C$50 Finance](https://docs.cs50.net/problems/finance/finance.html)

Implement a website via which users can "buy" and "sell" stocks.

