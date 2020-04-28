#include <iostream>
#include <string>
#include <string.h>
#include <cstring> 
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <fstream>

using namespace std;
int stage, score, scoresum, numword, numcategory, spreecount, life, back;
static int ct=0;
bool spree;
string answer, inputans, category;
char country[100][100] ={"CHINA", "THE UNITED STATES","JAPAN","TAIWAN","HONG KONG","AUSTRALIA","BELGIUM","BRAZIL","BULGARIA","CANADA","COLOMBIA","CUBA","DENMARK","EGYPT","FINLAND","FRANCE","GERMANY","ICELAND","ISRAEL","ITALY","KOREA","MALAYSIA","MEXICO","MOROCCO","NEW ZEALAND","NORWAY","RUSSIA","REPUBLIC OF THE CONGO","SWITZERLAND","THAILAND","TURKEY","UNITED KINGDOM","VIETNAM"};
char sports[100][100] ={"BASKETBALL", "FOOTBALL", "SOCCER","LACROSSE","HOCKEY","TENNIS","VOLLEYBALL","TABLE TENNIS","BASEBALL","RUGBY","GOLF"};
char scoreboard[100][100]={};
string playername;

int gameover(){
	
	int option;
	
	ofstream fout("PlayerRecord.txt", ios::app);
	if (fout.fail()){
		cout << "Cannot open scoreboard.txt! Exit game......";
		exit(1);
	}
	fout << playername << " " << scoresum << endl;
	fout.close();
	
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

char ChangePlayerName(){
	cout << "\n     Please enter your new player name: ";
	cin >> playername;
	cout <<"\n    Finised! Press <Enter> to back to menu......\n\n\n\n";
	system("pause");
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

int WordFever(){
	

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
			WordFever();
		}
		else {
			life -= 1;
			spreecount = 0;
		}
	}
}

void hang(char s[][100],int x){
char al[26];
char a='A';
int i;
for(i=0;i<26;i++,a++)
al[i]=a;
int j;
int ct1;
char alpha;
char s1[100];

for(i=0;i<strlen(s[x]);i++)
 { 
	if(isalnum(s[x][i]))
    s1[i]='_';
   else
    s1[i]=' ';

   cout<<s1[i]<<' ';
 }

for(;ct<9;)
{ 

  cout<<"\n\n No. of turns remaining: "<<9-ct<<' ';
  cout<<"\n Enter letter: ";
  cin>>alpha;
  alpha=toupper(alpha);
  ct1=0;
  for(j=0;j<strlen(s[x]);j++)
   { 
       if(s[x][j]==alpha)
       { s1[j]=alpha;
	 ct1++;
    }
   }
   s1[j]='\0';
   if(ct1==0)
   ct++; 


  for(j=0;j<strlen(s1);j++)      //couting the word to see what happened
  cout<<s1[j]<<' ';
  ct1=0;
  for(j=0;j<strlen(s1);j++)      //to check how many letters they found
  if(s1[j]!='_')
  ct1++;
  if(ct1==strlen(s1))
  break;
  cout<<endl;
  for(i=0;i<26;i++)
  if(al[i]==alpha)
   al[i]='/';
  for(i=0,j=65;i<26;i++,j++)
  if(al[i]=='/')
  {
   char s[2];
   s[0]=(char)j;
   s[1]='\0';
   cout<<s;
   cout<<' ';
  }
  else
  {char s[2];
   s[0]=al[i];
   s[1]='\0';
   cout<<s;
   cout<<' ';
  }
   cout<<endl;
  switch(ct)
   {
    case 1:cout<<"  O"<<endl;   
		  break;
		  
    case 2:cout<<"  O"<<endl;
	   cout<<"  |"<<endl;
	   cout<<"  |"<<endl;
		  break;
		  
    case 3:cout<<"  O"<<endl;
	   cout<<" \\|"<<endl;
	   cout<<"  |"<<endl;
		  break;
		  
    case 4:cout<<"  O"<<endl;
	   cout<<" \\|/"<<endl;
	   cout<<"  |"<<endl; 
		  break;
		  
    case 5:cout<<"  O"<<endl;
	   cout<<" \\|/"<<endl;
	   cout<<"  |"<<endl;
	   cout<<" /"<<endl;
		  break;
		  
    case 6:cout<<"  O"<<endl;
	   cout<<" \\|/"<<endl;
	   cout<<"  | "<<endl;
	   cout<<" / \\"<<endl;
		  break;
		  
    case 7:cout<<"  ! "<<endl
	       <<"  O"<<endl
	       <<" \\|/"<<endl
	       <<"  | "<<endl
	       <<" / \\"<<endl;
		  break;
		  
    case 8:cout<<"  ___ "<<endl
	       <<"  ! "<<endl
	       <<"  O"<<endl
	       <<" \\|/"<<endl
	       <<"  | "<<endl
	       <<" / \\"<<endl;
		  break;
		  
    case 9:cout<<"  ___ "<<endl
	       <<"  !    |"<<endl
	       <<"  O    |"<<endl
	       <<" \\|/   |"<<endl
	       <<"  |    |"<<endl
	       <<" / \\   |"<<endl
	       <<"      ###"<<endl;
		  break;

  }
}

if(ct!=9)
{
 cout<<endl;
 cout<<"You win";
}
else
{ 
  cout<<endl;
  cout<<"You lose";
  cout<<endl;
  cout<<"The movie is "<<s[x];
  cout <<"\n\n1. Back to menu        2.Exit\n";
  cout <<"\n: ";
  cin >> back;
}
}

