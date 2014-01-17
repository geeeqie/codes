from ps4a import *
import time


#
#
# Problem #6: Computer chooses a word
#
#

def isWordInHand(word, hand):
    freq = getFrequencyDict(word)
    for letter in word:
        if freq[letter] > hand.get(letter, 0):
            return False
    return True

def compChooseWord(hand, wordList):
    """
    Given a hand and a wordList, find the word that gives 
    the maximum value score, and return it.

    This word should be calculated by considering all the words
    in the wordList.

    If no words in the wordList can be made from the hand, return None.

    hand: dictionary (string -> int)
    wordList: list (string)
    returns: string or None
    """
    bestWord = None
    maxScore = 0
    for word in wordList:
        if isWordInHand(word, hand):
            score = getWordScore(word, sum(hand.values()))
            if score > maxScore:
                maxScore = score
                bestWord = word
    return bestWord


#
# Problem #7: Computer plays a hand
#
def compPlayHand(hand, wordList, n):
    """
    Allows the computer to play the given hand, following the same procedure
    as playHand, except instead of the user choosing a word, the computer 
    chooses it.

    1) The hand is displayed.
    2) The computer chooses a word.
    3) After every valid word: the word and the score for that word is 
    displayed, the remaining letters in the hand are displayed, and the 
    computer chooses another word.
    4)  The sum of the word scores is displayed when the hand finishes.
    5)  The hand finishes when the computer has exhausted its possible
    choices (i.e. compChooseWord returns None).
 
    hand: dictionary (string -> int)
    wordList: list (string)
    """
    # TO DO ... <-- Remove this comment when you code this function
    total = 0
    while sum(hand.values()) > 0:
        print 'Current Hand:',
        displayHand(hand)
        word = compChooseWord(hand, wordList)
        if word != None and isValidWord(word, hand, wordList):
            score = getWordScore(word, n)
            total += score
            print '"%s" earned %d points. Total: %d points' % (word, score, total)
            print
            hand = updateHand(hand, word)
        else:
            break
    print 'Total score: %d points.' % total

    
#
# Problem #8: Playing a game
#
#
def playGame(wordList):
    """
    Allow the user to play an arbitrary number of hands.
 
    1) Asks the user to input 'n' or 'r' or 'e'.
        * If the user inputs 'e', immediately exit the game.
        * If the user inputs anything that's not 'n', 'r', or 'e', keep asking them again.

    2) Asks the user to input a 'u' or a 'c'.
        * If the user inputs anything that's not 'c' or 'u', keep asking them again.

    3) Switch functionality based on the above choices:
        * If the user inputted 'n', play a new (random) hand.
        * Else, if the user inputted 'r', play the last hand again.
      
        * If the user inputted 'u', let the user play the game
          with the selected hand, using playHand.
        * If the user inputted 'c', let the computer play the 
          game with the selected hand, using compPlayHand.

    4) After the computer or user has played the hand, repeat from step 1

    wordList: list (string)
    """
    hand = None
    while True:
        cmd = raw_input('Enter n to deal a new hand, r to replay the last hand, or e to end game: ')
        if cmd == 'e':
            break
        elif cmd == 'n' or cmd =='r':
            if cmd == 'n':
                hand = dealHand(HAND_SIZE)
            else: # cmd == 'r'
                if hand == None:
                    print "Please play a new hand first!"
                    continue
            while True:
                whoplay = raw_input('Enter u to have yourself play, c to have the computer play: ')
                if whoplay == 'u':
                    playHand(hand.copy(), wordList, HAND_SIZE)
                    break
                elif whoplay == 'c':
                    compPlayHand(hand.copy(), wordList, HAND_SIZE)
                    break
                else:
                    print "Invalid command."
            print
        else:
            print "Invalid command."

        
#
# Build data structures used for entire session and play game
#
if __name__ == '__main__':
    wordList = loadWords()
    playGame(wordList)


