#include <iostream>
#include <string>

using namespace std;
string playername;

void EnterPlayerName(){
	
	cout<<"\n\n\n\n  Hi, Player. \n  Welcome to <gamename> ! \n\n _______________________________\n\n  What's your name: ";
	cin >> playername;
	system("CLS");
	
}

void Start(){

	int option;

	cout <<"\n\n\n  Hi, " << playername <<".\n ________________________________\n\n";
	cout <<"  1. Start Game"<<endl;
	cout <<"  2. Scoreboard"<<endl;
	cout <<"  3. How to play"<<endl;
	cout <<"  4. <To be implemented>"<<endl;
	cout <<"\n  9. Exit.";
	cout <<" \n ________________________________\n\n Please enter your choice: " ;
	cin >> option;

	system("CLS");
	cout <<"\n\n\n  Hi, " << playername <<".\n ________________________________\n\n";
	cout <<"  1. Start Game"<<endl;
	cout <<"  2. Scoreboard"<<endl;
	cout <<"  3. How to play"<<endl;
	cout <<"  4. <To be implemented>"<<endl;
	cout <<"\n  9. Exit.";	
	
	
	switch (option){
		
		case 9:
			cout << " \n ________________________________\n\n  See you!";
			exit(0);
			break;
		case 1:
			system("CLS"); 
			cout << "To be implemented.";
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
}
