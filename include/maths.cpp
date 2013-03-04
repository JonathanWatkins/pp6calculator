#include "maths.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include "input.hpp"

template<typename typeA>
int swap(typeA& a, typeA& b) {
//int swap(double& a, double& b) {
		
	typeA tmp = a;
	
	a=b;
	b=tmp;
	
	return 0;
	
}

/*int swap(int& a, int& b) {
	
	int tmp = a;
	a=b;
	b=tmp;
	
	return 0;
	
}
*/


/*int bubbleSort(double* a, int *index, int n, bool showsteps) {

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
				std::cout << std::setprecision(3) << std::setw(5) << a[i];
		
			}
			std::cout << std::endl;
			
			for (int i = 0; i<=n-1;i++) {
				std::cout << std::setprecision(3) << std::setw(5) << index[i];
		
			}
			std::cout << std::endl;
			
		}
		
		
	}
	while (true==switched);

	return 0;
}
*/

/*-----------------------------------------
 * 
 * Here are the interfaces for the maths functions
 * 
 */
 
 double swapInterface(std::string &fail){
	
	std::stringstream failstream;
	double a=get_double("");
	double b=get_double("");
	
	if(swap(a,b)) {
		failstream << "swap() function returned an error";
		fail= failstream.str();
		return 1;
	}
	
	std::cout << "a = " << a << std::endl << "b = " << b << std::endl; 
	
	return 0;
}


/*int indexedBubbleSort(int *a, int *index, int n) {
	
	int *rank = new int[(int)n];
	int *start = new int[(int)n];

	
	for (int i = 0; i<=n-1;i++) {
		start[i]=a[i];
		index[i]=(int)n-1-i;
			
	}
	
	std::cout << "Starting Order" << std::endl;
		
	
	for (int i = 0; i<=n-1;i++) {
		std::cout << std::setw(5) << a[i];
		
	}
	std::cout << std::endl;
	
	
	
	std::cout << std::endl;
	
	bubbleSort(a,index,(int)n,true);
	
	std::cout << "Final order" << std::endl;
	
	for (int i = 0; i<=n-1;i++) {
		std::cout << std::setw(5) << a[i];
		
	}
	std::cout << std::endl;
	
	
	//reverse sort to find rank in orginal order
	
	for (int i=0;i<=n-1;i++) {  // set ranks
		rank[i]=i;	
	}
	
	
	bubbleSort(index,rank,(int)n, false);
	std::cout << "Rank" << std::endl;
	for (int i = 0; i<=n-1;i++) {
		std::cout << std::setw(5) << start[i];
		
	}
	std::cout << std::endl;
	for (int i = 0; i<=n-1;i++) {
		index[i]=rank[i];
		std::cout << std::setw(5) << index[i];
		
	}
	std::cout << std::endl;
	
	
	
	
	delete [] rank;
	delete [] start;
	
	return 0;
}*/

template<typename typeA>
int indexedBubbleSort(typeA *a, int *index, int n) {
	
	int *rank = new int[(int)n];
	typeA *start = new typeA[(int)n];

	
	for (int i = 0; i<=n-1;i++) {
		start[i]=a[i];
		index[i]=(int)n-1-i;
			
	}
	
	std::cout << "Starting Order" << std::endl;
		
	
	for (int i = 0; i<=n-1;i++) {
		std::cout << std::setw(5) << a[i];
		
	}
	std::cout << std::endl;
	
	
	
	std::cout << std::endl;
	
	bubbleSort(a,index,(int)n,true);
	
	std::cout << "Final order" << std::endl;
	
	for (int i = 0; i<=n-1;i++) {
		std::cout << std::setw(5) << a[i];
		
	}
	std::cout << std::endl;
	
	
	//reverse sort to find rank in orginal order
	
	for (int i=0;i<=n-1;i++) {  // set ranks
		rank[i]=i;	
	}
	
	
	bubbleSort(index,rank,(int)n, false);
	std::cout << "Rank" << std::endl;
	for (int i = 0; i<=n-1;i++) {
		std::cout << std::setw(5) << start[i];
		
	}
	std::cout << std::endl;
	for (int i = 0; i<=n-1;i++) {
		index[i]=rank[i];
		std::cout << std::setw(5) << index[i];
		
	}
	std::cout << std::endl;
	
	
	
	
	delete [] rank;
	delete [] start;
	
	return 0;
}

