//  CPSC 121 – Intro to Programming
//  assignment: Assignment #6.1 Copy Constructors
//  due-date: April 28
//  author: Matthew Tea
//  partners: N/A
//  brief: Make Copies of both types. Over loaded and constructors.
//         

#include <iostream> // initial declarations
#include <string>
using namespace std;

class Testscores // Delcaration of Class
{
private:
	int *ptr; // Pointer Integer
	int size; // Size of the Array
	string name;
public:
	Testscores(string a)// Empty Constructor
	{name = a;}

	Testscores(string a, int x)// Size constuctor
	{name = a;size=x;}

	Testscores(Testscores &obj)//Copy Constructor
	{
		name = obj.name;
		size = obj.size;
		ptr=new int[size];
		for (int i=0; i<size; i++)
		{
		*(ptr+i) = *(obj.ptr+i);
		}
	}

	string displayname(){return name;}

	void getsize(); // Prototypes for Various Uses.
	double scoreaverage();
	void setscore();
	void sortArray(); // Prototype for the Book Algorithms
	void showArray();

	void print();// Displays the Average

	void operator=(Testscores &y) // Overloaded Operator
	{
		name = y.name;
		size = y.size;
		ptr=new int[size];
		for (int i=0; i<size; i++)
		{
		*(ptr+i) = *(y.ptr+i);
		}
	}

	~Testscores() // Clearing the Variable.
	{delete ptr;}
};


void reformat(bool x) // formatting purposes
{
	if (x==1)
		cout << "True" << endl;
	else
		cout << "False" << endl;
}

int main() // Beginning of Main
{
	Testscores x("Test Scores A"); // Declaration of an Object

	x.getsize(); // Sets the Size of the Array

	x.setscore(); // Allows for input of the scores.

	x.sortArray();// Sorts the Scores in ascending order.

	x.showArray(); // Displays the Array

	x.print();// Displays the Average

	cout << endl;
	Testscores g(x);// copy constructor

	//g.setscore(); //Used to Make sure they do not have the same Dynamic variable

	g.sortArray();

	g.showArray();

	g.print();

	cout << endl;
	Testscores y = x; // Overloaded Operator

	//y.setscore(); //Used to Make sure they do not have the same Dynamic variable

	y.sortArray();

	y.showArray();

	y.print();

	//x.sortArray();x.showArray(); x.print();g.sortArray(); g.showArray(); g.print();

	system ("PAUSE");
	return 0;
}

void Testscores::getsize() // Sets the Size of the Array.
{
	do
	{
	cout << "Enter the amount of scores(Must be positive): ";
	cin >> size;
	}while (size<=0); // Prevents the Array from being negative
	ptr=new int[size]; // Setting the Pointer to the New Array that is determined by Size.
}

double Testscores::scoreaverage() // Averages the Scores in the array.
{
	double temp=0; // Temp variable to hold the sum.
	for (int i=0; i<size; i++)
	{
		temp+= *(ptr+i); // For loop to add the numbers to the Temp variable.
	}
	return (temp/(double)size);// Returns the Temp Variable Divided by the Size of the Array Giving the Average.
}

void Testscores::setscore() // Allows for the User to Set the Values within the Array.
{
	
	//int temp=0;
	for (int i=0; i<size; i++)
	{
		do
		{
		cout << "Enter the #" << i+1 << " score(0-10): ";
		cin >> *(ptr+i);
		}while (*(ptr+i)<0||*(ptr+i)>10); // Prevents the User from placing a Value that isnt within the range of 0-10.
		//*(ptr+i)= temp;
	}
}

void Testscores::sortArray() // Sorts the Values of the Array
{
	int temp;
	bool swap;

	do
	{
		swap = false;
		for (int i = 0; i < (size-1); i++)
		{
			if (*(ptr+i) > *(ptr+i+1)) // Swaps values and sets Bool to true if the value of the first occuring array value is higher than the array value occuring after it.
			{
				temp = *(ptr+i);
				*(ptr+i)= *(ptr+i+1);
				*(ptr+i+1) = temp;
				swap = true;
			}
		}
	}
	while (swap);
}

void Testscores::showArray() // Prints out the Array in Ascending order.
{
	cout << "Scores in Ascending Order: ";
	for (int i = 0; i < size; i++)
		cout << *(ptr+i) << " ";
	cout << endl;
}

void Testscores::print()
{
	cout << "Average is: " << scoreaverage()<< " for " << displayname() << endl; // Displays the Average
}