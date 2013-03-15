#include "CTwoBodyGenerator.hpp"
#include "CParticle.hpp"
#include "CParticleInfo.hpp"
#include <vector>
#include <cmath>

CTwoBodyGenerator::CTwoBodyGenerator(const std::string Mother,const std::string Daughter1, const std::string Daughter2){
	
	CParticleInfo& ParticleInfoSingleton(CParticleInfo::Instance());
	
	// Set properties of mother, daugher1, daughter2 particles
	int motherID=ParticleInfoSingleton.getID(Mother);
	int daughter1ID=ParticleInfoSingleton.getID(Daughter1);
	int daughter2ID=ParticleInfoSingleton.getID(Daughter1);
	
	mother.name=Mother;
	mother.id=motherID;
	mother.set_mass(ParticleInfoSingleton.getMass(motherID));
	mother.charge=ParticleInfoSingleton.getCharge(motherID);
	//mother.get_E();
	
	daughter1.name=Daughter1;
	daughter1.id=daughter1ID;
	daughter1.set_mass(ParticleInfoSingleton.getMass(daughter1ID));
	daughter1.charge=ParticleInfoSingleton.getCharge(daughter1ID);
	
	daughter2.name=Daughter2;
	daughter2.id=daughter2ID;
	daughter2.set_mass(ParticleInfoSingleton.getMass(daughter2ID));
	daughter2.charge=ParticleInfoSingleton.getCharge(daughter2ID);
	
	

};
	
std::vector<CParticle> CTwoBodyGenerator::generate (const double beta) const {
	// Create a vector of CParticles that are the daughters of a
	// spin-0 meson to two other spin-0 mesons
	
	// Get random values of the angles
  double theta = acos(2.0*rand()/RAND_MAX-1.0);
  double phi = rand()*2.0*acos(-1.0)/RAND_MAX;
	
	// Calculate total momentum
	// e^2=p^2 c^2 +m^2 c^4
	// p= sqrt(e^2-m^2c^4/c^2)
	// Calculate the squares and 4th powers of the masses
  const double mM2 = mother.mass*mother.mass;
  const double d1M2 = daughter1.mass*daughter1.mass;
  const double d2M2 = daughter2.mass*daughter2.mass;

  const double mM4 = mM2*mM2;
  const double d1M4 = d1M2*d1M2;
  const double d2M4 = d2M2*d2M2;

  // Use those to calculate the magnitude of the momentum of each daughter particle
  
  double length =	sqrt( d1M4 - 2*d1M2*d2M2 - 2*d1M2*mM2 + d2M4 - 2*d2M2*mM2 + mM4 ) / ( 2*mother.mass);
	
	double px = length * sin(theta)*cos(phi);
  double py = length * sin(theta)*sin(phi);
  double pz = length * cos(theta);
 
	CParticle newDaughter1= daughter1;
	CParticle newDaughter2= daughter2;
	
	std::cout << newDaughter1.name << std::endl;
	std::cout << newDaughter2.name << std::endl;
	
	std::cout << newDaughter1.get_E() << std::endl;
	std::cout << newDaughter2.get_E() << std::endl;
	
	
	newDaughter1.set_momentum(px,py,pz);
	newDaughter2.set_momentum(-px,-py,-pz);
	
	newDaughter1.zboost(beta);
	newDaughter2.zboost(beta);
	
	// Return a vector of the particles
  std::vector<CParticle> particles;
  particles.push_back( newDaughter1 );
  particles.push_back( newDaughter2 );

  return particles;
	
	
};

CTwoBodyGenerator::~CTwoBodyGenerator() {}

