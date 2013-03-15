#ifndef CPARTICLEINFO_HPP
#define CPARTICLEINFO_HPP

#include <iostream>
#include <string>
#include <map>

class CParticleInfo {
		
public:
	
	static CParticleInfo& Instance();
	
	//typedef std::map<std::string,int> TPartIdMap;
	std::map<std::string,int> NameIdMap;
	std::map<int,std::string> IdNameMap;
	std::map<int,double> IdChargeMap;
	std::map<int,double> IdMassMap;
	
private:	
	
	CParticleInfo(){};
	~CParticleInfo();

public:
	
	int getID(const std::string&) const;
	std::string getName(const int) const;
	double getCharge(const int) const;
	double getMass(const int) const;
	
	int addMaps(const std::string&, const int, const double, const double);
	
private:
		
	static CParticleInfo* theInstance;
	
};


#endif
