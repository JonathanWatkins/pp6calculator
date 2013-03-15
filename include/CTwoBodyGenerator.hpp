#ifndef CTWOBODYGENERATOR_HPP
#define CTWOBODYGENERATIR_HPP

#include "CEventGenerator.hpp"
#include <vector>
#include "CParticle.hpp"
#include <iostream>
#include <string>


class CTwoBodyGenerator : public CEventGenerator {
	
	private:
		CParticle mother, daughter1, daughter2;
	
	public:

		CTwoBodyGenerator(const std::string Mother,const std::string Daughter1, const std::string Daughter2);
		
		 ~CTwoBodyGenerator();
		
		virtual std::vector<CParticle> generate (const double) const;

	
	
	
};
#endif
