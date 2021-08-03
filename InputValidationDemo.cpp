/***********************************************************************************************************
*	Application Name: InputValidationExample.cpp
*	Application Creation Date: July 5, 2019
*	Application Author: Dan Barlow
*	Description: This application demonstrates a method for validating user input captured via cin.
***********************************************************************************************************/
#include "InputValidation.h"

using namespace validation;

int main()
{
	//GetValidInteger() range thresholds
	const int MINIMUM_INPUT = 0;
	const int MAXIMUM_INPUT = 100;
	
	
	//GetValidDouble() range thresholds
	//const double MINIMUM_INPUT = 0.0;
	//const double MAXIMUM_INPUT = 100.0;
	
	int userInput = 0; 	//stores validated user input
	//double userInput = 0.0; //for use with GetValidDouble()
	
	/*****************
	*	INPUT        *
	*****************/
	userInput = GetValidInteger("Please enter a valid integer value: ", MINIMUM_INPUT, MAXIMUM_INPUT);
	//userInput = GetValidDouble("Please enter a valid double value: ", MINIMUM_INPUT, MAXIMUM_INPUT);
	
	
	/*****************
	*	OUTPUT       *
	*****************/
	cout << "Your input (" << userInput << ") sure was fantastic!\n" << endl;
	
	system("pause");
	return 0;
}
