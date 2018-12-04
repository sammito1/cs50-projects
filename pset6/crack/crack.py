# Ditching this for now.. I'd rather focus on moving on in CS50 vs tinkering with the itertools library for a while.
import itertools
import sys
import crypt

if len(sys.argv) != 2:
    print("Usage: python crack.py hash")
    exit()

givenHash = sys.argv[1]

alphabets = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
unhashedList = itertools.product(alphabets, repeat = 5)

if givenHash in(unhashedList):
    print("True")
else:
    print("False")



