# 6.00 Problem Set 3
# 
# Hangman game
#

# -----------------------------------
# Helper code
# You don't need to understand this helper code,
# but you will have to know how to use the functions
# (so be sure to read the docstrings!)

import random
import string

WORDLIST_FILENAME = "words.txt"

def loadWords():
    """
    Returns a list of valid words. Words are strings of lowercase letters.
    
    Depending on the size of the word list, this function may
    take a while to finish.
    """
    print "Loading word list from file..."
    # inFile: file
    inFile = open(WORDLIST_FILENAME, 'r', 0)
    # line: string
    line = inFile.readline()
    # wordlist: list of strings
    wordlist = string.split(line)
    print "  ", len(wordlist), "words loaded."
    return wordlist

def chooseWord(wordlist):
    """
    wordlist (list): list of words (strings)

    Returns a word from wordlist at random
    """
    return random.choice(wordlist)

# end of helper code
# -----------------------------------

# Load the list of words into the variable wordlist
# so that it can be accessed from anywhere in the program
wordlist = loadWords()

def isWordGuessed(secretWord, lettersGuessed):
    '''
    secretWord: string, the word the user is guessing
    lettersGuessed: list, what letters have been guessed so far
    returns: boolean, True if all the letters of secretWord are in lettersGuessed;
      False otherwise
    '''
    # FILL IN YOUR CODE HERE...
    return set([x for x in secretWord]) <= set(lettersGuessed)


def getGuessedWord(secretWord, lettersGuessed):
    '''
    secretWord: string, the word the user is guessing
    lettersGuessed: list, what letters have been guessed so far
    returns: string, comprised of letters and underscores that represents
      what letters in secretWord have been guessed so far.
    '''
    # FILL IN YOUR CODE HERE...
    import string
    lettersNotGuessed = set(string.ascii_lowercase) - set(lettersGuessed)
    for letter in lettersNotGuessed:
        secretWord = secretWord.replace(letter, '_')
    return secretWord


def getAvailableLetters(lettersGuessed):
    '''
    lettersGuessed: list, what letters have been guessed so far
    returns: string, comprised of letters that represents what letters have not
      yet been guessed.
    '''
    # FILL IN YOUR CODE HERE...
    import string
    lettersNotGuessed = set(string.ascii_lowercase) - set(lettersGuessed)
    return ''.join(sorted(lettersNotGuessed))
    

def hangman(secretWord):
    '''
    secretWord: string, the secret word to guess.

    Starts up an interactive game of Hangman.

    * At the start of the game, let the user know how many 
      letters the secretWord contains.

    * Ask the user to supply one guess (i.e. letter) per round.

    * The user should receive feedback immediately after each guess 
      about whether their guess appears in the computer's word.

    * After each round, you should also display to the user the 
      partially guessed word so far, as well as letters that the 
      user has not yet guessed.

    Follows the other limitations detailed in the problem write-up.
    '''
    # FILL IN YOUR CODE HERE...

### Welcome to the game, Hangman!
### 	I am thinking of a word that is 4 letters long.
### 	-------------
### 	You have 8 guesses left.
### 	Available letters: abcdefghijklmnopqrstuvwxyz
### 	Please guess a letter: a
### 	Good guess: _ a_ _
### 	------------
### 	You have 8 guesses left.
### 	Available letters: bcdefghijklmnopqrstuvwxyz
### 	Please guess a letter: a
### 	Oops! You've already guessed that letter: _ a_ _
    print 'Welcome to the game, Hangman!'
    print 'I am thinking of a word that is %d letters long.' % len(secretWord)
    print '-------------'

    mistakesMade = 0
    lettersGuessed = []
    availableLetters = string.ascii_lowercase
    while True:
        print 'You have %d guesses left.' % (8 - mistakesMade)
        print 'Available letters: %s' % getAvailableLetters(lettersGuessed)
        print 'Please guess a letter: ',
        letter = raw_input().strip().lower();
        if letter in lettersGuessed:
            print "Oops! You've already guessed that letter: %s" % getGuessedWord(secretWord, lettersGuessed)
        else:
            lettersGuessed.append(letter)
            if letter in secretWord:
                print 'Good guess: %s' % getGuessedWord(secretWord, lettersGuessed)
            else:
                print 'Oops! That letter is not in my word: %s' % getGuessedWord(secretWord, lettersGuessed)
                mistakesMade += 1
        print '-------------'

        if isWordGuessed(secretWord, lettersGuessed):
            print 'Congratulations, you won!'
            break

        if mistakesMade >= 8:
            print 'Sorry, you ran out of guesses. The word was %s.' % secretWord
            break


# When you've completed your hangman function, uncomment these two lines
# and run this file to test! (hint: you might want to pick your own
# secretWord while you're testing)

secretWord = chooseWord(wordlist).lower()
hangman(secretWord)
