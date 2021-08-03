/*****************************************************************************************
*	Application Name: ArmoganFunctionsIce4.cpp
*	Application Author: Nathaniel Armogan
*	Creation Date: July 7, 2019
*	
*	Description: This application will use a function that contains a reference parameter 
*				 to calculate a compound interest investment value and alter the value 
*				 of a variable in main().
*****************************************************************************************/

#include <cmath>				//include <cmath> and <iomanip> before InputValidation.h so they take 
#include <iomanip>				//advantage of the #include list in InputValidation.h
#include "InputValidation.h" 	//make sure this file is in the same directory as InputValidation.h
using namespace validation;


/*******************************************************************************************************
*	Function Name: CalculateInvestmentValue()
*	Description: A basic compound interest function that utilizes a reference parameter.
*	
*	@param theTotalQuarters The number of quarters entered previously as input.
*	@param theInvestmentValue& Reference parameter that holds the calculated value of the investment.
*******************************************************************************************************/

//CalculateInvestmentValue() prototype goes here
int CalculateInvestmentValue();

int main()
{
	//minimum allowable number of quarters
	int minimum = 1;
	//stores user input for number of quarters in the bank
	int quartersInBank = 0;
	//stores calculated value of investing quarters over 25 years
	float result = 0.00f;
	float afterCalculation = 0.00f;
	string prompt = "Please enter a valid integer value: ";
	/******************
	*	INPUT		  *
	******************/
	//assign result of GetValidInteger() done
	result = GetValidInteger(prompt,minimum,maximum,quartersInBank);
	
	/******************
	*	PROCESSING    *
	******************/
	//call CalculateInvestmentValue() done
	afterCalculation = CalculateInvestmentValue(theTotalQuarters);

	system("cls");	//clear the screen
		
	/******************
	*	OUTPUT		  *
	******************/
	//cout statement goes here
	std::cout << fixed << setprecision(2) << afterCalculation
	system("pause");
	return 0;
}

//define CalculateInvestmentValue()
int CalculateInvestmentValue(theTotalQuarters, theInvestmentValue&){
	//constant representing the value of a quarter
	//constant representing the interest rate of 5%
	//constant representing the investment term of 25 years

	const float quarter = 0.025;
	const int interest = 5;
	const int investment = 25;
	float result = 00.00f;
	result = quartersInBank * pow(1+interest, investment);
return result;
	//perform the calculation
//end of CalculateInvestmentValue() definition
}

	
	
