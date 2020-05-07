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
#include <stdlib.h>
#include <ctime> 

#include "Begining.cpp"
#include "swap.cpp"
#include "GameRule.cpp"
#include "ScoreBoard.cpp"
#include "gameover.cpp"
#include "ChangePlayerName.cpp"
#include "EnterPlayerName.cpp"
#include "grid.cpp"

#ifdef _WIN64
	#define CLEAR system("cls")
#elif _WIN32
	#define CLEAR system("cls")
#else 
	#define CLEAR system("clear")
#endif

#define PAUSE cin.get();cin.get();

using namespace std;
int stage, score, scoresum, numword, numcategory, spreecount, life, back;
static int ct=0;
bool spree;
string answer, inputans, category;
//word bank of game1, WordFever!
char country[100][100] ={"CHINA", "THE UNITED STATES","JAPAN","TAIWAN","HONG KONG","AUSTRALIA","BELGIUM","BRAZIL","BULGARIA","CANADA","COLOMBIA","CUBA","DENMARK","EGYPT","FINLAND","FRANCE","GERMANY","ICELAND","ISRAEL","ITALY","KOREA","MALAYSIA","MEXICO","MOROCCO","NEW ZEALAND","NORWAY","RUSSIA","REPUBLIC OF THE CONGO","SWITZERLAND","THAILAND","TURKEY","UNITED KINGDOM","VIETNAM"};
char sports[100][100] ={"BASKETBALL", "FOOTBALL", "SOCCER","LACROSSE","HOCKEY","TENNIS","VOLLEYBALL","TABLE TENNIS","BASEBALL","RUGBY","GOLF"};
//array to store playername and score after game1
char scoreboard[100][100]={};
string playername;
int A[8][3] = { {1, 2, 3}, {1, 5, 9}, {1, 4, 7}, {2, 5, 8}, {3, 6, 9}, {4, 5, 6}, {7, 8, 9}, {3, 5, 7} };
int displayedX[9] = {0},displayed[9] = {0},displayedO[9] = {0};
int x_count,o_count,total,computer, is_double = 0,double_loop;
char B[9] = {'1','2','3','4','5','6','7','8','9'},ch1='X',ch2='O';

void grid();
void choose();
int win();
void check_input();
void hard();
void easy();
int check_comp_pick();
void Double();

int tictactoe()
{
    srand((unsigned) time(0));
 cout<<"\nTIC TAC TOE\n...........\n\n";
 cout<<"1) Single Player\n2) Double Player\n\n";
 int ans;
 int w;
 do
 {
  cout<<"Enter option: ";
  cin>>ans;
  w=0;
  if(ans<1 || ans >2)
  {
   cout<<"Error.\n";
   w=1;
  }
 }while(w);
 if(ans==1)
 {
  cout<<"\n1) Easy\n2) Hard\n\n";
  do
  {
   cout<<"Enter option: ";
   cin>>ans;
   w=0;
   if(ans<1 || ans >2)
   {
    cout<<"Error.\n";
    w=1;
   }
  }while(w);
  if(ans==1){
   easy();
   }
  else
   hard();
 }
 else
  Double();

  cout << "\n\nPress <Enter> to exit game...\n";
  PAUSE;
  CLEAR;
    return 0;
}

void grid();

