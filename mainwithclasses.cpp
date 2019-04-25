#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <string>
//#include <sstream>


using namespace std;

class GameEngine{
	
	
	void generatecode() {
		srand(time(NULL));
	for (int i=0; i<positions;i++) {
		mastercode[i] = rand() % colors + 1;
		mastercolors1[mastercode[i]]++;
		mastercolors2[mastercode[i]]++;
	}
	}
	
	void generatehint(int[] guess) {
		int hk=0;
		for (int k=0;k<positions;k++) {
			
			if (guess[usedslots][k]==mastercode[k]) {
				hints[usedslots][hk]=2;
				mastercolors2[mastercode[k]]--;
				hk++;
			} else if (mastercolors2[guess[usedslots][k]]>0) {
				hints[usedslots][hk]=1;
				mastercolors2[guess[usedslots][k]]--;
				hk++;
			}
			
			
		}
		
	}
	
	bool checkguess() {
		int corrsum=0;
		for (int i=0;i<positions;i++) {
			corrsum += hints[usedslots][i];
		}
		if (corrsum==8) {
			correct = true;
		}
	}
	
	
	void resetboard() {
		cout << "Gameboard has been reset" << endl;
	}
};


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
	
	int mastercolors1[colors];
	int mastercolors2[colors];
	for (int j=0; j<colors; j++) {
		 mastercolors1[j] = 0;
		 mastercolors2[j] = 0;
	}
	
	cout << "I am the codemaker, I will now generate the MASTERCODE" << endl;
	srand(time(NULL));
	for (int i=0; i<positions;i++) {
		mastercode[i] = rand() % colors + 1;
		mastercolors1[mastercode[i]]++;
		mastercolors2[mastercode[i]]++;
		cout << mastercode[i];
	}
	cout << endl;
	
	
	//Initialize for guesses
	int guess[slots][positions];
	int hints[slots][positions];
	for (int i=0; i<slots; i++) {
		for (int j=0; j<positions; j++) {
			guess[i][j]=0;
			hints[i][j]=0;
		}
	}
	int usedslots=0;
	
	bool correct=false;
	while (usedslots!=slots) {
		
		if (usedslots!=0) {
			//cout << "Do you wish to see all previous guesses?" << endl;
			
			cout << "The new hint is: " << endl;
			cout << hints[usedslots-1][0] << hints[usedslots-1][1] << endl;
			cout << hints[usedslots-1][2] << hints[usedslots-1][3] << endl;
		}
		
		
		cout << "Please guess!" << endl;
		cout << "Enter pin 1:" << endl;
		cin >> guess[usedslots][0];
		cout << "Enter pin 2:" << endl;
		cin >> guess[usedslots][1];
		cout << "Enter pin 3:" << endl;
		cin >> guess[usedslots][2];
		cout << "Enter pin 4:" << endl;
		cin >> guess[usedslots][3];
		
		int hk=0;
		for (int k=0;k<positions;k++) {
			
			if (guess[usedslots][k]==mastercode[k]) {
				hints[usedslots][hk]=2;
				mastercolors2[mastercode[k]]--;
				hk++;
			} else if (mastercolors2[guess[usedslots][k]]>0) {
				hints[usedslots][hk]=1;
				mastercolors2[guess[usedslots][k]]--;
				hk++;
			}
			
			
		}
		
		int corrsum=0;
		for (int i=0;i<positions;i++) {
			corrsum += hints[usedslots][i];
		}
		if (corrsum==8) {
			correct = true;
		}
		
		if (correct) {
			cout << "You broke the mastercode!" << endl;
			break;
		}
		
		usedslots++;
		
		//reset mastercolor array
		for (int j=0; j<colors; j++) {
		 mastercolors2[j] = mastercolors1[j];
		}
	}
	
	
	
	
	
	
	
	int exit=0;
	while (exit!=1) {
		cout << "EXIT? (1,0) : ";
		cin >> exit;
	}
	
	
	return 0;




}








