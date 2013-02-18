#include <iostream>

using namespace std;

// Just a quick bit on passing using pointers
void f(int *a)
{
	int answer= *a *2;
	*a=answer;
	
	
}

int main() {
	
	int num1= 10;
	
	f(&num1);
	cout << num1 << endl;


	
	
	double a;
	double b;
	
	cout << "What operation do you want to perform ?" << endl;
	cout << "1)   +" << endl;
	cout << "2)   -" << endl;
	cout << "3)   *" << endl;
	cout << "4)   /" << endl;
	
	int operation;
	
	do
	{
		if (!(cin >> operation)){
			cout << "This is not a valid choice!  Please choose again." << endl; 
			cout << "What operation do you want to perform ?" << endl;
			cout << "1)   +" << endl;
			cout << "2)   -" << endl;
			cout << "3)   *" << endl;
			cout << "4)   /" << endl;
		}
	
	}
	while ( operation>=5 || operation <=0 );
	cout << "Enter a number: ";
	cin >> a;
	cout << endl;
	
	cout << "Enter a number: ";
	cin >> b;
	cout << endl << a << " + " << b << " = "  << a+b << endl;
	
	
	return 0;
}