void choose()
{
    int flag = 0;
    if (total < 2)
    {
        computer = rand()%9 + 1;
        goto picked;
    }    
    else
    {
        for ( int i = 0; i < o_count - 1; i++)
        {
            int one = displayedO[i];
            int two = displayedO[i+1];
            for (int j = 0; j < 8; j++)
            {
                int sum = 3, count = 0;
                for (int k = 0; k < 3; k++)
                {
                    if ( one == A[j][k] || two == A[j][k])
                    {
                        sum -= k;
                        count++;
                    }
                }
                if (count == 2)
                {
                    computer = A[j][sum];
                    if (check_comp_pick())
                        goto done;
                }
            }
            goto picked;
        }
        
        check_x:
        cout<<"Checked X\n";
        for ( int i = 0; i < x_count - 1; i++)
        {
            int one = displayedX[i];
            int two = displayedX[i+1];
            for (int j = 0; j < 8; j++)
            {
                int sum = 3, count = 0;
                for (int k = 0; k < 3; k++)
                {
                    if ( one == A[j][k] || two == A[j][k])
                    {
                        sum -= k;
                        count++;
                    }
                }
                if (count == 2)
                {
                    computer = A[j][sum];
                    if (check_comp_pick())
                        goto done;
                }
            }
        }
    }
    
    picked:
    if (!flag)
    {
        flag = 1;
        goto check_x;
    }
    for (int i = 0; i< total; i++)
    {
        if ( computer == displayed[i])
        {
            computer = rand() %9 + 1;
            goto picked;
        }
    }
    
    done:
    displayedO[o_count++] = displayed[total++] = computer;
    B[computer-1] = 'O';
}

int win()
{
 if((B[0]==B[1] && B[1]==B[2])||(B[0]==B[4] && B[4]==B[8]) ||(B[0]==B[3] && B[3]==B[6]) ||(B[1]==B[4] && B[4]==B[7]) ||(B[2]==B[5] && B[5]==B[8]) ||(B[4]==B[3] && B[3]==B[5]) ||(B[6]==B[7] && B[8]==B[6]) || (B[2]==B[4] && B[6]==B[4]))
  return 1;
 else
  return 0;
}

void check_input()
{
     int op = 0,n;
     do
     {
          op=0;
          cout<<"\nEnter place: ";
          cin>>n;
          if(n<1 || n>9)
          {
               cout<<"Error.\n";
               op=1;
          }
          for(int v=0;v<total;v++)
               if(n==displayed[v])
               {
                    cout<<"Error.\n";
                    op=1;
               }
     }while(op);
     if ( is_double)
     {
         char ch;
          if(double_loop%2==0)
          {
              displayedX[x_count++] = displayed[total++] = n; 
              B[n-1] = 'X';
              return;
          }
          else
          {
              displayedO[o_count++] = displayed[total++] = n;
              B[n-1] = 'O';
              return;
          }
     }
    displayedX[x_count++] = displayed[total++] = n; 
    B[n-1] = 'X';
}

void hard()
{
     cout << "\033[2J\033[1;1H";
     cout<<"\nHard Level\n..........\n";
     grid();
     int i;
     for(i=0;i<9;i++)
     {
          if(win())
          {
               cout<<"\nComputer Wins!!";
               return;
          }
          check_input();
          CLEAR;
          cout<<"\nHard Level\n..........\n\n";
          grid();
          i++;
          if(win())
          {
               cout<<"\nPlayer Wins!!";
               return;
          }
          if (i>=9)
          {
              cout<<"\n\nDraw!";
              return;
          }
          choose();
          CLEAR;
          cout<<"\nHard Level\n..........\n";
          grid();
     }
      cout<<"\n\nDraw!";
}

void easy()
{
     CLEAR;
     cout<<"\nEasy Level\n..........\n";
     grid();
     for(int i=0;i<9;i++)
     {
          check_input();
          CLEAR;
          cout<<"\nEasy Level\n..........\n";
          grid();
          if(win())
          {
               cout<<"\nPlayer Wins!!";
               return;
          }
          mychance:
          computer= rand()%9+1;
          int o;
          for( o=0;o<total;o++)
               if(computer==displayed[o])
                    break;
          if(o<total)
                goto mychance;
          i++;
	     
          displayedO[o_count++] = displayed[total++] = computer;
            B[computer-1] = 'O';
          if (i>=9)
          {
              cout<<"\n\nDraw!";
              return;
          }
          CLEAR;
          cout<<"\nEasy Level\n..........\n";
          grid();
          if(win())
          {
               cout<<"\nComputer Wins!!";
               return;
          }
     }
}

