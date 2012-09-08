# Problem Set 5: Ghost
# Name: Geeeqie
# Collaborators: 
# Time: 
#

import random

# -----------------------------------
# Helper code
# (you don't need to understand this helper code)
import string

WORDLIST_FILENAME = "../words.txt"

def load_words():
    """
    Returns a list of valid words. Words are strings of lowercase letters.
    
    Depending on the size of the word list, this function may
    take a while to finish.
    """
    print "Loading word list from file..."
    # inFile: file
    inFile = open(WORDLIST_FILENAME, 'r', 0)
    # wordlist: list of strings
    wordlist = []
    for line in inFile:
        wordlist.append(line.strip().lower())
    print "  ", len(wordlist), "words loaded."
    return wordlist

def get_frequency_dict(sequence):
    """
    Returns a dictionary where the keys are elements of the sequence
    and the values are integer counts, for the number of times that
    an element is repeated in the sequence.

    sequence: string or list
    return: dictionary
    """
    # freqs: dictionary (element_type -> int)
    freq = {}
    for x in sequence:
        freq[x] = freq.get(x,0) + 1
    return freq


# (end of helper code)
# -----------------------------------

# Actually load the dictionary of words and point to it with 
# the wordlist variable so that it can be accessed from anywhere
# in the program.
wordlist = load_words()

# TO DO: your code begins here!

def is_illegal_word_fragment(new_word):
    for word in wordlist:
        if word[:len(new_word)] == new_word.lower():
#        if word.startswith(new_word):
            return True
    return False

def ghost():
    print 'Welcome to Ghost!'
    print 'Player 1 goes first'

    current_player = 1
    current_word = ''

    while True:
        print "Current word fragment: '" + current_word + "'"
        print "Player " + str(current_player) + "'s turn"
        print "Player " + str(current_player) + " says letter:",
        letter = raw_input()
        if len(letter) != 1 or (not letter in string.ascii_letters):
            print "'" + letter + "' is not a letter, try again"
            continue

        # TODO: some check on letter

        new_word = current_word + letter
        if len(new_word) > 3 and (new_word.lower() in wordlist):
            print "Player " + str(current_player) + " loses because '" + new_word + "' is a word"
            print "Player " + str(current_player%2+1) + " wins"
            break
        elif not is_illegal_word_fragment(new_word):
            print "Player " + str(current_player) + " loses because no word begins with '" + new_word + "'"
            print "Player " + str(current_player%2+1) + " wins"
            break
        current_player = current_player%2 + 1
        current_word = new_word

    print "Game over."

ghost()
