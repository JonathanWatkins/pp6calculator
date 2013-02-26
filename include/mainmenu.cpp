#include "menu.hpp"
#include "mainmenu.hpp"
#include <iostream>
#include <sstream>
#include "mathsmenu.hpp"
#include "physicsmenu.hpp"
#include "advphysicsmenu.hpp"



void showMenu_Main() {
	
	std::stringstream oss;
	
	 oss	<< "\nWelcome to the pp6calculator" << std::endl
				<< "----------------------------" << std::endl
				<< "Choose one of the following options" << std::endl
				<< "1) Basic Maths Operations" << std::endl
				<< "2) Basic Physics Operations" << std::endl
				<< "3) Advanced Physics Operations" << std::endl
				<< "x) Exit" << std::endl;
				
		showMenu(oss.str());		

}

int loopMenu_Main() {
	
	char options[4];
	
	options[0]='1';
	options[1]='2';
	options[2]='3';
	options[3]='x';
	
	
	bool Exit=false;
	do{
	
		showMenu_Main();
		std::string choice = loopMenu(options,4);
	
		//std::cout << choice << std::endl;
	
		if (choice=="1") {
			loopMenu_Maths();
		} else if (choice=="2") {
			loopMenu_Physics();	
		} else if (choice=="3") {
			loopMenu_AdvPhysics();		
		} else if (choice=="x") {
			Exit=true;
		}
			
	}		
	while (false==Exit);
	
	//delete [] options;*/
	return 1;
}
