/*
	Application Author: Dan Barlow
	Application Name VariablesConstantsOutputDemo.cpp
	Date Created: May 16, 2016
	
	Description: A simple application to show the declaration and initialization of basic variables and constants.
	The application then embeds those values in a concatenated string of output.
*/

#include <iostream>

using namespace std;

int main()
{
	int myAge = 6;					//variable to hold a value representing my age
	const char MY_GENDER = 'F';		//Constant to hold a value representing my gender
	double myHeight = 92.5;			//variable to hold a value representing my height
	
	/*************
	   OUTPUT
	**************/
	cout << "Age: " << myAge 
		 << "\nGender: " << MY_GENDER 
		 << "\nHeight: " << myHeight << "\"" << endl;  //note the escape character which allows me to have double quotes in my output
	
	
	//pause execution and exit on any key press
	system("pause");
	return 0;
}
