// change the name of the player
#include <iostream>
#include <string>
#define PAUSE cin.get();cin.get();
using namespace std;
char ChangePlayerName()
{
	extern string playername;
	cout << "\n     Please enter your new player name: ";
	cin >> playername;
	cout <<"\n    Finised! Press <Enter> to back to menu......\n\n\n\n";
	PAUSE;
}

