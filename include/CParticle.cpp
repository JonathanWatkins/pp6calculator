#include "CParticle.hpp"
#include "CFourVector.hpp"
#include <cmath>

CParticle::CParticle() {
			//E=0;
			mass=0;
			//px=0;
			//py=0;
			//pz=0;
			name="";
			source="";
			event=0;
			id=0;
			
}
	
double CParticle::get_E(){
		
		return EM.get_ct();;
}


int CParticle::set_momentum(double px_, double py_, double pz_)
{
	
	EM.set_x(px_);
	EM.set_y(py_);
	EM.set_z(pz_);
	
	// set E
	double px = EM.get_x();
	double py = EM.get_y();
	double pz = EM.get_z();

		 
	double p2=(px*px+py*py+pz*pz);	
	double E=sqrt(mass*mass+p2);
	
	EM.set_ct(E);
		
	return 0;
	
}

int CParticle::set_mass(double mass_)
{
	mass = mass_;
}

double CParticle::get_px()
{
	return EM.get_x();
}

double CParticle::get_py()
{
	return EM.get_y();
}
	
double CParticle::get_pz()
{
	return EM.get_z();
}

int CParticle::set_E(double E_)
{
	
	EM.set_ct(E_);
	
	return 0;
}
		
CParticle::~CParticle(){
}


int CParticle::zboost(double beta_) {
	EM=EM.zboost(beta_);
	return 0;
}
