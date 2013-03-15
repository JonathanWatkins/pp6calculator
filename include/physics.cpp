#include "physics.hpp"
#include "maths.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "input.hpp"
#include <list>
#include <vector>
#include <cmath>
#include <cstdlib>
#include "FileReader.hpp"
#include "CParticle.hpp"
#include "CParticleInfo.hpp"
#include "CTwoBodyGenerator.hpp"

double invariantMass(double E, double px, double py, double pz) {
	return E*E - px*px - py*py - pz*pz;
}


int intervalInterface() {
	
	double ds2;
	
	double ct=get_double("ct: ");
	double x= get_double("x: ");
	double y= get_double("y: ");
	double z= get_double("z: ");
	
	CFourVector newVector;
	newVector.set(ct,x,y,z);
	
	std::string intervalType = newVector.get_intervalType();
	
	std::cout << intervalType;
	
	return 0;
	
}

int invariantMassInterface() {
	
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
			newParticle.set_momentum(rand()%201-100, rand()%201-100, rand()%201-100);
			
			newParticle.set_mass(rand()%21-10);
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
	std::cout <<std::setprecision(3);
	std::cout << "Two Particle" << std::endl;
	// Open the file to be read
	FileReader f("data//observedparticles.dat");
	if (!f.isValid()) {
		std::cout << "There is not data at the location 'data/observedparticles.dat'" << std::endl;
		return 1;
	}
	
	
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
	    //int event = f.getFieldAsInt(1);
			bool error;
			int event = f.getField<int>(1, error);
			if (true==error) break;
			
	    // retrieve field 2 as a float
	    //std::string name = f.getFieldAsString(2);
	    std::string name = f.getField<std::string>(2, error);
	    if (true==error) break;
			
			if (name!="mu+" && name!="mu-")
				continue;
				
	    // retrieve field 3 as a double
	    //double px = f.getFieldAsDouble(3);
	
			//double py = f.getFieldAsDouble(4);
	
	
			//double pz = f.getFieldAsDouble(5);
	
	
			double px = f.getField<double>(3,error);
			if (true==error) break;
			
			double py = f.getField<double>(4,error);
			if (true==error) break;
			
	
			double pz = f.getField<double>(5,error);
			if (true==error) break;
			
	
	    // retrieve field 4 as a float
	    //std::string source = f.getFieldAsString(6);
			std::string source = f.getField<std::string>(6,error);
			if (true==error) break;
			
			// Check that input is o.k.
	    if (f.inputFailed()) break;
	    
	    CParticle newParticle;
	    newParticle.name=name;
	    newParticle.event=event;
	    newParticle.set_momentum(px,py,pz);
			newParticle.source=source;
			
			if ("mu+"==name)
				muPlusParticleList.push_back(newParticle);
			else if ("mu-"==name)
				muMinusParticleList.push_back(newParticle);
			
			
	  }
	}
	
	
	/*for (std::list<CParticle>::iterator p=muPlusParticleList.begin();
			p!=muPlusParticleList.end(); ++p) {
		std::cout << p->name << " " << p->event << std::endl;
 	}
	
	for (std::list<CParticle>::iterator p=muMinusParticleList.begin();
			p!=muMinusParticleList.end(); ++p) {
		std::cout << p->name << " " << p->event << std::endl;
 	}
	*/
	
	std::vector<CParticle> pairsVector;
	
	for (std::list<CParticle>::iterator p=muPlusParticleList.begin();
			p!=muPlusParticleList.end(); ++p) {
		for (std::list<CParticle>::iterator q=muMinusParticleList.begin();
				q!=muMinusParticleList.end(); ++q) {
			std::stringstream ss;
			
			
			CParticle newPair;
			ss << p->event << "/" << q->event;
	    newPair.name=ss.str();
	    newPair.set_momentum(p->get_px()+q->get_px(), p->get_py()+q->get_py(), p->get_pz()+q->get_pz());
			//newPair.source=source;
			
			pairsVector.push_back(newPair);
		}	
	}
	int n = pairsVector.size();
	int *index = new int[(int)n];
	double *energyArray = new double[(int)n];
		
		
	int i=0;	
	for (std::vector<CParticle>::iterator p=pairsVector.begin();
			p!=pairsVector.end(); ++p) {
		
		energyArray[i]=p->get_E();
		index[i]=i;
		i++;
	}
	std::vector<CParticle> initialPairsVector=pairsVector;
	
	//for (int j=0;j<=pairsVector.size()-1;j++){
	//	std::cout << j << "  " << pairsVector[j].name <<  "  " << pairsVector[j].get_E() << std::endl;
		
	//}
	std::cout << std::endl;
	std::cout << std::endl;
	//indexedBubbleSort(energyArray,index,(int)n);
	bubbleSort(energyArray,index,(int)n,false);
	
	std::cout << "10 Highest Invariant Mass Pairs" << std::endl;
	int numPairs=10; // initialPairsVector.size() for all
	for (int j=0;j<=numPairs-1;j++){
		std::cout << j << ")"  << initialPairsVector[index[j]].name <<  "  "  << initialPairsVector[index[j]].get_E() << std::endl;
		
	}
	std::cout << std::endl;
	
	
	//for (int i = 0; i<=10;i++ ) {
	//	std:: cout << energyArray[i] << std::endl; 
			
		
	//}
		
	
	
	
	delete [] index;
	delete [] energyArray;
	


	return 0;
}


