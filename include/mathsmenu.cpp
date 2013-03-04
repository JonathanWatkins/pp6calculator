#include "menu.hpp"
#include "mathsmenu.hpp"
#include <iostream>
#include <sstream>
#include "maths.hpp"

void showMenu_Maths() {
	
	std::stringstream oss;
	oss << "\nBasic Maths Operations\n"
			<< "------------------------------------------\n"
			<< "What operation do you want to perform ?\n"
							<< "1) Addition\n"
							<< "2) Subtraction\n"
							<< "3) Multiplication\n"
							<< "4) Division\n"
							<< "5) Interception of a line with the x-axis\n"
							<< "6) Solve a quadratic\n"
							<< "7) Length of a vector\n"
							<< "8) Swap doubles\n"
							<< "9) Bubble Sort\n"
							<< "x) to exit" << std::endl;
	
	showMenu(oss.str());		

}

int loopMenu_Maths() {
	

	char options[10];
	std::string fail;
	
	options[0]='1';
	options[1]='2';
	options[2]='3';
	options[3]='4';
	options[4]='5';
	options[5]='6';
	options[6]='7';
	options[7]='8';
	options[8]='9';
	options[9]='x';
	
	bool Exit=false;
	do{
	
		showMenu_Maths();
		
		std::string choice = loopMenu(options,10);
		
		//std::cout << choice << std::endl;
		
	
		if (choice=="1") {
			if(add()) std::cout << "Function Failed";
		} else if (choice=="2") {
			if(subtract()) std::cout << "Function Failed";	
		} else if (choice=="3") {
			if(multiply()) std::cout << "Function Failed";
		} else if (choice=="4") {
			if(divide()) std::cout << "Function Failed";
		} else if (choice=="5") {
			if(intercept()) std::cout << "Function Failed";
		} else if (choice=="6") {
			if(threevector()) std::cout << "Function Failed";
		} else if (choice=="7") {
			if(rootsOfQuadratic()) std::cout << "Function Failed";
		} else if (choice=="8") {
			if(swapInterface(fail)) std::cout << "Function Failed - " << fail;
		} else if (choice=="9") {
			if(bubbleSortInterface(fail)) std::cout << "Function Failed - " << fail;
		} else if (choice=="x") {
			Exit=true;
		}	
	}while(false==Exit);	
		
	//delete [] options;*/
	return 0;
}
