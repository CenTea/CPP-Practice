//2. Write a complete C++ program that does the following :
//
//The program then reads integers from the keyboard, and as long as the integers are positive or zero, the program inserts a new node holding that integer at the rear of a linked list.
//When a negative integer is entered, the program should print out all the integers in the linked list from front to back.Note that this should write the numbers in the order in which the numbers were entered by the user.

// Matthew Tea
// 893634899

#include <iostream>

using namespace std;

struct node
{
	int info;
	node *next;

	node()
	{
		info = 0;
		next = NULL;
	}
};

int main()
{
	node *head = NULL;
	node *rear = NULL;
	node *temp = NULL;
	int input=0;

	cout << "Please enter integers to be put into a linked list." << endl;
	cout << "Type a negative number to stop." << endl;
	do
	{
		cin >> input;

		if (input >= 0 && head == NULL)
		{
			head = new node;
			head->info = input;
			rear = head;
		}
		else if (input >= 0)
		{
			temp = new node;
			temp->info = input;
			rear->next = temp;
			rear = temp;
		}
	} while (input >= 0);

	cout << "Numbers in the linked list:" << endl;
	temp = head;
	while (temp != NULL)
	{
		cout << temp->info << endl;
		temp = temp->next;
	}

	return 0;
}