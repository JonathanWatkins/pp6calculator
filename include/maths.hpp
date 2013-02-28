#ifndef CALC_MATHS_HPP
#define CALC_MATHS_HPP

#include <iostream>
#include <string.h>

int swap(double& a, double& b);

int swap(int& a, int& b);

int indexedBubbleSort(int *a, int *index, int n);

int indexedBubbleSort(double *a, int *index, int n);

int bubbleSort(double* a, int* index, int n, bool showsteps);

int bubbleSort(int* a, int* index, int n, bool showsteps);

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
