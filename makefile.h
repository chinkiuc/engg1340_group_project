all: Beginning.o ChangePlayerName.o EnterPlayerName.o gameover.o GameRule.o ScoreBoard.o swap.o main.o main

Beginning.o: Beginning.cpp
	g++ -c Beginning.cpp

ChangePlayerName.o: ChangePlayerName.cpp
	g++ -c ChangePlayerName.cpp

EnterPlayerName.o: EnterPlayerName.cpp	
	g++ -c EnterPlayerName.cpp
	
gameover.o: gameover.cpp
	g++ -c gameover.cpp
	
GameRule.o: GameRule.cpp	
	g++ -c GameRule.cpp
	
ScoreBoard.o: ScoreBoard.cpp
	g++ -c ScoreBoard.cpp
	
swap.o: swap.cpp
	g++ -c swap.cpp

main.o: main.cpp	
	g++ -c main.cpp

//main: Beginning.o ChangePlayerName.o EnterPlayerName.o gameover.o GameRule.o ScoreBoard.o swap.o main.o
//	g++ Beginning.o ChangePlayerName.o EnterPlayerName.o gameover.o GameRule.o ScoreBoard.o swap.o main.o -o main
