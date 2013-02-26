#include "physics.hpp"
#include <iostream>
#include <sstream>
#include "input.hpp"

double invariantMass(double E, double px, double py, double pz) {
	return E*E - px*px - py*py - pz*pz;
}


double fourvector() {
	
	std::stringstream oss;
	
	double ct=get_double("ct: ");
	double x= get_double("x: ");
	double y= get_double("y: ");
	double z= get_double("z: ");
	
	double dr2=x*x+y*y+z*z;
	double ct2=ct*ct;
	if (ct2>dr2) {
		oss << "The interval is time-like and events are casually related." << std::endl;
	} else if (ct2==dr2) {
		oss << "The interval is light-like and events are casually related." << std::endl;
	} else if (ct2<dr2) {
		oss << "The interval is space-like and events lie outside each others light cone." << std::endl;
	}
	
	oss << "The space-time interval is ds^2 = " << ct*ct-x*x-y*y-z*z;
	
	std::cout << oss.str();
	
	return 0;
	
}

double invariantMassInterface() {
	
	std::stringstream oss;
	
	std::cout << "The Energy-momentum relation is defined as" << std::endl
	<< "    E^2 = (pc)^2 + (m0 c^2)^2" << std::endl
	<< "where p= gamma(u) m u and p= |p|" << std::endl
	<< "From this definition the invariant mass is calculated as " << std::endl
	<< "    m0^2 c^2 = (E/c)^2 - |p|^2  or m0^2=E^2-|p|^2 if c=1" << std::endl
	<< "Note: E and p are measured differently depending on the observers frame." << std::endl << std::endl;  
	double E= get_double("E: ");
	double px= get_double("px: ");
	double py= get_double("py: ");
	double pz= get_double("pz: ");
	
	oss << "The invariant mass squared is m0^2 = " << invariantMass(E,px,py,pz) << std::endl;
	
	std::cout << oss.str();
	
	return 0;
		
}

