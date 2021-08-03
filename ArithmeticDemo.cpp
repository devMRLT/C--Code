/*
	Application Author: Dan Barlow
	Application Name ArthmeticDemo.cpp
	Date Created: May 16, 2016
	
	Description: A simple application to demonstrate basic arithmetic in C++.
*/

#include <iostream>

using namespace std;

int main()
{
	//constant declarations
	const int FIRST_NUMBER = 12;		//arbitrary integer to be used in basic arithmetic
	const int SECOND_NUMBER = 5;		//arbitrary integer to be used in basic arithmetic
	const float THIRD_NUMBER = 5.0f;	//arbitrary float to be used in basic arithmetic
	
	//variable declarations
	int additionResult = 0;				//used to store the result of addition
	int subtractionResult = 0;			//used to store the result of subtraction
	int multiplicationResult = 0;		//used to store the result of multiplication
	int divisionResult = 0;				//used to store the result of division
	int modulusResult = 0;				//used to store the result of modulus
	float mixedDivisionResult = 0.0f;	//used to demonstrate mixed mode division
	
	
	/***************
		PROCESSING
	***************/
	additionResult = FIRST_NUMBER + SECOND_NUMBER;	
	subtractionResult = FIRST_NUMBER - SECOND_NUMBER;	
	multiplicationResult = FIRST_NUMBER * SECOND_NUMBER;	
	divisionResult = FIRST_NUMBER / SECOND_NUMBER;	
	modulusResult = FIRST_NUMBER % SECOND_NUMBER;	
	mixedDivisionResult = FIRST_NUMBER / THIRD_NUMBER;
	
	
	/************
		OUTPUT
	*************/
	cout << "Addition result: " << additionResult 
		 << "\nSubtraction result: " << subtractionResult
		 << "\nMultiplication result: " << multiplicationResult 
		 << "\nDivision result: " << divisionResult 
		 << "\nModulus result: " << modulusResult 
		 << "\nMixed division result: " << mixedDivisionResult << endl;
	
	
	//prompt user to press a key and end the application
	system("pause");
	return 0;
}
