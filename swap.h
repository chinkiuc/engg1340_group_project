//Accecpting answer string, 
//Then use rand() + for loop to swap the letters in random order
//Using rand() + for loop to prevent duplication from rand() function
//Print the swapped letters in game with spacing & formatting

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include <string.h>
#include <iomanip>
using namespace std;
char swap(string answer)
{
	const int n = answer.size()+1;
	char *word = new char[100];
	strcpy(word, answer.c_str());
	char TEMP;
	int wordnum = strlen(word)-1;
	srand(time(NULL));	
	//Swapping the answer (FINSHED)
	for (int i=0;i<=wordnum;i++){
		int j=rand()%wordnum;
		TEMP = word[i];
		word[i] = word[j];
		word[j] = TEMP;	}
	cout <<"\n\n\n\n";
	cout << setw(25);
	//Printing out the swapped word (FINISHED)
	for (int i=0; i<=wordnum;i++){
	if (word[i]==' ')
			cout << "*  ";
		else 
			cout << word[i] << "  ";}
	cout <<"\n\n";
	delete[] word;
	return 0;
}

