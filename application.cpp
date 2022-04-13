// -----------------------------------------------------------------------

// Project 3 - Animated Bar Chart, application.cpp
//
// This application uses BarChartAnimate (which uses BarChart, which uses Bar)
// to produce an animated bar chart.
// application.cpp is the user interface.
//
// Author: Zaid Awaidah
// Date: 2 / 10 / 2022
// Class: CS 251, Spring 2022, UIC

// -----------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <map>
#include "barchartanimate.h"
using namespace std;

// -----------------------------------------------------------------------

void displayFileOptions(int& userChoice);
void chooseFile(int& userChoice, string& fileChoice);
void performAnimation(string& fileName);

// -----------------------------------------------------------------------

int main() {
	int userChoice;
	string fileChoice = "";
	cout << "Welcome to Bar Chart Animations.\nThis application will produce"
		<< " an animation for the file you choose,\nand display it in a bar chart format!\n\n";

	cout << "Please select one of these options:\n";
	displayFileOptions(userChoice);
	chooseFile(userChoice, fileChoice);
	performAnimation(fileChoice);

    return 0;
}

// -----------------------------------------------------------------------

/* displayFileOptions
 * Displays the file options to the user
*/
void displayFileOptions(int& userChoice) {
	cout << "1. baby-names.txt\n";
	cout << "2. brands.txt\n";
	cout << "3. cities.txt\n";
	cout << "4. cities-usa.txt\n";
	cout << "5. endgame.txt\n";
	cout << "6. football.txt\n";
	cout << "7. game-of-thrones.txt\n";
	cout << "8. infinity-war.txt\n";
	cout << "9. movies.txt\n";
	cout << "10. patents.txt\n";
	cout << "11. trademarks.txt\n";

	cout << "Your Choice: ";
	cin >> userChoice;
	cout << endl;
}

// -----------------------------------------------------------------------

/* chooseFile
 * Switch-case statement to determine which file to read in 
*/
void chooseFile(int& userChoice, string& fileChoice) {
	
	switch (userChoice) {
	case 1:
		fileChoice = "baby-names.txt";
		break;

	case 2:
		fileChoice = "brands.txt";
		break;

	case 3:
		fileChoice = "cities.txt";
		break;

	case 4:
		fileChoice = "cities-usa.txt";
		break;

	case 5:
		fileChoice = "endgame.txt";
		break;

	case 6:
		fileChoice = "football.txt";
		break;

	case 7 :
		fileChoice = "game-of-thrones.txt";
		break;

	case 8:
		fileChoice = "infinity-war.txt";
		break;

	case 9:
		fileChoice = "movies.txt";
		break;

	case 10:
		fileChoice = "patents.txt";
		break;

	case 11:
		fileChoice = "trademarks.txt";
		break;

	default:
		break;
	}
}

// -----------------------------------------------------------------------

/* performAnimation
 * Opens the file, retrieves and stores file info,
 * and calls animate to produce animation
*/
void performAnimation(string& fileName) {

	ifstream inFile(fileName);
	assert(inFile.fail() == false);

	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);
	BarChartAnimate bca(title, xlabel, source);

	while (!inFile.eof()) {
		bca.addFrame(inFile);
	}

	int top = 0, endIter = 0;
	cout << "Choose number of bars to animate: ";

	// to check top is > 0
	while (top <= 0) {
		cin >> top;
	}
	
	cout << "Choose number of iterations of the animation: ";
	cin >> endIter;

	bca.animate(cout, top, endIter);
}

// -----------------------------------------------------------------------
