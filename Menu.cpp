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
