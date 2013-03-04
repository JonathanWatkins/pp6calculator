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
		std::string name, source;
		
	public:
	
	CParticle();
	
	~CParticle();
	
	double get_E();
		
};

#endif
