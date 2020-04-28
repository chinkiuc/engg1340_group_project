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
