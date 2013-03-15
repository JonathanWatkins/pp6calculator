#include "CParticleInfo.hpp"

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

CParticleInfo* CParticleInfo::theInstance =0;

CParticleInfo& CParticleInfo::Instance()
{
	if (theInstance == 0) {
			theInstance = new CParticleInfo();
	}
	return *theInstance;
}


int CParticleInfo::getID(const std::string& name) const
{
	std::map<std::string,int>::const_iterator p = NameIdMap.find(name);
	
	if (p!=NameIdMap.end()) {
		return (*p).second;
	}
	return 0;
}

std::string CParticleInfo::getName(const int id) const
{
	std::map<int,std::string>::const_iterator p = IdNameMap.find(id);
	
	if (p!=IdNameMap.end()) {
		return (*p).second;
	}
		return "";
}

double CParticleInfo::getCharge(const int id) const
{
	std::map<int,double>::const_iterator p = IdChargeMap.find(id);
	
	if (p!=IdChargeMap.end()) {
		return (*p).second;
	}
	return 0;
}

double CParticleInfo::getMass(const int id) const
{
	std::map<int,double>::const_iterator p = IdMassMap.find(id);
	
	if (p!=IdMassMap.end()) {
		return (*p).second;
	}
	return 0;
}

int CParticleInfo::addMaps(const std::string& name, const int id, const double charge, const double mass)
{
	NameIdMap.insert(std::make_pair(name,id));
	IdNameMap.insert(std::make_pair(id,name));
	IdChargeMap.insert(std::make_pair(id,charge));
	IdMassMap.insert(std::make_pair(id,mass));
	
	
	return 0;	
}
