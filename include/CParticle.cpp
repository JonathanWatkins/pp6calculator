#include "CParticle.hpp"
#include <cmath>

CParticle::CParticle() {
			E=0;
			mass=0;
			px=0;
			py=0;
			pz=0;
			name="";
			source="";
			event=0;
			
}
	
double CParticle::get_E(){
		double p2=(px*px+py*py+pz*pz);
		E=sqrt(mass*mass+p2);
		return E;
}
		
CParticle::~CParticle(){
}
