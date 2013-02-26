#include "input.hpp"
#include <string>
#include <iostream>
#include <climits>

double get_double (std::string question) {
	if (question.empty()) {
	 question="Enter number: ";
	}
	
	// Add error checking
	double a;
	std::cout << question;
	
	while (!(std::cin >> a)) {
		std::cin.clear();
		std::cin.ignore(INT_MAX,'\n');
		std::cout << question;
		
	};
    return a;
}