int check_comp_pick()
{
    for (int i = 0; i< total; i++)
    {
        if ( computer == displayed[i])
        {
            return 0;
        }
    }  
    return 1;
}
void Double()
{
     CLEAR;
     is_double = 1;
     cout<<"\nDouble Player\n..............\n";
     grid();
     cout<<"\nPlayer 1:- X \nPlayer 2:- O\n";
     for(double_loop=0;double_loop<9;double_loop++)
     {
          cout<<"\nPlayer "<<double_loop%2+1<<" :\n";
          check_input();
          CLEAR;
          cout<<"\nDouble Player\n.............\n";
          grid();
          if(win())
          {
               cout<<"\nPlayer "<<double_loop%2+1<<" Wins!!";
               return;
          }
     }
     cout << "\nDraw!";
     return;
 }
int gameover();
char ChangePlayerName();
char swap(string answer);
//Game1 (WordFever!)'s main code
//using rand() to generate random answer
//calculating score
int WordFever()
{
	CLEAR;
	//generating random answer
	srand (time(NULL));
	numcategory = rand()%2+1;
	switch(numcategory)	
	{
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
			getchar();	
	}
	//game continue until the player's life reached 0
	while (life != 0)
	{	
		if (spreecount>=5)
			spree = true; 
		else 
			spree = false;
		CLEAR;
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
		
		if (inputans == answer)
		{
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
// hangman code
void hang(char s[][100],int x)
{
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
// hangman main set up
int HMSetUp()
{
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
CLEAR;
	
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
// wordfever main set up
int WFSetUp()
{
	

	cout <<"\n\n\n\n\n\n    ========================================================   ";
	cout << "\n\n\n     Hi! "<<playername<<".\n\n     Are You Ready? \n\n     Press <Enter> key to start!\n\n\n\n";
	cout <<"\n\n    ========================================================   \n\n\n\n";
	PAUSE;
	CLEAR;
	
	//initate game
	life = 5;
	stage = 1;
	scoresum = 0;
	spree = false;
	
	//Start game
	WordFever();
	gameover();	

	
}
void EnterPlayerName();
//Option 1 from menu
//choosing game1/2/3
int Op1()
{
	int option;
	cout << "\n\n\n\n\n\n\n   ---------------  Game Mode  ---------------  \n\n\n          1.  WordFever!\n\n          2.  HANGMAN\n\n          3. TicTacToe(Single and double player)\n\n\n";
	cout << "  ==================================================\n\n";
	cout << "   Select game mode: ";
	cin >> option;
	switch (option){
		case 1:
			CLEAR;
			WFSetUp();
			break;
		case 2:
			CLEAR;
			HMSetUp();
			break;
		case 3:
			CLEAR;
			tictactoe();
			break;
		default:
			CLEAR;
			cout << "Unknown command. Exiting game...";
			exit(1);
	}
}
int GameRule();
int ScoreBoard();
//main Menu
void Menu()
{
	int option;
	cout <<"\n\n\n     Hi, " << playername <<".\n    ==========================================================\n\n";
	cout <<"     1. Start Game\n"<<endl;
	cout <<"     2. WordFever! Scoreboard\n"<<endl;
	cout <<"     3. How to play\n"<<endl;
	cout <<"     4. Setting\n"<<endl;
	cout <<"\n     9. Exit.\n";
	cout <<" \n    ==========================================================\n\n    Please enter your choice: " ;
	cin >> option;
	
	CLEAR;
	switch (option)
	{
		case 9:
			back = 2;
			break;
		case 1:
			CLEAR;
			Op1();
			break;
		case 2:
			CLEAR;
			ScoreBoard();
			break;
		case 3:
			CLEAR;
			GameRule();
			break;
		case 4:
			int settingOption;
			CLEAR;
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
					PAUSE;
					break;
				case 0:
					break;
			}
}
}
int Begining();
// main function
int main(){
	Begining();
	EnterPlayerName();
	Menu();
	while (back == 1){
		CLEAR;
		Menu();
	}
	if (back == 2)
		CLEAR;
		cout << "\n\n\n\n\n\n\n                         Thanks for playing!"<<"\n\n                           Goodbye!\n\n";
		exit(0);

}