int runTwoBodyGenerator() {
	
	CParticleInfo& ParticleInfoSingleton(CParticleInfo::Instance());
	std::cout << ParticleInfoSingleton.getID("B+") << std::endl;
	
	CTwoBodyGenerator newTwoBodyGenerator("B0","K+","pi-");
	std::vector<CParticle> decaysVector = newTwoBodyGenerator.generate(0.2);
	
	for (std::vector<CParticle>::iterator p = decaysVector.begin();
			p != decaysVector.end(); ++p) {
	
		std::cout << p->get_px() << ", " << p->get_py() << ", " << p->get_pz() << std::endl;		
	
	
	}
	
	std::cout << invariantMass(
				decaysVector[0].get_E()+ decaysVector[1].get_E(),
				decaysVector[0].get_px()+decaysVector[1].get_px(),
				decaysVector[0].get_py()+decaysVector[1].get_py(),
				decaysVector[0].get_pz()+ decaysVector[1].get_pz()) << std::endl;
	
	
	
	
	return 0;
	
	
}


double readPDGDatbase() {

	//CEventGenerator newEventGenerator;
	
	

	CParticleInfo& ParticleInfoSingleton(CParticleInfo::Instance());
	std::vector<std::string> nameVector;
	std::vector<int> idVector;
	std::vector<double> chargeVector;
	std::vector<double> massVector;
	
	std::cout <<std::setprecision(3);
	std::cout << "Read PDG Database" << std::endl;
	// Open the file to be read
	FileReader f("data//pdg.dbt");
	if (!f.isValid()) {
		std::cout << "There is not data at the location 'data/pdg.dbt'" << std::endl;
		return 1;
	}
	
	
	// Only process if the file is open/valid
	if (f.isValid()) {
	  
	  // Loop until out of lines
	  //f.nextLine();
	  
	  while (f.nextLine()) {
	    // Fields in each line line are treated as whitespace separated
	    // and co-unted from 1. Fields can be retrieved as one of four main
	    // types
			
			// int string double double double string
	
	    // retrieve field 1 of current line as an integer
	    //int event = f.getFieldAsInt(1);
			bool error;
			std::string name = f.getField<std::string>(1, error);
			if (true==error) break;
			
			
			
	    // retrieve field 2 as a float
	    //std::string name = f.getFieldAsString(2);
	    int id = f.getField<int>(2, error);
	    if (true==error) break;
			
			// retrieve field 3 as a double
	    //double px = f.getFieldAsDouble(3);
	
			//double py = f.getFieldAsDouble(4);
	
	
			//double pz = f.getFieldAsDouble(5);
	
	
			double charge = f.getField<double>(3,error);
			if (true==error) break;
			
			double mass = f.getField<double>(4,error);
			if (true==error) break;
						
			// Check that input is o.k.
	    if (f.inputFailed()) break;
	    
	   
	    
	    nameVector.push_back(name);
	    idVector.push_back(id);
	    chargeVector.push_back(charge);
	    massVector.push_back(mass);
	    
	   ParticleInfoSingleton.addMaps(name,id,charge,mass);
			
			
	  }
	}
	
	
	
	
	for (std::vector<std::string>::iterator p=nameVector.begin();
			p!=nameVector.end(); ++p) {
		std::cout << *p << std::endl;
 	}
 	
 	runTwoBodyGenerator();  // Test ParticleInfo Singleton
 	
	return 0;
}



int zBooststInterface(){
	
	double ct=get_double("ct: ");
	double x= get_double("x: ");
	double y= get_double("y: ");
	double z= get_double("z: ");
	
	CFourVector initialVector;
	initialVector.set(ct,x,y,z);
	
	double velz=get_double("vz (in units of c): ");  //in units of c
	
	CFourVector boostedVector = initialVector.zboost(velz);
	
	std::cout << initialVector.get_intervalType();
		
	std::cout << "The boosted 4-vector is (" 
	<< boostedVector.get_ct() << ", "
	<< boostedVector.get_x() << ", "
	<< boostedVector.get_y() << ", "
	<< boostedVector.get_z() << ")" << std::endl;
	
	std::cout << boostedVector.get_intervalType();
	
	
	
	
	
	return 0;
}

int zBoostEpInterface(){
	
	double ct=get_double("E: ");
	double x= get_double("px: ");
	double y= get_double("py: ");
	double z= get_double("pz: ");
	
	CFourVector initialVector;
	initialVector.set(ct,x,y,z);
	
	double velz=get_double("vz (in units of c): ");  //in units of c
	
	CFourVector boostedVector = initialVector.zboost(velz);
	
	
	std::cout << initialVector.get_intervalType();
	
	
	std::cout << "The boosted 4-vector is (" 
	<< boostedVector.get_ct() << ", "
	<< boostedVector.get_x() << ", "
	<< boostedVector.get_y() << ", "
	<< boostedVector.get_z() << ")" << std::endl;
	
	std::cout << boostedVector.get_intervalType();

	
	
	
	
	return 0;
}

