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
