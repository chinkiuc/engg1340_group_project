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
