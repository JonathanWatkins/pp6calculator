#include <iostream>
#include <sstream>
#include <string.h>
#include <climits>
#include <cmath>

using namespace std;

// Just a quick bit on passing using pointerst

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


void f(int *a)
{
	int answer= *a *2;
	*a=answer;
	
	
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
	double b=get_double("");
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
	
	cout << "The invariant mass squared is m0^2 = " << E*E - px*px - py*py - pz*pz << endl;
	
	cout << oss.str();
	
}

double rootsOfQuadratic() {
	
    stringstream oss;
	
	cout << "A quadratic is defined as ax^2 + bx + c = 0" << endl;
    cout << "Enter the coefficients" << endl;
    double a= get_double("a=");
	double b= get_double("b=");
	double c= get_double("c=");
	cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    
    double discriminant=b*b-4.0*a*c;
    cout << "The discriminant is " << discriminant << endl;
    if (discriminant>0) {  //   Real
        cout << "The roots are real" << endl;
        cout << "The roots are x = " << (-b+sqrt(discriminant))/2.0/a
            << " and x = " << (-b-sqrt(discriminant))/2.0/a << endl;
        
    }
    else if (0==discriminant) { // Single root
        cout << "There is a single root" << endl;
        cout << "The root is x = " << -b/2.0/a << endl;
            
        
        
    }
    else if (discriminant<0) {  // Complex
        cout << "The roots are complex" << endl;
        cout << "The roots are x = ";
        if (0!=-b/2.0/a) cout << -b/2.0/a << " ";
        cout << "+ i" << sqrt(-discriminant)/2.0/a
        << " and x = ";
        if (0!=-b/2.0/a) cout << -b/2.0/a << " ";
        cout << "- i" << sqrt(-discriminant)/2.0/a << endl;
        
    
    }
    
}


int main() {
	
	int num1= 10;
	
	f(&num1);
	
	cout << num1 << endl;
	
	double a;
	double b;
	
	char operation[1];
	char ReturnStr[50];
	
	stringstream optionsOss;
	
	optionsOss << "What operation do you want to perform ?" << endl;
	optionsOss << "'+' '-' '*' '/' 'i' 'q'uadractic solve '3'-vector '4'-vector invariant 'm'ass or 'x' to exit" << endl;
		
	
	do
	{
	
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
			
			double answer;
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


