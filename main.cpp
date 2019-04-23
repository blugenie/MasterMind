#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <string>
//#include <sstream>


using namespace std;

int main() {

	cout << "Hello World" << endl;
	cout << "Welcome to MasterMind" << endl;
	
	cout << "Initiate decoding board" << endl;
	
	int slots;
	cout << "Enter Number of slots = ";
	cin >> slots;
	
	int colors;
	cout << "Enter Number of colors = ";
	cin >> colors;
	
	int N=1;
	
	while (N % 2 != 0) {
		cout << "Enter Number of games = ";
		cin >> N;
		if (N%2==1)	{
			cout << "Number of games must be even!" << endl;
		}
	}
	
	int positions = 4;
	int mastercode[positions]={0,0,0,0};
	// 0 represents empty
	// 1-colors represents colors
	
	cout << "I am the codemaker, I will now generate the MASTERCODE" << endl;
	srand(time(NULL));
	for (int i=0; i<positions;i++) {
		mastercode[i] = rand() % colors + 1;
		cout << mastercode[i];
	}
	cout << endl;
	
	
	//Initialize for guesses
	int guess[slots][positions];
	int hints[slots][positions];
	int usedslots=0;
	
	while (usedslots!=slots) {
		
		if (usedslots!=0) {
			cout << "Do you wish to see all previous guesses?" << endl;
		}
		
		
		cout << "Please guess!" << endl;
		cin >> guess[usedslots][0]
		cin >> guess[usedslots][1]
		cin >> guess[usedslots][2]
		cin >> guess[usedslots][3]
		
		
		
		
		usedslots++;
	}
	
	
	
	
	
	
	
	int exit=0;
	while (exit!=1) {
		cout << "EXIT? (1,0) : ";
		cin >> exit;
	}
	
	
	return 0;




}








