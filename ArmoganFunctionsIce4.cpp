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
void CalculateInvestmentValue(int, float&);

int main()
{
	//minimum allowable number of quarters
	int minimum = 1;
	//stores user input for number of quarters in the bank
	int theTotalQuarters = 0;
	//stores calculated value of investing quarters over 25 years
	float theInvestmentValue = 0.00f;
	/******************
	*	INPUT		  *
	******************/
	//assign result of GetValidInteger() done
	theTotalQuarters = GetValidInteger("Please specifiy the number of quarters: ",minimum);
	
	/******************
	*	PROCESSING    *
	******************/
	//call CalculateInvestmentValue() done
	CalculateInvestmentValue(theTotalQuarters,theInvestmentValue);

	system("cls");	//clear the screen
		
	/******************
	*	OUTPUT		  *
	******************/
	//cout statement goes here
	std::cout << fixed << setprecision(2) << "Investment value is: $"
		<< &theInvestmentValue << std::endl;
	system("pause");
	return 0;
}

//define CalculateInvestmentValue()
void CalculateInvestmentValue(int theTotalQuarters, float& theInvestmentValue){ //does calculation then passes back to main the reference
	//constant representing the value of a quarter
	//constant representing the interest rate of 5%
	//constant representing the investment term of 25 years

	const float quarter = 0.25;
	const float interest = 0.05;
	const int investment = 25;

	theInvestmentValue = (theTotalQuarters*quarter) * pow(1+interest, investment);
	//perform the calculation
//end of CalculateInvestmentValue() definition
}

	
	
