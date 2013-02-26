/* This is the pp6calculator written by Jonathan Watkins
 * 
 * Current features are
 * 		- Addition
 * 		- Subtraction
 * 		- Multiplication
 * 		- Division
 * 		- Roots of a quadratic
 * 		- Length of a 3-vector
 * 		- Calculation of ds^2
 * 		- Calculation of the invariant mass
 * 		
 * 
 * 		Note: stringstreams are implemented for future use cases. 
 * 					The function results are written to a streamstream and may be
 * 					returned to the main loop rather than being immediately output
 * 					to screen. 
 */ 

#include <iostream>
#include <sstream>
#include <string.h>
#include <climits>
#include <cmath>
#include <iomanip>
#include <cstdlib>

#include "input.hpp"
#include "maths.hpp"
#include "physics.hpp"

#include "mainmenu.hpp"


using namespace std;





int main() {
	
	char operation[1];
	string fail;
	srand(time(0));
	
	stringstream optionsOss;
	
	// The following defines the menu choices
	// New choices must be added to if and while loops below
	
	optionsOss << "\nWhat operation do you want to perform ?" << endl;
	optionsOss 	<< "------------------------------------------\n"
							<< "'+' Addition\n"
							<< "'-' Subtraction\n"
							<< "'*' Multiplication\n"
							<< "'/' Division\n"
							<< "'i' Interception of a line with the x-axis\n"
							<< "'q' Solve a quadratic\n"
							<< "'3' Length of a vector\n"
							<< "'4' ds^2 of a 4-vector\n"
							<< "'m' Invariant mass\n"
							<< "'s' Swap doubles\n"
							<< "'b' Bubble Sort\n"
							<< "'x' to exit" << endl;
		
	bool Exit=false;
	do
	{
		
		
		Exit=loopMenu_Main();
		
		// Display the menu
		/*cout << optionsOss.str();
		
		
		do
		{
			
			cin >> operation;
			
			if (( *operation!='+' && *operation!='-' && *operation!='*' && *operation!='/'  && *operation!='x' && *operation!='i' && *operation!='3' && *operation!='4' && *operation!='m' && *operation!='q' && *operation!='b' )) {
				cin.clear();
				cin.ignore();
				cout << "\nThis is not a valid choice!  Please choose again." << endl; 
				cout << optionsOss.str();
			} else {
			
				cout << "You have chosen " << operation << endl;
			}
	
		}
		while ( *operation!='+' && *operation!='-' && *operation!='*' && *operation!='/' && *operation!='x' && *operation!='i' && *operation!='3' && *operation!='4' && *operation!='m' && *operation!='q' && *operation!='s' && *operation!='b');
		
		if (*operation!='x') {
			
			
			// If exit is not chosen run the requested function
			if (*operation=='+') {
				if(add()) cout << "Function Failed";
			} else if (*operation=='-') {
				if(subtract()) cout << "Function Failed";	
			} else if (*operation=='*') {
				if(multiply()) cout << "Function Failed";
			} else if (*operation=='/') {
				if(divide()) cout << "Function Failed";
			} else if (*operation=='i') {
				if(intercept()) cout << "Function Failed";
			} else if (*operation=='3') {
				if(threevector()) cout << "Function Failed";
			} else if (*operation=='4') {
				if(fourvector()) cout << "Function Failed";
			} else if (*operation=='m') {
				if(invariantMassInterface()) cout << "Function Failed";
			} else if (*operation=='q') {
				if(rootsOfQuadratic()) cout << "Function Failed";
			} else if (*operation=='s') {
				if(swapInterface(fail)) cout << "Function Failed - " << fail;
			} else if (*operation=='b') {
				if(bubbleSortInterface(fail)) cout << "Function Failed - " << fail;
			}
			
			
			
			cout << "\n\n";
			
		}
		*/
		
		
	}
	while (false==Exit);
	
	cout << "Goodbye!" << endl;
	
	return 0;
}


