# Engg1340 Group Project
Welcome the Engg1340 group project repo. This is a text-based game project complied with  C++ language.

# Identification of group members
1. Dev Choradia Manoj (3035666669)
2. Choi Chin Kiu (3035557351)

# How to play

A Dual Game.
First is a text guessing game and the second is Hangman. 
The user gets to choose what he/she wishes to play.

**Game 1 :video_game:-- WordFever!** 

*:heavy_exclamation_mark: Basic game rules*

The game is a Single Player game where a player has to guess a certain word in the game within a limited number of guesses. As a player makes a wrong guess the life of the player get deduced. Player can continue guessing until the life is used up. Everytime when player guess the correct word successfully, the life of player restores.

*:white_check_mark:Scoring*

When player answers the correct word, player gets scores.
For stage 1-5, player get 10 scores for each word.
For stage 6-10, player get 50 scores for each word.
For stage 11-20, player get 100 scores for each word.
For stage more than 20, player get 250 scores for each word.

*:white_check_mark:Spree*

When player CONSECUTIVELY guess the correct word without using any life for 5 times, the scores that player can get from each correct words are multiplied by 2. Once player makes one incorrect guess, spree stops.

**Game 2 :video_game:-- HANGMAN**

We know the rules.
Guess the word before the man gets hanged.Pictorial representation available.
Guess letters and fill the blanks to save the man and win the game.
The theme of hangman is movies with 3 sub topic to choose from.

**Game 3 :video_game:-- Tic Tac Toe**

Support single player and mulit-player mode.
3 in a row to win with easy and hard levels to choose from!!

# Features:hammer:

This is a text-guessing game added with different features and functions:
1. Random function used to generate words and other events in the game
2. Multiple arrays and structures used to store words, blanks, letters and other game statuses 
3. Both static and dynamic memory Allocation along with time calculating features
4. Files to save results of ongoing and completed games
5. Pictorial representation and other functions like stacks and queues used for order management.


# Requirements 
1. Generation of random game sets or events
  - using rand() to generate random answer
  - using rand() to swap letters in random order
2. Data structures for storing game status
3. Dynamic memory management
4. File input/output (e.g., for loading/saving game status)
  - Score board
  - game rules
5. Program codes in multiple files
6. Proper indentation and naming styles
  - varibles are named with clear instructions 
  (e.g. back: flag of going back to main menu
        life: for the life of player
        sports/ countries: array of storing words in different categories)
7. In-code documentation
