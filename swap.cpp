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
