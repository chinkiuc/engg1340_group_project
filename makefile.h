all: Beginning.o ChangePlayerName.o EnterPlayerName.o gameover.o GameRule.o ScoreBoard.o swap.o main.o main run

Beginning.o: Beginning.h
	g++ -c Beginning.h

ChangePlayerName.o: ChangePlayerName.h
	g++ -c ChangePlayerName.h

EnterPlayerName.o: EnterPlayerName.h	
	g++ -c EnterPlayerName.h
	
gameover.o: gameover.h
	g++ -c gameover.h
	
GameRule.o: GameRule.h	
	g++ -c GameRule.h
	
ScoreBoard.o: ScoreBoard.h
	g++ -c ScoreBoard.h
	
swap.o: swap.h
	g++ -c swap.h

main.o: main.h	
	g++ -c main.h

main: Beginning.o ChangePlayerName.o EnterPlayerName.o gameover.o GameRule.o ScoreBoard.o swap.o main.o
	g++ Beginning.o ChangePlayerName.o EnterPlayerName.o gameover.o GameRule.o ScoreBoard.o swap.o main.o -o main

run: ./main
