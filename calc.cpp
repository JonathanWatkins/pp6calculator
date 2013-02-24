/* This is the pp6calculator written by Jonathan Watkins
 * 
 * Current features are
 * 		- Addition
 * 		- Subtraction
 * 		- Multiplication
 * 		- Division
 * 		- Roots of a quadratic
 * 		- Length of a 3-vector
 * 		- Calculation of ds^2
 * 		- Calculation of the invariant mass
 * 		
 * 
 * 		Note: stringstreams are implemented for future use cases. 
 * 					The function results are written to a streamstream and may be
 * 					returned to the main loop rather than being immediately output
 * 					to screen. 
 */ 

#include <iostream>
#include <sstream>
#include <string.h>
#include <climits>
#include <cmath>

using namespace std;


double get_double (string question) {
	if (question.empty()) {
	 question="Enter number: ";
	}
	
	// Add error checking
	double a;
	cout << question;
	
	while (!(cin >> a)) {
		cin.clear();
		cin.ignore(INT_MAX,'\n');
		cout << question;
		
	};
    return a;
}

double multiply(){
	
	stringstream oss;
	
	double a= get_double("");
	double b=get_double("");
	oss << a << " * " << b << " = " << a*b;
	cout << oss.str();
	
	
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
	
}

double threevector() {
	
	stringstream oss;
	
	double a= get_double("Component 1: ");
	double b= get_double("Component 2: ");
	double c= get_double("Component 3: ");
	
	oss << "The length of the vector is : " << sqrt(a*a+b*b+c*c);
	
	cout << oss.str();
	
}

double fourvector() {
	
	stringstream oss;
	
	double ct=get_double("ct: ");
	double x= get_double("x: ");
	double y= get_double("y: ");
	double z= get_double("z: ");
	
	double dr2=x*x+y*y+z*z;
	double ct2=ct*ct;
	if (ct2>dr2) {
		oss << "The interval is time-like and events are casually related." << endl;
	} else if (ct2==dr2) {
		oss << "The interval is light-like and events are casually related." << endl;
	} else if (ct2<dr2) {
		oss << "The interval is space-like and events lie outside each others light cone." << endl;
	}
	
	oss << "The space-time interval is ds^2 = " << ct*ct-x*x-y*y-z*z;
	
	cout << oss.str();
	
}

double invariantMass() {
	
	stringstream oss;
	
	cout << "The Energy-momentum relation is defined as" << endl
	<< "    E^2 = (pc)^2 + (m0 c^2)^2" << endl
	<< "where p= gamma(u) m u and p= |p|" << endl
	<< "From this definition the invariant mass is calculated as " << endl
	<< "    m0^2 c^2 = (E/c)^2 - |p|^2  or m0^2=E^2-|p|^2 if c=1" << endl
	<< "Note: E and p are measured differently depending on the observers frame." << endl << endl;  
	double E= get_double("E: ");
	double px= get_double("px: ");
	double py= get_double("py: ");
	double pz= get_double("pz: ");
	
	oss << "The invariant mass squared is m0^2 = " << E*E - px*px - py*py - pz*pz << endl;
	
	cout << oss.str();
	
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
    
}


int main() {
	
	char operation[1];
	
	stringstream optionsOss;
	
	// The following defines the menu choices
	// New choices must be added to if and while loops below
	
	optionsOss << "\nWhat operation do you want to perform ?" << endl;
	optionsOss 	<< "------------------------------------------\n"
							<< "'+' Addition\n"
							<< "'-' Subtraction\n"
							<< "'*' Multiplication\n"
							<< "'/' Division\n"
							<< "'i' Interception of a line with the x-axis\n"
							<< "'q' Solve a quadratic\n"
							<< "'3' Length of a vector\n"
							<< "'4' ds^2 of a 4-vector\n"
							<< "'m' Invariant mass\n"
							<< "'x' to exit" << endl;
		
	
	do
	{
		
		// Display the menu
		cout << optionsOss.str();
		
		
		do
		{
			
			cin >> operation;
			
			if (( *operation!='+' && *operation!='-' && *operation!='*' && *operation!='/'  && *operation!='x' && *operation!='i' && *operation!='3' && *operation!='4' && *operation!='m' && *operation!='q')) {
				cin.clear();
				cin.ignore();
				cout << "\nThis is not a valid choice!  Please choose again." << endl; 
				cout << optionsOss.str();
			} else {
			
				cout << "You have chosen " << operation << endl;
			}
	
		}
		while ( *operation!='+' && *operation!='-' && *operation!='*' && *operation!='/' && *operation!='x' && *operation!='i' && *operation!='3' && *operation!='4' && *operation!='m' && *operation!='q');
		
		if (*operation!='x') {
			
			
			// If exit is not chosen run the requested function
			if (*operation=='+') {
				add();
			} else if (*operation=='-') {
				subtract();	
			} else if (*operation=='*') {
				multiply();
			} else if (*operation=='/') {
				divide();
			} else if (*operation=='i') {
				intercept();
			} else if (*operation=='3') {
				threevector();
			} else if (*operation=='4') {
				fourvector();
			} else if (*operation=='m') {
				invariantMass();
			} else if (*operation=='q') {
				rootsOfQuadratic();
			}
			
			cout << "\n\n";
			
		}
		
	}
	while (*operation!='x');
	
	cout << "Goodbye!" << endl;
	
	return 0;
}


