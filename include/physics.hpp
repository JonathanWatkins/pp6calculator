#ifndef CALC_PHYSICS_HPP
#define CALC_PHYSICS_HPP
#include <iostream>
#include <string>
#include "CFourVector.hpp"

double invariantMass(double E, double px, double py, double pz);

double muTwoParticle();

double meanMassOfRandParticles();

int intervalInterface();

int invariantMassInterface();

int zBooststInterface();

int zBoostEpInterface();


#endif