double bubbleSortInterface(std::string &fail) {
	
	std::cout << "We will create an array with up to 10 random numbers. " ;
	
	double n;
	do
	{
		n=get_double("What size N would you like ?: ");
	
		if (floor(n)!=n) std::cout << "This is not an integer you plank. Please enter a different number!\n";
	}
	while (floor(n)!=n);
	
	
	int *a = new int[(int)n];
	int *index = new int[(int)n];

	
	for (int i = 0; i<=n-1;i++) {
		a[i]=rand()%100;	
	}
	indexedBubbleSort(a,index,(int)n);
	
	delete [] a;
	delete [] index;
	
	return 0;
	
	
}



/*---------------------------------
 * 
 * Need interface and function separating
 * 
 */
 
 
/* 
 
double multiply(){
	
	stringstream oss;
	
	double a= get_double("");
	double b=get_double("");
	oss << a << " * " << b << " = " << a*b;
	cout << oss.str();
	
	return 0;
	
}

double divide(){

	stringstream oss;
	
	double a= get_double("");
	double b;
	do
	{
			b=get_double("");
		if (0==b) cout << "This would give a divide by zero error. Please enter a different number!\n";
	} while (0==b);
	oss << a << " / " << b << " = " << a/b;
	cout << oss.str();
	
}

double add(){

	stringstream oss;
	
	double a= get_double("");
	double b=get_double("");
	oss << a << " + " << b << " = " << a+b;
	
	cout << oss.str();
}

double subtract(){

	stringstream oss;
	
	double a= get_double("");
	double b=get_double("");
	oss << a << " - " << b << " = " << a-b;
	
	cout << oss.str();
	
}

double intercept(){

	stringstream oss;
	
	
	double m= get_double("m = ");
	
	double c=get_double("c = ");
	
	oss << "The intercept of the line with the x axis is " << (0-c)/m;
	
	cout << oss.str();
	
	return 0;
	
}

double threevector() {
	
	stringstream oss;
	
	double a= get_double("Component 1: ");
	double b= get_double("Component 2: ");
	double c= get_double("Component 3: ");
	
	oss << "The length of the vector is : " << sqrt(a*a+b*b+c*c);
	
	cout << oss.str();
	
	return 0;
	
	
	
}

double rootsOfQuadratic() {
	
		stringstream oss;
	
		cout << "A quadratic is defined as ax^2 + bx + c = 0" << endl;
		cout << "Enter the coefficients" << endl;
		double a;
		do
		{
			a = get_double("a=");
			if (0==a) cout << "a=0 does not define a quadratic. Please enter a different number!" << endl;
		}
		while (0==a);
		double b= get_double("b=");
		double c= get_double("c=");
		cout << a << endl;
		cout << b << endl;
		cout << c << endl;
    
    double discriminant=b*b-4.0*a*c;
    oss << "The discriminant is " << discriminant << endl;
    if (discriminant>0) {  //   Real
        oss << "The roots are real" << endl;
        oss << "The roots are x = " << (-b+sqrt(discriminant))/2.0/a
            << " and x = " << (-b-sqrt(discriminant))/2.0/a << endl;
        
    }
    else if (0==discriminant) { // Single root
        oss << "There is a single root" << endl;
        oss << "The root is x = " << -b/2.0/a << endl;
            
        
        
    }
    else if (discriminant<0) {  // Complex
        oss << "The roots are complex" << endl;
        oss << "The roots are x = ";
        if (0!=-b/2.0/a) oss << -b/2.0/a << " ";
        oss << "+ i" << sqrt(-discriminant)/2.0/a
        << " and x = ";
        if (0!=-b/2.0/a) oss << -b/2.0/a << " ";
        oss << "- i" << sqrt(-discriminant)/2.0/a << endl;
        
    
    }
    
    cout << oss.str();
    
    return 0;
    
} 
*/
