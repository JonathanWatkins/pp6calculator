#include "maths.hpp"
#include <iostream>
#include <iomanip>


int swap(double& a, double& b) {
	
	double tmp = a;
	a=b;
	b=tmp;
	
	return 0;
	
}

int swap(int& a, int& b) {
	
	int tmp = a;
	a=b;
	b=tmp;
	
	return 0;
	
}

double bubbleSort(int* a, int n) {

	bool switched = false;
	do
	{
		switched=false;	
		for (int i=0;i<=n-2;i++) {
			if (a[i]<a[i+1]) {
				swap(a[i],a[i+1]);
				switched=true;
			}
		}
	
		for (int i = 0; i<=n-1;i++) {
			std::cout << std::setw(5) << a[i];
		
		}
		std::cout << std::endl;
		
	}
	while (true==switched);


}
