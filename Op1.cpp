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
