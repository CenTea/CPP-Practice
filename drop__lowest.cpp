//  CPSC 121 – Intro to Programming
//  assignment: Exercise 1 drop_lowest.cpp
//  due-date: March 24
//  author: Matthew Tea
//  partners: N/A
//  brief: Take Info from a text file and display and modify it.

#include <iostream> // Initial Library declarations.
using namespace std;

void getscore(int &score); //Function Prototypes
void calcaverage(int score1,int score2,int score3,int score4,int score5); // Function Prototypes
int findlowest(int score1,int score2,int score3,int score4,int score5); // Function Protopyes

int main()											// Start of Int main.
{
	int test1,test2,test3,test4,test5;  // Initial Declarations of variables
	getscore(test1); // getting test score 1
	getscore(test2); // getting test score 2
	getscore(test3); // getting test score 3
	getscore(test4); // getting test score 4
	getscore(test5); // getting test score 5
	calcaverage(test1,test2,test3,test4,test5); // Getting and displaying the Average of the scores.
	
	//system("Pause"); //Prevents application from auto closing.

	return 0; // End Of program.
}

void getscore(int &score) // Function that allows input of scores.
{
	do //do while loop to check.
	{
		cout << "Enter a score from 0 to 100: "; // plain text
		cin >> score; // input of score
	}while (score>100||score<0); // checks if score is less than zero or greater than 100
}

void calcaverage(int score1,int score2,int score3,int score4,int score5) // function to calculate the average.
{
	switch (findlowest(score1,score2,score3,score4,score5)) // swtich statement using findlowest function
	{
	case 1:cout << "The average for the scores is " << (double) (score2+score3+score4+score5)/4 << endl;break; // using the returned value, score 1 is omitted.
	case 2:cout << "The average for the scores is " << (double) (score1+score3+score4+score5)/4 << endl;break; // using the returned value, score 2 is omitted.
	case 3:cout << "The average for the scores is " << (double) (score1+score2+score4+score5)/4 << endl;break; // using the returned value, score 3 is omitted.
	case 4:cout << "The average for the scores is " << (double) (score1+score2+score3+score5)/4 << endl;break; // using the returned value, score 4 is omitted.
	case 5:cout << "The average for the scores is " << (double) (score1+score2+score3+score4)/4 << endl;break; // using the returned value, score 5 is omitted.
	}
}

int findlowest(int score1,int score2,int score3,int score4,int score5) // function that finds the lowest score and returns a value to pick which one is omitted.
{
	if (score1<=score2&&score1<=score3&&score1<=score4&&score1<=score5) // score 1 is the lowest soo 1 is returned so the first score is omitted in the switch statement.
		return 1;
	else if (score2<=score1&&score2<=score3&&score2<=score4&&score2<=score5)// score 2 is the lowest soo 2 is returned so the second score is omitted in the switch statement.
		return 2;
	else if (score3<=score1&&score3<=score2&&score3<=score4&&score3<=score5)// score 3 is the lowest soo 3 is returned so the third score is omitted in the switch statement.
		return 3;
	else if (score4<=score1&&score4<=score2&&score4<=score3&&score4<=score5)// score 4 is the lowest soo 4 is returned so the fourth score is omitted in the switch statement.
		return 4;
	else if (score5<=score1&&score5<=score2&&score5<=score3&&score5<=score4)// score 5 is the lowest soo 5 is returned so the fifth score is omitted in the switch statement.
		return 5;
}