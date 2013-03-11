#ifndef CALC_MATHS_HPP
#define CALC_MATHS_HPP

#include <iostream>
#include <string.h>
#include <iomanip>


template<typename typeA>  // This is an example of Static Polymorphism. It cannot be changed at run-time. This would be dynamic polymorphism
int swap(typeA& a, typeA& b);

template<typename typeA>
int indexedBubbleSort(typeA *a, int *index, int n);

template<typename typeA>
int bubbleSort(typeA* a, int* index, int n, bool showsteps) {

	bool switched = false;
	do
	{
		switched=false;	
		for (int i=0;i<=n-2;i++) {
			if (a[i]<a[i+1]) {
				swap(a[i],a[i+1]);
				swap(index[i],index[i+1]);
				switched=true;
			}
		}
	
		if (true==showsteps) {
			for (int i = 0; i<=n-1;i++) {
				std::cout << std::setw(5) << a[i];
			}
			std::cout << std::endl;
		}
		
		
	}
	while (true==switched);

	return 0;
};




/*---------------------------------
 * 
 * Here are the user interfaces for the maths functions
 * 
 * 
 */

double swapInterface(std::string &fail);

double bubbleSortInterface(std::string &fail);


/* -------------------------------
 * 
 *  Need interface and function separating
 * 
 * 
 */
 
 
 
double multiply();

double divide();

double add();

double subtract();

double intercept();

double threevector();

double rootsOfQuadratic();

int  algorithms();

#endif
