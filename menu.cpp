#include "mainmenu.hpp"
#include <iostream>

void showMenu(string menutext) {

	/*std::cout 	<< "Welcome to the pp6calculator" << endl
				<< "----------------------------" << endl
				<< "Choose one of the following options" << endl
				<< "1) Basic Maths Operations" << endl;
				<< "2) Physics operations" << endl;
				<< "q) Quit" << endl;
	*/
	std::cout << menutext;

}


char[1] loopMenu(char* choice, int numChoices) {
	
	do
		{
			
			cin >> operation;
			
			if (( /*not one of the possible choices*/ )) {
			
				cin.clear();
				cin.ignore();
				cout << "\nThis is not a valid choice!  Please choose again." << endl; 
				cout << optionsOss.str();
			} else {
			
				cout << "You have chosen " << operation << endl;
			}
	
		}
		while ( /*not one of the possible choices*/ );
		
			
		return operation*;
					
			
}		
	
