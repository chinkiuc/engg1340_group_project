$make main_main

g++ -c Beginning.cpp
g++ -c ChangePlayerName.cpp
g++ -c EnterPlayerName.cpp
g++ -c gameover.cpp
g++ -c GameRule.cpp
g++ -c ScoreBoard.cpp
g++ -c swap.cpp
g++ -c main.cpp

g++ -o main Beginning.o ChangePlayerName.o EnterPlayerName.o gameover.o GameRule.o ScoreBoard.o swap.o main.o
