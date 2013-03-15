#ifndef CEVENTGENERATOR_HPP
#define CEVENTGENERATOR_HPP

#include "CParticle.hpp"
#include <vector>

class CEventGenerator {

	public:
				
		virtual ~CEventGenerator(){};
		
		virtual std::vector<CParticle> generate (const double) const =0;


};
#endif
