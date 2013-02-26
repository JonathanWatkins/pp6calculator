#include "menu.hpp"
#include "mainmenu.hpp"
#include <iostream>
#include <string.h>
#include <sstream>

bool inChoices(char* choice, int numChoices, char* chosen) {
	for (int i = 0;i<=numChoices-1;i++) 
		{
			if (choice[i]==chosen[0]) return true; 
		}
		return false;
}

int showMenu(std::string menutext) {

	std::cout << menutext;
	
	return 0;

}


std::string loopMenu(char* choice, int numChoices) {
	
	
	char operation[1];
	
	do
		{
			
			std::cin >> operation;
			
			if (( !inChoices(choice,numChoices,operation) )) {
			
				std::cin.clear();
				std::cin.ignore();
				std::cout << "\nThis is not a valid choice!  Please choose again." << std::endl; 
				//std::cout << "menu";/*optionsOss.str();
			} /* else {
			
				std::cout << "You have chosen " << operation << std::endl;
			} */
	
		}
		while ( !inChoices(choice,numChoices,operation) );
		
		std::stringstream oss;
		oss << operation[0];
		
		return oss.str();//(std::string)operation[0];
			
}		
	
