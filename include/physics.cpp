#include "physics.hpp"
#include "maths.hpp"
#include <iostream>
#include <sstream>
#include "input.hpp"
#include <list>
#include <cmath>
#include <cstdlib>
#include "FileReader.hpp"


class CParticle {
	
	private:
			double E;
	
	public:
		double mass, px, py, pz;
		int event;
		std::string name, source;
		
	public:
	
	CParticle() {
			E=0;
			mass=0;
			px=0;
			py=0;
			pz=0;
			name="";
			source="";
			event=0;
			
	}
	
	~CParticle(){};
	
	double get_E(){
		double p2=(px*px+py*py+pz*pz);
		E=sqrt(mass*mass+p2);
		return E;
	}
	
	
	/*void set_E(double Ein){
		E=Ein;
	}
	
	void set_mass(double massin){
		mass=massin;
	}
	
	void set_p(double pxin, double pyin, double pzin){
		px=pxin;
		py=pyin;
		pz=pzin;
	}*/
	
	
	
};


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

double meanMassOfRandParticles(){
	
	std::list<CParticle> particleList;
	double energyArray[100];
	int index[100];
	
	for (int i = 0;i<=99;i++) {
			CParticle newParticle;
			newParticle.px = rand()%201-100;
			newParticle.py = rand()%201-100;
			newParticle.pz = rand()%201-100;
			newParticle.mass = rand()%21-10;
			particleList.push_back(newParticle);
			energyArray[i]=newParticle.get_E();
			index[i]=i;
	}
	
	bubbleSort(energyArray,index,100,true);
	
	double mean;
	
		for (std::list<CParticle>::iterator p = particleList.begin();
			p!=particleList.end();++p) {
		std::cout << p->get_E() << std::endl;
				mean+= p->get_E();
	}
	mean/=100.0;
	
	double sd;
	
		for (std::list<CParticle>::iterator p = particleList.begin();
			p!=particleList.end();++p) {
				sd+=(p->get_E()-mean)*(p->get_E()-mean);
	}
	
	sd/=100.0;
	sd=sqrt(sd);
	
	std::cout << "Mean: " << mean << std::endl;
	std::cout << "s.d: " << sd << std::endl;
	
	
	
	return 0;
}

double muTwoParticle() {

	std::list<CParticle> muPlusParticleList;
	std::list<CParticle> muMinusParticleList;
	
	std::cout << "Two Particle" << std::endl;
	// Open the file to be read
	FileReader f("data//observedparticles.dat");
	
	// Only process if the file is open/valid
	if (f.isValid()) {
	  
	  // Loop until out of lines
	  f.nextLine();
	  
	  while (f.nextLine()) {
	    // Fields in each line line are treated as whitespace separated
	    // and co-unted from 1. Fields can be retrieved as one of four main
	    // types
			
			// int string double double double string
	
	    // retrieve field 1 of current line as an integer
	    int event = f.getFieldAsInt(1);
	
	    // retrieve field 2 as a float
	    std::string name = f.getFieldAsString(2);
			if (name!="mu+" && name!="mu-")
				continue;
				
	    // retrieve field 3 as a double
	    double px = f.getFieldAsDouble(3);
	
			double py = f.getFieldAsDouble(4);
	
	
			double pz = f.getFieldAsDouble(5);
	
	    // retrieve field 4 as a float
	    std::string source = f.getFieldAsString(6);
			
			// Check that input is o.k.
	    if (f.inputFailed()) break;
	    
	    CParticle newParticle;
	    newParticle.name=name;
	    newParticle.event=event;
	    newParticle.px = px;
			newParticle.py = py;
			newParticle.pz = pz;
			newParticle.source=source;
			
			if ("mu+"==name)
				muPlusParticleList.push_back(newParticle);
			else if ("mu-"==name)
				muMinusParticleList.push_back(newParticle);
			
			
	  }
	}
	
	
	for (std::list<CParticle>::iterator p=muPlusParticleList.begin();
			p!=muPlusParticleList.end(); ++p) {
		std::cout << p->name << " " << p->event << std::endl;
 	}
	
	for (std::list<CParticle>::iterator p=muMinusParticleList.begin();
			p!=muMinusParticleList.end(); ++p) {
		std::cout << p->name << " " << p->event << std::endl;
 	}
	


	return 0;
}
