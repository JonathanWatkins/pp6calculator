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
							<< "'+' Addition\n"
							<< "'-' Subtraction\n"
							<< "'*' Multiplication\n"
							<< "'/' Division\n"
							<< "'i' Interception of a line with the x-axis\n"
							<< "'q' Solve a quadratic\n"
							<< "'3' Length of a vector\n"
							<< "'s' Swap doubles\n"
							<< "'b' Bubble Sort\n"
							<< "'x' to exit" << std::endl;
	
	showMenu(oss.str());		

}

int loopMenu_Maths() {
	

	char options[10];
	std::string fail;
	
	options[0]='+';
	options[1]='-';
	options[2]='*';
	options[3]='/';
	options[4]='i';
	options[5]='q';
	options[6]='3';
	options[7]='s';
	options[8]='b';
	options[9]='x';
	
	bool Exit=false;
	do{
	
		showMenu_Maths();
		
		std::string choice = loopMenu(options,10);
		
		//std::cout << choice << std::endl;
		
	
		if (choice=="+") {
			//if(add()) cout << "Function Failed";
		} else if (choice=="-") {
			//if(subtract()) cout << "Function Failed";	
		} else if (choice=="*") {
			//if(multiply()) cout << "Function Failed";
		} else if (choice=="/") {
			//if(divide()) cout << "Function Failed";
		} else if (choice=="i") {
			//if(intercept()) cout << "Function Failed";
		} else if (choice=="3") {
			//if(threevector()) cout << "Function Failed";
		} else if (choice=="q") {
			//if(rootsOfQuadratic()) cout << "Function Failed";
		} else if (choice=="s") {
			if(swapInterface(fail)) std::cout << "Function Failed - " << fail;
		} else if (choice=="b") {
			if(bubbleSortInterface(fail)) std::cout << "Function Failed - " << fail;
		} else if (choice=="x") {
			Exit=true;
		}	
	}while(false==Exit);	
		
	//delete [] options;*/
	return 0;
}
