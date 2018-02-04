//  CPSC 121 – Intro to Programming
//  assignment: Assignment #4 Working with classes - What_date.cpp
//  due-date: April 7
//  author: Matthew Tea
//  partners: N/A
//  brief: Develop a class that uses constructors and allows for its functions to print the date with or without aruguments.
//         

#include <iostream> // Initial Library declarations.
#include <iomanip>
using namespace std;

class date // start of the class date
{
private:			// Private variables
	int day;
	int month;
	int year;
public:			// public functions and constructors
	date(int, int, int); // constructor with params
	date();// default constructor.

	void monthdayyearnum(); // class functions
	void monthdayyeartext();
	void daymonthyear();
	void numtotext();
};

int main() // start of int main
{
	date defValue; // initialization of the Date datatypes using a default, initial declaration and an error.
	date today(6,4,2014);
//	date err(31,2,2014); // values to test in  (D,M,Y) format

	cout << "Using Default Values: " << endl << endl; // output of the Default value

	defValue.monthdayyearnum(); // the three print types
	defValue.monthdayyeartext();
	defValue.daymonthyear();

	cout << endl << "Using set Values: " << endl << endl; // output of the set values

	today.monthdayyearnum();// the three print types
	today.monthdayyeartext();
	today.daymonthyear();

//	cout << endl << "Using set err Values: " << endl << endl; // output of an error

//	err.monthdayyearnum();// the three print types
//	err.monthdayyeartext();
//	err.daymonthyear();

	cout << endl; // formatting

	system("PAUSE");
	return 0; // end of main
}

date::date() // default constructor
{
	day = 1;
	month =1;
	year = 2001;
}

date::date(int x, int y, int z) // Constructor that takes values
{
	if (((y%2==1&&(x>31||x<1))||(y%2==0&&(x>30||x<1))||(y==2&&(x>28||x<1)))&&(y>12||y<1)) // If the Month and day is invalid, they are set to default (1)
	{
		day = 1;
		month = 1;
		year = z;
	}
	else if (y>12||y<1)  // if the just the month is invalid, it is set to default (1)
	{
		day = x;
		month = 1;
		year = z;
	}
	else if ((y%2==1&&(x>31||x<1))||(y%2==0&&(x>30||x<1))||(y==2&&(x>28||x<1)))// if only the day is invalid that is set to default (1)
	{
		day = 1;
		month = y;
		year = z;
	}
	 else // if there are no problems all the variables are set
	{
		day = x;
		month = y;
		year = z;
	}
}

void date::monthdayyearnum() // Print method 1 (M/D/Y)
{
	cout << month << "/" << day << "/" << year << endl;
}

void date::monthdayyeartext() // print method 2 (Month D, Y)
{
	numtotext();
	cout << " " << day << ", " << year << endl;
}

void date::daymonthyear() // print method 3 (D Month Y)
{
	cout << day << " ";
	numtotext();
	cout << " " << year << endl;
}

void date::numtotext() // an extra function to change the numerical month to text.
{
	switch(month)
	{
	case 1: cout << "January";break;
	case 2: cout << "February";break;
	case 3: cout << "March";break;
	case 4: cout << "April";break;
	case 5: cout << "May";break;
	case 6: cout << "June";break;
	case 7: cout << "July";break;
	case 8: cout << "August";break;
	case 9: cout << "September";break;
	case 10: cout << "October";break;
	case 11: cout << "November";break;
	case 12: cout << "December";break;
	}
}