#ifndef CFOURVECTOR_HPP
#define CFOURVECTOR_HPP

#include <iostream>
#include <string>

class CFourVector {
	
private:
	double ct;
	double x;
	double y;
	double z;
	double interval;
	std::string intervalType;
	
public:

		CFourVector();
		
		CFourVector(double, double, double, double);
				
		~CFourVector();
		
		void calcInterval();

		CFourVector zboost(double velz_);

		
		void set(double, double, double , double);

		void set_ct(double);
		
		void set_x(double);
		
		void set_y(double);
		
		void set_z(double);
		
		double get_ct();
		
		double get_x();
		
		double get_y();
		
		double get_z();
		
		std::string get_intervalType();
		
		double get_interval();
		
		CFourVector& operator+=(const CFourVector& rhs)
		{
			ct += rhs.ct;
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
			
		
			return *this;
		}	
		
		CFourVector& operator=(const CFourVector& rhs)
		{
			if (&rhs != this) {
				ct = rhs.ct;
				x = rhs.x;
				y = rhs.y;
				z = rhs.z;
			}
		
			return *this;
		}	
	
	
	
	
};

CFourVector operator+(const CFourVector& lhs, const CFourVector& rhs);


#endif
