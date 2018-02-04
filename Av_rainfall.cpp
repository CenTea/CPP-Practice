//  CPSC 121 – Intro to Programming
//  assignment: Exercise 1 Av_Rainfall.cpp
//  due-date: March 10
//  author: Matthew Tea
//  partners: N/A
//  brief: Take Info from a text file and display and modify it.

#include <iostream> // Initial Library declarations.
#include <fstream>
using namespace std;

int main()											// Start of Int main.
{

	ifstream rainfallfile;							//Declaration of file
	char month1[100], month2[100];					//Character array for Months
	double total=0;									//Total
	double num1, num2=0;		//Variables to store the numbers
	double average;									//Variable for the Average
	
	rainfallfile.open ("Rainfall.txt"); // Opens file
	if (rainfallfile) // file check
	{
	rainfallfile>>month1; //Collects
	cout << month1 << " ";
	rainfallfile>>month2; //Collects
	cout << month2 << endl;

	while (rainfallfile>>num1) // collects more data
	{
	cout << num1 << " "; // displays data
	total+=num1; // puts data into a sum
	num2+=1; // keeps track of numbers for the average
	}
	cout << endl; // formatting
	average=total/num2; // calculates average

	cout << "Total Rainfall: " << total << endl;  // Displays total rainfall

	cout << "Average Rainfall: " << average << endl << endl; // Displays average rainfall
	}
	else
	{
		cout << "FAIL" << endl; // file check fail
	}
	system("Pause"); //Prevents application from auto closing.

	return 0; // End Of program.
}