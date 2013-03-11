#ifndef CPARTICLE_HPP
#define CPARTICLE_HPP

#include <iostream>
#include <string>
#include "CFourVector.hpp"


class CParticle {
	
	private:
			double E;
	
	public:
		double mass, px, py, pz;
		int event;
		int id;
		std::string name, source;
		
	public:
	
	CParticle();
	
	~CParticle();
	
	double get_E();
	
	
	CParticle& operator=(const CParticle& rhs)
	{
			if (&rhs != this) {
				mass = rhs.mass;
				px = rhs.px;
				py = rhs.py;
				pz = rhs.pz;
				event = rhs.event;
				id = rhs.id;
				name = rhs.name;
				source = rhs.source;
	
			}
		
			return *this;
		}	
	
		
};

#endif
