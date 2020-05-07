//The begining of the program
//Displaying project name and developers
#include <iostream>
#ifdef _WIN64
	#define CLEAR system("cls")
#elif _WIN32
	#define CLEAR system("cls")
#else 
	#define CLEAR system("clear")
#endif
#define PAUSE fgetc(stdin);
using namespace std; 
int Begining()
{
	cout <<"\n\n\n\n"<<"      ------------  ENGG1340 Course Project  ------------ \n\n\n\n\n         Developed by:\n";
	cout <<"\n            CHOI CHIN KIU      (3035557351)\n\n            DEV CHORADIA MANOJ (3035666669)\n\n\n\n\n\n         Press <ENTER> key to continue...... \n\n\n\n";
	PAUSE;
	CLEAR;
}
