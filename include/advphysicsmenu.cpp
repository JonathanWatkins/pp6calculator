#include "menu.hpp"
#include "advphysicsmenu.hpp"
#include <iostream>
#include <sstream>
#include "maths.hpp"
#include "physics.hpp"

void showMenu_AdvPhysics() {
	
	std::stringstream oss;
	oss << "\nAdvanced Physics Operations\n"
			<< "------------------------------------------\n"
			<< "What operation do you want to perform ?\n"
							<< "1) Mean and S.D of invariant masses of random particles \n"
							<< "2) Two-Particle mu+/mu- from observed.dat file\n"
							<< "3) Import data from pdg.dbt file\n"
							<< "4) Run single decay TwoBodyGenerator\n"
							<< "x) to exit" << std::endl;
	
	showMenu(oss.str());		

}

int loopMenu_AdvPhysics() {
	
	
	char options[5];
	std::string fail;
	
	options[0]='1';
	options[1]='2';
	options[2]='3';
	options[3]='4';
	options[4]='x';
	
	
	bool Exit=false;
	do{
	
		showMenu_AdvPhysics();
		
		std::string choice = loopMenu(options,5);
		
		//std::cout << choice << std::endl;
		
	
		if (choice=="1") {
				if(meanMassOfRandParticles()) std::cout << "Function Failed";	
		} else if (choice=="2") {
				if(muTwoParticle()) std::cout << "Function Failed";
		} else if (choice=="3") {
				if(readPDGDatbase()) std::cout << "Function Failed";
		} else if (choice=="4") {
				if(runTwoBodyGenerator()) std::cout << "Function Failed";
		} else if (choice=="x") {
			Exit=true;
		}	
	}while(false==Exit);	
		
	//delete [] options;*/
	return 0;
}
