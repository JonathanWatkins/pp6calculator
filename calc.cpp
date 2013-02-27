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


int main() {
	
	char operation[1];
	std::string fail;
	srand(time(0));
	
	bool Exit=false;
	do
	{
		
		Exit=loopMenu_Main();
				
		
	}
	while (false==Exit);
	
	std::cout << "Goodbye!" << std::endl;
	
	return 0;
}


