#include<iostream>
#include<cctype>
#include<cstring>
#include<cstdlib>
using namespace std;
static int ct=0;
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
 { if(isalnum(s[x][i]))
    s1[i]='_';
   else
    s1[i]=' ';

   cout<<s1[i]<<' ';
 }

for(;ct<9;)
{ cout<<"\n\n No. of turns remaining: "<<9-ct<<' ';
  cout<<"\n Enter letter: ";
  cin>>alpha;
  alpha=toupper(alpha);
  ct1=0;
  for(j=0;j<strlen(s[x]);j++)
   { if(s[x][j]==alpha)
       { s1[j]=alpha;
	 ct1++;
       }
   }s1[j]='\0';
  if(ct1==0)
  {ct++;}


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
  {char s[2];
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
    case 1:cout<<"  O"<<endl;     break;
    case 2:cout<<"  O"<<endl;
	   cout<<"  |"<<endl;
	   cout<<"  |"<<endl;break;
    case 3:cout<<"  O"<<endl;
	   cout<<" \\|"<<endl;
	   cout<<"  |"<<endl;break;
    case 4:cout<<"  O"<<endl;
	   cout<<" \\|/"<<endl;
	   cout<<"  |"<<endl;  break;
    case 5:cout<<"  O"<<endl;
	   cout<<" \\|/"<<endl;
	   cout<<"  |"<<endl;
	   cout<<" /"<<endl;break;
    case 6:cout<<"  O"<<endl;
	   cout<<" \\|/"<<endl;
	   cout<<"  | "<<endl;
	   cout<<" / \\"<<endl;break;
    case 7:cout<<"  ! "<<endl
	       <<"  O"<<endl
	       <<" \\|/"<<endl
	       <<"  | "<<endl
	       <<" / \\"<<endl;break;
    case 8:cout<<"  ___ "<<endl
	       <<"  ! "<<endl
	       <<"  O"<<endl
	       <<" \\|/"<<endl
	       <<"  | "<<endl
	       <<" / \\"<<endl;break;
    case 9:cout<<"  ___ "<<endl
	       <<"  !    |"<<endl
	       <<"  O    |"<<endl
	       <<" \\|/   |"<<endl
	       <<"  |    |"<<endl
	       <<" / \\   |"<<endl
	       <<"      ###"<<endl;break;

  }
   }

//cout<<endl<<"ct is :"
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
}
}
int main()
{
    int x,op;
char e[100][100]={"AVENGERS","MISSION IMPOSSIBLE","HARRY POTTER","DARK KNIGHT","INCEPTION","CONJURING","THE MATRIX","TERMINATOR","TRANSOFRMERS","DIE HARD","SKYFALL","CASINO ROYALE","EXORCIST","SPEED","BLACK PANTHER","FAST AND FURIOUS","JOHN WICK","INSIDIOUS"};
char t[100][100]={"COCO","INSIDE OUT","MOANA","TOY STORY","INCREDIBLES","ZOOTOPIA","FROZEN","FINDING DORY","BIG HERO","RATATOUILE","DESPICABLE ME"};
char h[100][100]={"JUNGLE BOOK","THE HOBBIT","PIRATES OF THE CARIBBEAN","FINDING NEMO","JUMANJI","AVATAR","SHAWSHANK REDEMPTION","FORREST GUMP","THE GODFATHER","THE TERMINAL","MILLIONS","SLUMDOG MILLIONARE","TITANIC","GANDHI","PURSUIT OF HAPPYNESS","SUPERBAD"};

cout<<"\t\t     HANGMAN"<<endl
    <<" 1. English Action/ Horror"<<endl
    <<" 2. Animated Movies"<<endl
    <<" 3. Big Hits(ALL CATEGORIES)"<<endl
    <<" Choose language: ";
cin>>op;
switch(op)
{case 1:{ x=rand()%18;
	  hang(e,x);
	  }
	break;
 case 2:{ x=rand()%11;
	hang(t,x); }
	break;
 case 3:{ x=rand()%16;
	hang(h,x); }
	break;
}
ct=0;
return 0;
}