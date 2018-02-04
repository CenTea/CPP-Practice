//  CPSC 121 – Programming Concepts
//  assignment: Assignment #6 Rational Overloading. Rational.cpp
//  due-date: May 2
//  author: Matthew Tea
//  partners:N/A
//  brief: Overload a bunch of operators to demonstrate understanding.


#include <iostream> // Include

using namespace std; // Namespace

class Rational // Beginning of class
{
private:
   int numerator, denominator;
public:
	friend ostream &operator<<(ostream &output, Rational &obj); // Overload prototypes
	friend Rational operator+(Rational &obj, Rational &obj2);
	friend Rational operator-(Rational &obj, Rational &obj2);
	friend Rational operator*(Rational &obj, Rational &obj2);
	friend Rational operator/(Rational &obj, Rational &obj2);
	Rational &operator-() // Unary overload
	{
		numerator = -numerator;
		return *this;
	}
	// Constructor builds a rational number n/d
   Rational(int n, int d):numerator(n), denominator(d)
   {    
      reduce();
   }
private:
   // This member function transforms a rational number into 
   // reduced form where the numerator and denominator have 1
   // as greatest common factor
   void reduce();  
  

};

ostream &operator<<(ostream &output, Rational &obj) // Output overload, Uses a "N/D" format.
{
	output << obj.numerator << '/' << obj.denominator << endl;
	return output;
}


//************************************************************
// This member function transforms a rational number into    *
// reduced form where the numerator and denominator have 1   *
// as greatest common factor.                                *
//************************************************************
void Rational::reduce()
{
    bool negative = (numerator < 0) != (denominator < 0);
    numerator = abs(numerator);
    denominator = abs(denominator);

    int factor = 2;
    while (factor <= min(numerator, denominator))
    {
       if (numerator % factor == 0 && denominator % factor == 0)
       {
           numerator = numerator / factor;
           denominator = denominator / factor;
           continue;
       }
       factor ++;
    }
    if (negative) 
       numerator = - numerator;
}

int main() // Main function
{
	int num, den; // Declarations
	int num2, den2;
	Rational result(0,0);
	char symbol;

	cout << "Enter Numerator for Fraction 1: "; // Inputs for Data
	cin >> num;
	cout << "Enter Denominator for Fraction 1: ";
	cin >> den;
	Rational x(num,den); // Construction of the first Fraction
	cout << "Enter Numerator for Fraction 1: "; // More inputs
	cin >> num2;
	cout << "Enter Denominator for Fraction 2: ";
	cin >> den2;
	Rational y(num2, den2); // Construction of the 2nd fraction

	do // Validation input
	{
	cout << "Enter the Operation: "; // Input of Operation
	cin >> symbol;
	
	if (symbol == '+') // Checks for symbol and does operation accordingly
	{
		result = x+y;
		cout << result;
	}

	else if (symbol == '-')
	{
		result = x-y;
		cout << result;
	}
	else if (symbol == '*')
	{
		result = x*y;
		cout << result;
	}
	else if (symbol == '/')
	{
		result = x/y;
		cout << result;
	}
	else
	{
		cout << "Invalid, Enter a Valid operation symbol (+,-,*,/)" << endl;
	}

	} while(symbol!='+'&&symbol!='-'&&symbol!='*'&&symbol!='/');

	cout << "Unary test: " << -result << endl; // Unary overload

	system("PAUSE");
	return 0; // End of Program
}

	Rational operator+(Rational &obj, Rational &obj2) // Plus overload
	{
		Rational x((obj.numerator*obj2.denominator) + (obj2.numerator*obj.denominator),obj.denominator*obj2.denominator); // Creats an object that stores the values and reduces it
		return x;
	}
	Rational operator-(Rational &obj, Rational &obj2) // Minus overload
	{
		Rational x((obj.numerator*obj2.denominator) - (obj2.numerator*obj.denominator),obj.denominator*obj2.denominator);// Creats an object that stores the values and reduces it
		return x;
	}
	Rational operator*(Rational &obj, Rational &obj2) // Multiply overload
	{
		Rational x(obj.numerator * obj2.numerator,obj.denominator * obj2.denominator);// Creats an object that stores the values and reduces it
		return x;
	}
	Rational operator/(Rational &obj, Rational &obj2) // Divide overload
	{
		Rational x(obj.numerator * obj2.denominator,obj.denominator * obj2.numerator);// Creats an object that stores the values and reduces it
		return x;
	}