//  CPSC 121 – Intro to Programming
//  assignment: Exercise 2 Saleschart.cpp
//  due-date: March 10
//  author: Matthew Tea
//  partners: N/A
//  brief: To establish a program that requires user input of sales. The program then takes the sales and turns it into the amount of stars.  The prints the data in respect to the amount of stars.
//         This data is saved on a text file.

#include <iostream> // Initial Library declarations.
#include <fstream>
#include <iomanip>
using namespace std;
void print(double c, double v, double b);			// Void Prototype
int main()											// Start of Int main.
{

	ofstream saleschart;							//Declaration of File
	saleschart.open ("saleschart.txt");				//Opening of File
	double sales1, sales2, sales3;					//Declaration of Variables
	int stars1, stars2, stars3;
	if (saleschart) // Filecheck
	{
	do												// Do while loop to process the input of the sales amounts, It also ensures that the sales are not negative.
	{
	cout << "Enter the Positive number for Daily Sales for Store: ";		// Plain text.
	cin >> sales1;													// cin of Sales
	}
	while (sales1<0);												// Limiting conditions

	do												// Do while loop to process the input of the sales amounts, It also ensures that the sales are not negative.
	{
	cout << "Enter the Positive number for Daily Sales for Store: ";		// Plain text.
	cin >> sales2;													// cin of Sales
	}
	while (sales2<0);												// Limiting conditions

	do												// Do while loop to process the input of the sales amounts, It also ensures that the sales are not negative.
	{
	cout << "Enter the Positive number for Daily Sales for Store: ";		// Plain text.
	cin >> sales3;													// cin of Sales
	}
	while (sales3<0);												// Limiting conditions

	stars1 = (int) sales1/100;															// conversion of the sale amounts into stars. (100-1 ratio)
	stars2 = (int) sales2/100;															// conversion of the sale amounts into stars. (100-1 ratio)
	stars3 = (int) sales3/100;															// conversion of the sale amounts into stars. (100-1 ratio)

	//----------------------------------------------------------------------------------Beginning of Text file.
	saleschart << "DAILY SALES CHART" << endl;					// Prints plain text to the text file.
	
	saleschart << "Store1" << setw(5) <<"$"<< sales1;													// Prints plain text to the text file.

	saleschart << endl << "Store2"<< setw(5) <<"$"<< sales2;											// Prints plain text to the text file.

	saleschart << endl << "Store3"<< setw(5) <<"$"<< sales3;											// Prints plain text to the text file.

	saleschart.close();
	//----------------------------------------------------------------------------------End of Text file.
	print(stars1,stars2,stars3);														// Prints plain text to command prompt.
	}
	else
	{
		cout << "FAIL" << endl;
	}
	system ("Pause"); //Pauses the program to prevent command prompt from auto closing.

	return 0; // End Of program.
}

void print(double c, double v, double b)												// Void function that prints the same thing printed to the text file to the command prompt
{
	cout << "DAILY SALES CHART (each * represents $100)" << endl;						// Prints plain text to the text file.
	
	cout << "Store1" << setw(5);														// Prints plain text to the text file.

	for (int x=0; x<c; x++)																// Prints stars to the text file depending on the prior amounts inputted.
		cout << "*";

	cout << endl << "Store2"<< setw(5);													// Prints plain text to the text file.

	for (int x=0; x<v; x++)																// Prints stars to the text file depending on the prior amounts inputted.
		cout << "*";

	cout << endl << "Store3"<< setw(5);													// Prints plain text to the text file.

	for (int x=0; x<b; x++)																// Prints stars to the text file depending on the prior amounts inputted.
		cout << "*";

	cout << endl;																		// Creates an empty line for Formatting.
}