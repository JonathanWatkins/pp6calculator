#include "menu.hpp"
#include "mainmenu.hpp"
#include <iostream>
#include <sstream>
#include "mathsmenu.hpp"
#include "physicsmenu.hpp"



void showMenu_Main() {
	
	std::stringstream oss;
	
	 oss	<< "\nWelcome to the pp6calculator" << std::endl
				<< "----------------------------" << std::endl
				<< "Choose one of the following options" << std::endl
				<< "1) Basic Maths Operations" << std::endl
				<< "2) Physics operations" << std::endl
				<< "x) Exit" << std::endl;
				
		showMenu(oss.str());		

}

int loopMenu_Main() {
	
	char options[3];
	
	options[0]='1';
	options[1]='2';
	options[2]='x';
	
	bool Exit=false;
	do{
	
		showMenu_Main();
		std::string choice = loopMenu(options,3);
	
		//std::cout << choice << std::endl;
	
		if (choice=="1") {
			loopMenu_Maths();
		} else if (choice=="2") {
			loopMenu_Physics();	
		} else if (choice=="x") {
			Exit=true;
		}
			
	}		
	while (false==Exit);
	
	//delete [] options;*/
	return 1;
}
