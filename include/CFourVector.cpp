#include "CFourVector.hpp"

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

CFourVector::CFourVector(){
	ct=0;
	x= 0;
	y=0;
	z=0;
	
}

CFourVector::CFourVector(double ct_, double x_, double y_, double z_)
	: ct(ct_), x(x_), y(y_), z(z_)
{
	calcInterval();
}

CFourVector::~CFourVector(){
	calcInterval();
}


void CFourVector::calcInterval(){
	
	std::stringstream oss;
	
	double dr2=x*x+y*y+z*z;
	double ct2=ct*ct;
	interval=ct2-dr2;
	oss << "(" << ct << ", " << x  << ", " << y  << ", " << z << ")" << std::endl;
	if (ct2>dr2) {
		oss << "The interval is time-like and events are casually related." << std::endl;
	} else if (ct2==dr2) {
		oss << "The interval is light-like and events are casually related." << std::endl;
	} else if (ct2<dr2) {
		oss << "The interval is space-like and events lie outside each others light cone." << std::endl;
	}
	
	oss << "The space-time interval is ds^2 = " << interval << std::endl;
	intervalType= oss.str();
	
}


CFourVector CFourVector::zboost(double velz) {
	double beta=velz; //vel in units of c and using natural units
	double gamma=sqrt(1-beta*beta);
	
	CFourVector outVector;
	
	outVector.ct=gamma*(ct-beta*z);
	outVector.x=x;
	outVector.y=y;
	outVector.z=gamma*(z-beta*ct);
	
	outVector.calcInterval();
	
	return outVector;
	
}

void CFourVector::set(double ct_, double x_, double y_, double z_) {
	ct=ct_;
	x=x_;
	y=y_;
	z=z_;
	calcInterval();
};


void CFourVector::set_ct(double ct_) { ct=ct_; calcInterval(); };
		
void CFourVector::set_x(double x_)  { x=x_; calcInterval(); };
		
void CFourVector::set_y(double y_){ y=y_; calcInterval(); };
		
void CFourVector::set_z(double z_){ z=z_; calcInterval(); };
		
		
double CFourVector::get_ct() { return ct; };
		
double CFourVector::get_x() { return x; };
		
double CFourVector::get_y() { return y; };
		
double CFourVector::get_z() { return z; };
		
std::string CFourVector::get_intervalType() { return intervalType; };
		
double CFourVector::get_interval() { return interval; };
		
CFourVector operator+(const CFourVector& lhs, const CFourVector& rhs)
{
CFourVector temp(lhs);
temp += rhs;

return temp;
};
