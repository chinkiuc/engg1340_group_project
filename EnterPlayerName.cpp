//Accept playername from user input
#include <iostream>
#include <string>
using namespace std;
void EnterPlayerName()
{
	extern string playername;
	cout<<"\n\n\n\n\n\n\n          Hi, Player! \n\n          Please enter your name:  ";
	cin >> playername;
	cout << "\033[2J\033[1;1H";
	
}
