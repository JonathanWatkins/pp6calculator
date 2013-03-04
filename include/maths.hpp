#ifndef CALC_MATHS_HPP
#define CALC_MATHS_HPP

#include <iostream>
#include <string.h>
#include <iomanip>


template<typename typeA>
int swap(typeA& a, typeA& b);

//int swap(double& a, double& b);

//int swap(int& a, int& b);

template<typename typeA>
int indexedBubbleSort(typeA *a, int *index, int n);

//int indexedBubbleSort(int *a, int *index, int n);

//int indexedBubbleSort(double *a, int *index, int n);


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


//int bubbleSort(double* a, int* index, int n, bool showsteps);

//int bubbleSort(int* a, int* index, int n, bool showsteps);

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

#endif
