#ifndef CPARTICLE_HPP
#define CPARTICLE_HPP

#include <iostream>
#include <string>
#include "CFourVector.hpp"


class CParticle {
	
	private:
			//double E;
			CFourVector EM;
	
	public:
		double mass;//, px, py, pz;
		
		double charge;
		int event;
		int id;
		std::string name, source;
		
	public:
	
	CParticle();
	
	~CParticle();
	
	double get_E();
	
	int set_momentum(double, double, double);
	
	int set_mass(double);
	
	double get_px();
	
	double get_py();
	
	double get_pz();
	
	int set_E(double);
	
	int zboost(double);
	
	CParticle& operator=(const CParticle& rhs)
	{
			if (&rhs != this) {
				mass = rhs.mass;
				//px = rhs.px;
				//py = rhs.py;
				//pz = rhs.pz;
				EM = rhs.EM;
				event = rhs.event;
				id = rhs.id;
				name = rhs.name;
				source = rhs.source;
	
			}
		
			return *this;
		}	
	
		
};

#endif
