#include <iostream>
#include <sstream>
#include <string.h>
#include <climits>



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

}


void f(int *a)
{
	int answer= *a *2;
	*a=answer;
	
	
}

double multiply(){
	
	stringstream oss;
	
	double a= get_double(NULL);
	double b=get_double(NULL);
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
	optionsOss << "'+' '-' '*' '/' 'i' or 'q' to quit" << endl;
		
	
	do
	{
	
		cout << optionsOss.str();
		
		
		do
		{
			
			cin >> operation;
			
			if (( *operation!='+' && *operation!='-' && *operation!='*' && *operation!='/'  && *operation!='q' && *operation!='i')) {
				cin.clear();
				cin.ignore();
				cout << "\nThis is not a valid choice!  Please choose again." << endl; 
				cout << optionsOss.str();
			} else {
			
				cout << "You have chosen " << operation << endl;
			}
	
		}
		while ( *operation!='+' && *operation!='-' && *operation!='*' && *operation!='/' && *operation!='q' && *operation!='i');
		
		if (*operation!='q') {
			
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
			}
			
			
			cout << "\n\n";
			
		}
		
	}
	while (*operation!='q');
	
	
	return 0;
}


