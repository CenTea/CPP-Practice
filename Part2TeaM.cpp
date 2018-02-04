// Matthew Tea
// 893634899

#include <iostream>
#include <string>

using namespace std;

struct animalnode // Animal Struct
{
	string name;
	int ID;
	int age;
	animalnode *next;

	animalnode()
	{
		name = "";
		ID = NULL;
		age = NULL;
		next = NULL;
	}
		string showname()
		{
			return name;
		}
		int showage()
		{
			return age;
		}
		int showid()
		{
			return ID;
		}
		void setID()
		{
			cout << "Set ID: ";
			cin >> ID;
		}
		void setName()
		{
			cout << "Set Name: ";
			cin >> name;
		}
		void setAge()
		{
			cout << "Set Age: ";
			cin >> age;
		}
};

int anichoice() // Assists in choosing an animal
{
	char animalident; // identifies animal based on char

	cout << "D: Dog - C: Cat - R: Rabbit" << endl;
	cout << "Please enter the type of animal: ";
	cin >> animalident;
    
	if (toupper(animalident) == 'D')
	{
		return 0;
	}
	else if (toupper(animalident) == 'C')
	{
		return 1;
	}
	else if (toupper(animalident) == 'R')
	{
		return 2;
	}
	else
	{
		cout << "Invalid option..." << endl;
		anichoice(); // redoes if error
	}
}

bool IDcheck(animalnode * head, int IDC, animalnode * origin) // checks for ID duplicates // Head is current of list, IDC is ID that is being checked, Origin is the head
{
	if (origin == NULL)
	{
		return true;
	}
	else if (head == origin)
	{
		return true;
	}
	else if (origin->ID == IDC && origin != head)
	{
		return false;
	}
	else
	{
		IDcheck(head, IDC, origin->next);
	}
}

void animalinsert(animalnode *& head, animalnode *& prev, int cagenum, int max, animalnode* origin) // Inserts an Animal to list // head is current, Origin is the head of the list, Cagenum is current cage, Max is the max of cages
{
	animalnode * Previous;
	Previous = head;

	if (cagenum == max)
	{
		cout << "The Adoption Center is full..." << endl;
	}
	else if (head == NULL)
	{
		head = new animalnode;
		if (prev != NULL)
		{
			prev->next = head;
		}
		head->setName();
		do
		{
			head->setID();
			if (IDcheck(head, head->ID, origin) == false)
			{
				cout << "ID already taken..." << endl;
			}
		}while (IDcheck(head, head->ID, origin) == false);
		head->setAge();
	}
	else
	{
		animalinsert(head->next, Previous,cagenum+1, max, origin);
	}
}

void animaladopt(animalnode *& head, animalnode *& prev, int FID) // Removes animal from list // head is current //prev is the previous // FID is the ID that needs to be found.
{
	animalnode *& Previous = head;
	if (head == NULL)
	{
		cout << "Animal cannot be found..." << endl;
	}
	else if (head->ID == FID)
	{
		cout << "Name: " << head->showname() << endl;
		cout << "ID: " << head->showid() << endl;
		cout << "Age: " << head->showage() << endl;

		if (prev != NULL) // Problems: Deleting the node is not properly working.
		{
			prev->next = head->next;
			delete head;
			head = NULL;
		}
		else if (prev == head) // Not functioning properly.
		{
			head = head->next;
			delete prev;
			prev = NULL;
		}
		

		cout << endl << "The Animal has been Adopted!" << endl;
	}
	else
	{
		animaladopt(head->next, Previous, FID);
	}
}
void printinfo(animalnode * critter) // Prints the list // critter is the current position.
{
	if (critter != NULL)
	{
		cout << "Name: " << critter->showname() << endl;
		cout << "ID: " << critter->showid() << endl;
		cout << "Age: " << critter->showage() << endl;
		cout << endl;
		printinfo(critter->next);
	}
}


int main() // Main
{
	int cages[3]; //maxnum of cages
	int IDsear; // ID search storage
	char menu; // Menu options
	animalnode *head[3]; //Heads of 3 different lists of animals
	animalnode *previous = NULL; // Previous filler
	string const creature[3] = { "Dogs", "Cats", "Rabbits" }; // Different animals

	for (int i = 0; i < 3; i++) // Creates Cage amount
	{
		cout << "Please input the number of cages for " << creature[i] << "." << endl;
		cin >> cages[i];
		head[i] = NULL;
	}

	do // Menu of the program
	{
		cout << "N:Intake\nA:Adopt\nP:Print\nQ:Quit\n";
		cin >> menu;
		previous = NULL;
		if (toupper(menu) == 'N')
		{
			switch (anichoice()) // Inserts based on animal
			{
			case 0:
				animalinsert(head[0], previous, 0, cages[0], head[0]);
				break;
			case 1:
				animalinsert(head[1], previous, 0, cages[1], head[1]);
				break;
			case 2:
				animalinsert(head[2], previous, 0, cages[2], head[2]);
				break;
			}
		}
		else if (toupper(menu) == 'A') // Adopts based on animal
		{
			cout << "Please choose an ID to search For: ";
			cin >> IDsear;
			switch (anichoice())
			{
			case 0:
				animaladopt(head[0], previous, IDsear);
				break;
			case 1:
				animaladopt(head[1], previous, IDsear);
				break;
			case 2:
				animaladopt(head[2], previous, IDsear);
				break;
			}
		}
		else if (toupper(menu) == 'P') // Prints everything
		{
			for (int i = 0; i < 3; i++)
			{
				cout << creature[i] << endl;
				printinfo(head[i]);
			}
		}
		else if (toupper(menu) != 'Q') // Error Check
		{
			cout << "Invalid Option, Please try again..." << endl;
		}
		
	} while (toupper(menu) != 'Q'); //end of program.




	return 0;
}