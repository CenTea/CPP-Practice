//  CPSC 121 – Intro to Programming
//  assignment: Assignment #5 Dynamic Memory Allocation - TestScores.Cpp
//  due-date: April 28
//  author: Matthew Tea
//  partners: N/A
//  brief: Develop a class that uses Pointers on Dynamic Memory and modify the data in pointer notation instead of array notation.
//         

#include <iostream> // initial declarations
using namespace std;

class Testscores // Delcaration of Class
{
private:
	int *ptr; // Pointer Integer
	int size; // Size of the Array
public:
	void getsize(); // Prototypes for Various Uses.
	double scoreaverage();
	void setscore();

	void sortArray(); // Prototype for the Book Algorithms
	void showArray();

	~Testscores() // Clearing the Variable.
	{delete ptr;}
};

int main() // Beginning of Main
{
	Testscores x; // Declaration of an Object

	x.getsize(); // Sets the Size of the Array

	x.setscore(); // Allows for input of the scores.

	x.sortArray();// Sorts the Scores in ascending order.

	x.showArray(); // Displays the Array
	
	cout << "Average is: " << x.scoreaverage() << endl; // Displays the Average

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