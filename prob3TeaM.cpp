//3. Write a recursive function called recurseprint that takes the front pointer to a linked list of nodes and any other parameter you wish to pass in to print every other value
//(i.e., the 1st value, 3rd value, 5th value, …) in the linked list beginning from the front.
//If this recurseprint function was called at the end of your program in problem 2, it should print out :
//3 0
//(i.e., only the first and third number from the four nodes are printed out).


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

void recurseprint(node *head, int number)
{
	if (head != NULL)
	{
		if (number % 2 == 0)
		{
			cout << head->info << " ";
		}
		recurseprint(head->next, number + 1);
	}
}

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

	cout << "Printing Every Other Value: " << endl;

	recurseprint(head, 0);

	cout << endl;

	return 0;
}