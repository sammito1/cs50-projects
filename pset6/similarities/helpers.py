from nltk.tokenize import sent_tokenize

def lines(a, b):
    """Return lines in both a and b"""

    linesInA = a.splitlines()
    linesInB = b.splitlines()

    linesInAB = set(linesInA).intersection(linesInB)
    return list(linesInAB)


def sentences(a, b):
    """Return sentences in both a and b"""

    sentencesInA = sent_tokenize(a)
    sentencesInB = sent_tokenize(b)


    sentencesInAB = set(sentencesInA).intersection(sentencesInB)
    return list(sentencesInAB)


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    # split each string into substrings of length n
    substringsInA = # something

    substringsInB = # something
    # compute list of all substrings appearing in both a and b
    return list(substringsInAB)
