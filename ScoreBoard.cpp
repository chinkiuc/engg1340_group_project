//score board for Game WordFever!
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <string.h>
#ifdef _WIN64
	#define CLEAR system("cls")
#elif _WIN32
	#define CLEAR system("cls")
#else 
	#define CLEAR system("clear")
#endif
using namespace std;
int ScoreBoard()
{	
	extern int back;
	string namelist[100] = {};
	int scorelist[100] = {};
	string name, tempname;
	int i = 0;
	int score, tempscore;

	CLEAR;
	ifstream fin("PlayerRecord.txt");
	if (fin.fail()){
		cout << "\n\n    No record! Back to menu..";
		back = 1;
	}
	while (fin >> name >> score){
		namelist[i]=name;
		scorelist[i]=score;
		i+=1;
	}
	
	int recordnum =i;
	for (int i=0; i<recordnum;i++){
		for (int j=0; j<recordnum;j++){
			if (scorelist[i]>scorelist[j]){
				tempname = namelist[i];
				namelist[i] = namelist[j];
				namelist[j] = tempname;
				tempscore = scorelist[i];
				scorelist[i] = scorelist[j];
				scorelist[j] = tempscore;				
			}
		}
	}

	cout << "\n\n"<<setw(10)<<"Name"<<setw(22)<<"Score\n";
	cout << "    =======================================\n";
	for (int i=0;i<recordnum;i++)
	{
		cout << setw(10)<< namelist[i]<<" "<<setw(20)<<scorelist[i] <<"\n\n";
	}	
	cout << "    =======================================\n";
	cout <<"    Press <Enter> to back to menu......\n\n";
	back = 1;
	cin.get();
	cin.get();
	return 0;
}
