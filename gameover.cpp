// end of game output
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int gameover()
{
	extern string playername;
	extern int back, scoresum;
	int option;
	
	ofstream fout("PlayerRecord.txt", ios::app);
	if (fout.fail())
	{
		cout << "Cannot open scoreboard.txt! Exit game......";
		exit(1);
	}
	fout << playername << " " << scoresum << endl;
	fout.close();
	
	cout << "\033[2J\033[1;1H";
	cout <<"\n\n\n\n\n\n       ==========================================================";
	cout <<"\n\n                         Game Over!  You Lose!";
	cout <<"\n\n                          Player name:  "<<playername;
	cout <<"\n\n                           Your Score:  "<<scoresum;
	cout << "\n\n                  Back to meun: 1.      Exit: 2.";
	cout <<"\n\n       ==========================================================";
	cout << "\n\n                  :";
	cin >> back;

}
