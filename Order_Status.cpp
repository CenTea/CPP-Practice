//  CPSC 121 – Intro to Programming
//  assignment: Exercise 2 order_status.cpp
//  due-date: March 24
//  author: Matthew Tea
//  partners: N/A
//  brief: Gathers data with functions and uses it to modify and display it.

#include <iostream> // Initial Library declarations.
using namespace std;

void getOrderinfo(int &v1, int &v2, double &v3); // function prototype
void secondfunction(int srs, int sbo, double extra); //function prototype

int main()											// Start of Int main.
{
	int spoolsordered; //initial declaration
	int spoolstock; // initial declaration
	double shipping;//initial declaration

	getOrderinfo(spoolsordered,spoolstock,shipping); // function of getting the order info
	cout << endl;
	secondfunction(spoolsordered,spoolstock,shipping);// function of displaying information.

	system("Pause"); //Prevents application from auto closing.

	return 0; // End Of program.
}

void getOrderinfo(int &v1, int &v2, double &v3) // gets the amounts of spools ordered and in stock and extra charges.
{
	do // gets the amounts of spools ordered, makes sure its over 0
	{
	cout << "Enter the amount of spools ordered: ";
	cin >> v1;
	}while (v1<0);

	do // gets the amounts of spools in stock, makes sure its not negative.
	{
	cout << "Enter the number of spools in stock: ";
	cin >> v2;
	}while (v2<=0);

	do // adds any additional charges, makes sure it is not a negative number.
	{
	cout << "Any additional shipping and handling charges (above the $10 regular rate): $";
	cin >> v3;
	}while (v3<=0);
}

void secondfunction(int srs, int sbo, double extra) // second function that allows for a summary of information to be displayed.
{
	if (srs<sbo) // if less spools are ordered than available
	cout << "Spools ready to ship: " << srs << endl; // displays spools ready to ship.
	else // if more spools are ordered than available
	cout << "Spools ready to ship: " << sbo << endl; // displays spools ready to ship.
	if (srs>sbo) // if there are more spools ordered than available, a backorder will be made
	{
	cout << "Spools in Backorder: " << srs-sbo << endl; // if there are more ordered than available then this will display those on hold.
	}
	if (srs<sbo) // if less spools are ordered than available
	{
	cout << "Price of spools ready to ship: $" << ((srs)*100) << endl; // price of spools ready to ship.
	cout << "Total Shipping and Handling charges on portion ready to ship: $" << ((srs)*10) << endl; // shipping charges on spools raedy to ship
	cout << "Total of the Order ready to ship: $" << (double) (srs*100)+(srs*10)+extra << endl; // total cost of the order.
	}
	else// if more spools are ordered than available
	{
	cout << "Price of spools ready to ship: $" << ((sbo)*100) << endl; // price of spools ready to ship.
	cout << "Total Shipping and Handling charges on portion ready to ship: $" << ((sbo)*10) << endl; // shipping charges on spools raedy to ship
	cout << "Total of the Order ready to ship: $" << (double) (sbo*100)+(sbo*10)+extra << endl; // total cost of the order.
	}
}