int HMSetUp(){
    int x,op;
char e[100][100]={"AVENGERS","MISSION IMPOSSIBLE","HARRY POTTER","DARK KNIGHT","INCEPTION","CONJURING","THE MATRIX","TERMINATOR","TRANSOFRMERS","DIE HARD","SKYFALL","CASINO ROYALE","EXORCIST","SPEED","BLACK PANTHER","FAST AND FURIOUS","JOHN WICK","INSIDIOUS"};
char t[100][100]={"COCO","INSIDE OUT","MOANA","TOY STORY","INCREDIBLES","ZOOTOPIA","FROZEN","FINDING DORY","BIG HERO","RATATOUILE","DESPICABLE ME"};
char h[100][100]={"JUNGLE BOOK","THE HOBBIT","PIRATES OF THE CARIBBEAN","FINDING NEMO","JUMANJI","AVATAR","SHAWSHANK REDEMPTION","FORREST GUMP","THE GODFATHER","THE TERMINAL","MILLIONS","SLUMDOG MILLIONARE","TITANIC","GANDHI","PURSUIT OF HAPPYNESS","SUPERBAD"};

cout<<"\t\t     HANGMAN"<<endl
    <<" 1. English Action/ Horror"<<endl
    <<" 2. Animated Movies"<<endl
    <<" 3. Big Hits(ALL CATEGORIES)"<<endl
    <<" Choose Genre: ";
	
cin>>op;
system("CLS");
	
switch(op)
{
    case 1:
    { 
	x=rand()%18;
	  hang(e,x);
	}
	break;
 case 2:    
    {
	x=rand()%11;
	hang(t,x);
    }
	break;
 case 3:
    {
	x=rand()%16;
	hang(h,x); 
    }
	break;
}
ct=0;
}

int WFSetUp(){
	

	cout <<"\n\n\n\n\n\n    ========================================================   ";
	cout << "\n\n\n     Hi! "<<playername<<".\n\n     Are You Ready? \n\n     Press <Enter> key to start!\n\n\n\n";
	cout <<"\n\n    ========================================================   \n\n\n\n";
	system("pause");
	system("CLS");
	
	//initate game
	life = 6;
	stage = 1;
	scoresum = 0;
	spree = false;
	
	//Start game
	WordFever();
	gameover();	

	
}

