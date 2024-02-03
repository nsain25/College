#Single player game of gussing the correct word which is the right choice and any other word is false and is given n chances to guess
#Once gussed, program terminates with message either won or lost
#define number of guesses, guess limit and out_guess=false. Don't provide a list of words. user has to guess the word and the program will tell if it is correct or not
#on guessing the correct word, the program will terminate with a message "You have won!"
#on guessing the wrong word, the program will terminate with a message "You have lost!"

import random
import time

def get_word():
    #user input for the word
    word = input("Enter the word: ")
    return word

def play(word):
    #define number of guesses, guess limit and out_guess=false. Don't provide a list of words. user has to guess the word and the program will tell if it is correct or not
#on guessing the correct word, the program will terminate with a message "You have won!"
#on guessing the wrong word, the program will terminate with a message "You have lost!"
    guess = ""
    guess_count = 0
    #enter guess limit as user input
    guess_limit = int(input("Enter the number of guesses: "))
    out_guess = False
    while guess != word and not(out_guess):
        if guess_count < guess_limit:
            guess = input("Enter guess: ")
            guess_count += 1
        else:
            out_guess = True
    if out_guess:
        print("You have lost!")
    else:
        print("You have won!")
        
def main():
    word = get_word()
    play(word)
    
if __name__ == "__main__":
    main()
    
    
