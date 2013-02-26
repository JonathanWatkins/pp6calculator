#include "menu.hpp"
#include "physicsmenu.hpp"
#include <iostream>
#include <sstream>
#include "maths.hpp"
#include "physics.hpp"

void showMenu_Physics() {
	
	std::stringstream oss;
	oss << "\nPhysics Operations\n"
			<< "------------------------------------------\n"
			<< "What operation do you want to perform ?\n"
							<< "'m' Invariant Mass\n"
							<< "'4' Length of a 4-vector\n"
							<< "'x' to exit" << std::endl;
	
	showMenu(oss.str());		

}

int loopMenu_Physics() {
	

	char options[3];
	std::string fail;
	
	options[0]='m';
	options[1]='4';
	options[2]='x';
	
	
	bool Exit=false;
	do{
	
		showMenu_Physics();
		
		std::string choice = loopMenu(options,3);
		
		//std::cout << choice << std::endl;
		
	
		if (choice=="m") {
			if(invariantMassInterface()) std::cout << "Function Failed";
		} else if (choice=="4") {
			if(fourvector()) std::cout << "Function Failed";	
		} else if (choice=="x") {
			Exit=true;
		}	
	}while(false==Exit);	
		
	//delete [] options;*/
	return 0;
}
