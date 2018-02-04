//1.  Write a complete C++ program to calculate the two largest numbers in a set of quiz scores.Specifically, the program should do the following :
//
//The program asks for and reads in N, the total number of students taking the quiz.The program will then prompt the user and reads in the N quiz scores into an array called scores.
//The main program calls a function called largest that takes the array scores and the number N, and returns the largest of the N scores.
//The main program uses the result to print the largest score.
//The main program then calls a function secondlargest that also takes the array scores and N and any other parameter you wish to pass in.
//The function second largest will return the second largest of the scores. The main program uses this result to print the second largest score.
//
//For full credit, your program should handle the case where there are two or more students with the highest score.
//In this case, both the largest and second largest score will be the same.
//
//Please write and use the functions described above!Note that both functions largest and secondlargest return a value.
//
//Assumptions you may make to simplify coding :
//•	The number of quiz scores(N) will not be larger than 100.
//•	The quiz scores will be integers.
//•	All quiz scores are integers in the range from 0 to 100, inclusive.
//
//Your program should be a single.cpp file.Name your program prob1YourLastNameFirstInitial.cpp where YourLastNameFirstInitial is replaced by your last name followed by your first name initial.Turn it in to the Final Problem 1 on the CPSC 301 Titanium site.Put in your name at the start of the file as a comment.

// Matthew Tea
// 893634899

#include <iostream>

using namespace std;

int largest(int a[], int len)
{
	int largestNum = 0;

	for (int i = 0; i < len; i++)
	{
		if (a[i]>largestNum)
		{
			largestNum = a[i];
		}
	}
	return largestNum;
}

int secondLargest(int a[], int len, int largest)
{
	int second = 0;
	bool largestfound = false;
	for (int i = 0; i < len; i++)
	{
		if (a[i]>second)
		{
			if (a[i] == largest && largestfound == false)
			{
				largestfound = true;
			}
			else
			{
				second = a[i];
			}
		}
	}
	return second;
}

int main()
{
	int studentNum;
	int *scores;
	cout << "Please input the number of students: ";
	cin >> studentNum;
	scores = new int[studentNum];

	cout << "Please input the Score Values: " << endl;
	for (int i = 0; i < studentNum; i++)
	{
		cin >> scores[i];
	}

	cout << "The largest score is: " << largest(scores, studentNum) << endl;
	cout << "The second score is: " << secondLargest(scores, studentNum, largest(scores, studentNum)) << endl;

	return 0;
}