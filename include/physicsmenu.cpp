#include "menu.hpp"
#include "physicsmenu.hpp"
#include <iostream>
#include <sstream>
#include "maths.hpp"
#include "physics.hpp"

void showMenu_Physics() {
	
	std::stringstream oss;
	oss << "\nBasic Physics Operations\n"
			<< "------------------------------------------\n"
			<< "What operation do you want to perform ?\n"
							<< "1) Invariant Mass\n"
							<< "2) Length of a 4-vector\n"
							<< "3) z-Boost E/p 4-Vector\n"
							<< "4) z-Boost space-time 4-Vector\n"
							<< "x) to exit" << std::endl;
	
	showMenu(oss.str());		

}

int loopMenu_Physics() {
	

	char options[3];
	std::string fail;
	
	options[0]='1';
	options[1]='2';
	options[2]='3';
	options[3]='4';
	options[4]='x';
	
	
	bool Exit=false;
	do{
	
		showMenu_Physics();
		
		std::string choice = loopMenu(options,5);
		
		//std::cout << choice << std::endl;
		
	
		if (choice=="1") {
			if(invariantMassInterface()) std::cout << "Function Failed";
		} else if (choice=="2") {
			if(intervalInterface()) std::cout << "Function Failed";	
		} else if (choice=="3") {
			if(zBoostEpInterface()) std::cout << "Function Failed";	
		} else if (choice=="4") {
			if(zBooststInterface()) std::cout << "Function Failed";	
		} else if (choice=="x") {
			Exit=true;
		}	
	}while(false==Exit);	
		
	//delete [] options;*/
	return 0;
}
