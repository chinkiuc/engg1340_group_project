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
