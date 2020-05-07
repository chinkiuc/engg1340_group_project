//Accept playername from user input
#include <iostream>
#include <string>
#ifdef _WIN64
	#define CLEAR system("cls")
#elif _WIN32
	#define CLEAR system("cls")
#else 
	#define CLEAR system("clear")
#endif
using namespace std;
void EnterPlayerName()
{
	extern string playername;
	cout<<"\n\n\n\n\n\n\n          Hi, Player! \n\n          Please enter your name:  ";
	cin >> playername;
	CLEAR;
	
}
