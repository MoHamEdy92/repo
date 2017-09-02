//  -------------------------------------------------------------
//  Question 6:   Write a program
//  -------------------------------------------------------------
/****************************************************************
Write a complete C++ program that display message to indicate the 
single input character is belong to alphabetic character (a-z or 
A-Z), a digit (0-9) or special character (anything else). 

Sample Run 1:
Enter a character: 5
--> numeric

Sample Run 2:
Enter a character: m
--> alphabetic

Sample Run 3:
Enter a character: !
--> special
****************************************************************/

#include <iostream>
using namespace std;

int main()
{
	char character;
	cout << "Enter a character: ";
	cin >> character;
	cout << "--> ";
	
	if ((character >= 'a' && character <='z') || (character >= 'A' && character <= 'Z'))
	{
		cout << "alphabetic" << endl;
	}
	
	else
	{
		if (character >= '0' && character <= '9')
		{
			cout << "numeric" << endl;
		}
	
		else
		{
			cout << "special" << endl;
		}
	}
	
	return 0;
}
