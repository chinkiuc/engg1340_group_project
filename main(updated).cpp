#include <iostream>
#include <string>
#include <string.h>
#include <cstring> 
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <algorithm>

using namespace std;
int stage, score, scoresum, numword, numcategory, spreecount, life, back;
bool spree;
string answer, inputans, category;
char country[100][100] ={"CHINA", "THE UNITED STATES","JAPAN","TAIWAN","HONG KONG","AUSTRALIA","BELGIUM","BRAZIL","BULGARIA","CANADA","COLOMBIA","CUBA","DENMARK","EGYPT","FINLAND","FRANCE","GERMANY","ICELAND","ISRAEL","ITALY","KOREA","MALAYSIA","MEXICO","MOROCCO","NEW ZEALAND","NORWAY","RUSSIA","REPUBLIC OF THE CONGO","SWITZERLAND","THAILAND","TURKEY","UNITED KINGDOM","VIETNAM"};
char sports[100][100] ={"BASKETBALL", "FOOTBALL", "SOCCER","LACROSSE","HOCKEY","TENNIS","VOLLEYBALL","TABLE TENNIS","BASEBALL","RUGBY","GOLF"};
string playername;

int gameover(){
	
	int option;
	
	system("CLS");
	cout <<"\n\n\n\n\n\n       ==========================================================";
	cout <<"\n\n                         Game Over!  You Lose!";
	cout <<"\n\n                          Player name:  "<<playername;
	cout <<"\n\n                           Your Score:  "<<scoresum;
	cout << "\n\n                  Back to meun: 1.      Exit: 2.";
	cout <<"\n\n       ==========================================================";
	cout << "\n\n                  :";
	cin >> back;

}

char swap(string answer){
	
	char word[answer.size()+1];
	strcpy(word, answer.c_str());
	char TEMP;
	int wordnum = strlen(word)-1;
	srand(time(NULL));
	
	//Swapping the answer (FINSHED)
	for (int i=0;i<=wordnum;i++){
		int j=rand()%wordnum;
		TEMP = word[i];
		word[i] = word[j];
		word[j] = TEMP;
	}
	cout <<"\n\n\n\n";
	cout << setw(25);
	//Printing out the swapped word (FINISHED)
	for (int i=0; i<=wordnum;i++){
	if (word[i]==' ')
			cout << "*  ";
		else 
			cout << word[i] << "  ";
	}
	cout <<"\n\n";
}

int play(){
	

	system("CLS");
	//generating random answer (FINISHED)
	srand (time(NULL));
	numcategory = rand()%2+1;
	
	switch(numcategory)	{
		case 1:
			numword = rand()%33;
			category = "Countries";
			answer = country[numword];
			break;
		case 2:
			numword = rand()%11;
			category = "Sports";
			answer = sports[numword];
			break;
		default:
			cout << "Wrong category!!\n\n\n";
			getchar();	}

	while (life != 0){	
		if (spreecount>=5)
			spree = true; 
		else 
			spree = false;
		system("CLS");
		cout <<"\n\n\n"<<setw(15)<<"Player: "<<playername<<endl;
		cout <<"\n"<<setw(15)<<"Stage: "<<stage<<setw(50)<<"Score: "<<scoresum<<endl;
		cout <<"\n"<<setw(15)<<"Life: "<<life<<setw(50)<<"Spree: ";
		if (spree)
			cout << "Yes";
		else 
			cout << "No";
		cout <<"\n"<<"   =====================================================================\n";
		cout <<"\n"<<setw(15)<<"Category: "<<category;
		//Swaping the answer and display swapped word
		swap(answer);		

		cout <<"\n"<<"   =====================================================================\n\n";
		cout << "   Your Answer:   ";
		getline(cin, inputans);
		transform(inputans.begin(), inputans.end(),inputans.begin(), ::toupper);	
		
		if (inputans == answer){

			if (stage<=5)
				score = 10;
			else if(stage>=6&&stage<=10)
				score = 50;
			else if(stage>=11&&stage<=20)
				score = 100;
			else 
				score = 250;
			stage +=1;			
			if (spree)
				score = score*2;
			scoresum = scoresum + score;
			spreecount +=1;
			life = 5;
			play();
		}
		else {
			life -= 1;
			spreecount = 0;
		}
	}
}


int game(){
	

	
	cout << "\n\n\n\n\n     Hi! "<<playername<<".\n\n     Are You Ready? \n\n     Press <Enter> key to start!\n\n\n\n";
	system("pause");
	system("CLS");
	
	//initate game
	life = 6;
	stage = 1;
	scoresum = 0;
	spree = false;
	
	//Start game
	play();
	gameover();	

	
}



void EnterPlayerName(){
	
	cout<<"\n\n\n\n     Hi, Player. \n\n     Welcome to <gamename> ! \n\n   ========================================\n\n     What's your name: ";
	cin >> playername;
	system("CLS");
	
}

void Start(){
	int option;
	cout <<"\n\n\n     Hi, " << playername <<".\n    ==========================================================\n\n";
	cout <<"     1. Start Game\n"<<endl;
	cout <<"     2. Scoreboard\n"<<endl;
	cout <<"     3. How to play\n"<<endl;
	cout <<"     4. <To be implemented>\n"<<endl;
	cout <<"\n     9. Exit.\n";
	cout <<" \n    ==========================================================\n\n    Please enter your choice: " ;
	cin >> option;
	
	system("CLS");
	switch (option){
		case 9:
			cout <<"\n\n\n     Hi, " << playername <<".\n    ==========================================================\n\n";
			cout <<"     1. Start Game\n"<<endl;
			cout <<"     2. Scoreboard\n"<<endl;
			cout <<"     3. How to play\n"<<endl;
			cout <<"     4. <To be implemented>\n"<<endl;
			cout <<"\n     9. Exit.\n";
			cout <<" \n    ==========================================================\n\n    See you!";
			exit(0);
			break;
		case 1:
			system("CLS"); 
			game();
			break;
		case 2:
			system("CLS");
			cout << "To be implemented.";
			break;
		case 3:
			system("CLS");
			cout << "To be implemented.";
			break;
		case 4:
			system ("CLS");
			cout << "To be implemented.";
			break;
		default:
			system ("CLS");
			cout << " \n\n  Unknown command. Please select again...";
			Start();

}
}

int main(){
	EnterPlayerName();
	Start();
	while (back == 1){
		system("CLS");
		Start();
	}
	if (back == 2)
		system("CLS");
		cout << "\n\n\n\n\n\n\n                         Thanks for playing!"<<"\n\n                               Goodbye!";
		exit(0);

}