void EnterPlayerName(){
	

	cout<<"\n\n\n\n\n\n\n          Hi, Player! \n\n          Please enter your name:  ";
	cin >> playername;
	system("CLS");
	
}

int Op1(){
	int option;
	cout << "\n\n\n\n\n\n\n   ---------------  Game Mode  ---------------  \n\n\n          1.  WordFever!\n\n          2.  HANGMAN\n\n\n";
	cout << "  ==================================================\n\n";
	cout << "   Select game mode: ";
	cin >> option;
	switch (option){
		case 1:
			system("CLS");
			WFSetUp();
			break;
		case 2:
			system("CLS");
			HMSetUp();
			break;
		default:
			system("CLS");
			cout << "Unknown command. Exiting game...";
			exit(1);
	}
}

int GameRule(){
	
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
	system("pause");
	
	back = 1;
	
}

int ScoreBoard(){
	
	string namelist[100] = {};
	int scorelist[100] = {};
	string name, tempname;
	int i = 0;
	int score, tempscore;

	system("CLS");
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
	for (int i=0;i<recordnum;i++){
		cout << setw(10)<< namelist[i]<<" "<<setw(20)<<scorelist[i] <<"\n\n";
	}	
	cout << "    =======================================\n";
	cout <<"    Press <Enter> to back to menu......\n\n";
	back = 1;
	system("pause");
	

}

void Menu(){
	int option;
	cout <<"\n\n\n     Hi, " << playername <<".\n    ==========================================================\n\n";
	cout <<"     1. Start Game\n"<<endl;
	cout <<"     2. Scoreboard\n"<<endl;
	cout <<"     3. How to play\n"<<endl;
	cout <<"     4. Setting\n"<<endl;
	cout <<"\n     9. Exit.\n";
	cout <<" \n    ==========================================================\n\n    Please enter your choice: " ;
	cin >> option;
	
	system("CLS");
	switch (option){
		case 9:
			back = 2;
			break;
		case 1:
			system("CLS"); 
			Op1();
			break;
		case 2:
			system("CLS");
			ScoreBoard();
			break;
		case 3:
			system("CLS");
			GameRule();
			break;
		case 4:
			int settingOption;
			system ("CLS");
			cout << "\n\n\n   =========================================\n";
			cout << "   |                                       |\n";
			cout << "   |  Setting:                             |\n";
			cout << "   =========================================\n";
			cout << "   |                                       |\n";			
			cout << "   |  1. Change player name                |\n";
			cout << "   |                                       |\n";
			cout << "   |  2. Clear scoreboard                  |\n";
			cout << "   |                                       |\n";
			cout << "   |  0. Back to menu                      |\n";	
			cout << "   |                                       |\n";	
			cout << "   =========================================\n";
			cout << "\n   : ";
			cin >> settingOption;
			back = 1;
			
			switch (settingOption){
				case 1:
					ChangePlayerName();
					break;
				case 2:
					remove("PlayerRecord.txt");
					cout <<"\n    Finised! Press <Enter> to back to menu......\n\n\n\n";
					system("pause");
					break;
				case 0:
					break;
			}
}
}

int Begining(){
	cout <<"\n\n\n\n"<<"      ------------  ENGG1340 Course Project  ------------ \n\n\n\n\n         Developed by:\n";
	cout <<"\n            CHOI CHIN KIU      (3035557351)\n\n            DEV CHORADIA MANOJ (3035666669)\n\n\n\n\n\n         Press <ENTER> key to continue...... \n\n\n\n";
	system("pause");
	system("CLS");
}

int main(){
	Begining();
	EnterPlayerName();
	Menu();
	while (back == 1){
		system("CLS");
		Menu();
	}
	if (back == 2)
		system("CLS");
		cout << "\n\n\n\n\n\n\n                         Thanks for playing!"<<"\n\n                               Goodbye!\n\n";
		exit(0);

}
