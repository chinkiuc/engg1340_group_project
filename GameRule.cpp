//reading gamerules from gamerule.txt
//printing the content of gamerules 
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
static int GameRule()
{
	extern int back;
	string rule;
	
	ifstream fin("gamerule.txt");
	if (fin.fail()){
		cout << "Cannot open gamerule.txt! Exit game......";
		exit(1);
	}
	
	while (getline(fin, rule)){
		cout << rule << endl;
	}
	fin.close();
	cout << "  Press <Enter> to back to menu...\n\n";
	cin.get();
	cin.get();
	
	back = 1;
	return 0;
}
