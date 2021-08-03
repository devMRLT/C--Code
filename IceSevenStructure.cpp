/*******************************************************************************************************************************************************************************************
*	Application Author: Nathaniel Armogan
*	Application Name: ICE 7
*	Creation Date: June 20, 2016
*	
*	Description: This application will determine the total amount of cash, in dollars, within a piggy bank that contains only quarters and 
*				 the potential value if that amount is invested with compound interest.
*				 The user is continuously prompted to input the total number of quarters until a positive number is entered. 
*				 The total cash is determined by using the FindTotalCash() function to multiply the number of quarters by the constant value, in cents, of a quarter (0.25).
*				 The value after investment is determined by using the CalculateInvestmentValue() function to execute a compound interest formula.
*				 The user is then shown the amount of quarters in the piggy bank, the total cash in the piggy bank, and the value of the investment.
*				 The EvaluateTotalCash() function is used to display a message letting the user know the status of their savings (broke, some cash, rich).
*				 Users are continuously asked if they would like to enter another value until they enter 'y' or 'n'.
*				 Entering 'y' will re-run the program, entering 'n' will notify the user that the application is ending.
*
*******************************************************************************************************************************************************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//function prototypes

/*****************************************************************************************************************************************************************
*	Function name: CalculateInvestmentValue
*	Description: The CalculateInvestmentValue() function will calculate the value of an investment using a compound interest formula.
*	@param initialInvestment The initial investment.
*	@param theInterestRate The interest rate.
*	@param investmentTerm The length of the investment period
*	@returns The calculated value of the investment at the end of the investmentTerm.
*****************************************************************************************************************************************************************/
inline double CalculateInvestmentValue(double initialInvestment, double theInterestRate, int investmentTerm)
{
	return initialInvestment * pow(1 + theInterestRate, investmentTerm);
}

/*****************************************************************************************************************************************************************
*	Function name: FindTotalCash
*	Description: The FindTotalCash function will multiply a number of coins by the value of each coin.
*	@param numberOfCoins The total number of coins.
*	@param valuePerCoin The value that each coin holds in cents.
*	@returns The result of multiplying numberOfCoins by valuePerCoin.
*****************************************************************************************************************************************************************/
inline double FindTotalCash(int numberOfCoins, double valuePerCoin)
{
	return numberOfCoins*valuePerCoin;
}

/*****************************************************************************************************************************************************************
*	Function name: EvaluateTotalCash
*	Description: The EvaluateTotalCash function will output a message to the console based on the value of the theTotalCash parameter.
*				 If theTotalCash is less than or equal to the constant FIFTY_DOLLARS, the message "You're broke!" will be shown.
*				 If theTotalCash is less than or equal to the constant ONE_HUNDRED_DOLLARS, the message "You've got some cash!" will be shown.
*				 If theTotalCash is greater than 100, the message "You're rich!" will be shown.
*	@param theTotalCash The cash value to evaluate.
*****************************************************************************************************************************************************************/
void EvaluateTotalCash(double);

/*****************************************************************************************************************************************************************
*	Function name: ValidateInput
*	Description: This overloaded version of the ValidateInput function will validate an integer input to determine if the user entered a value greater than zero.
*				 If the user entered a negative value they will be shown an error message.
*	@param theNumber The number that the user supplied as input.
*	@returns isValid A boolean value that returns true if the user entered a value greater than zero.
*****************************************************************************************************************************************************************/
bool ValidateInput(int);

/*****************************************************************************************************************************************************
*	Function name: ValidateInput
*	Description: This overloaded version of the ValidateInput function will validate a character input to determine if the user entered 'y' or 'n'.
*				 If the user did not enter either of these values they will be shown an error message.
*	@param theResponse The character that the user supplied as input.
*	@returns isValid A boolean value that returns true if the user entered 'y' or 'n', otherwise it returns false.
*****************************************************************************************************************************************************/
bool ValidateInput(char);
	
int main()
{	
	//outer loop control
	char anotherInput = 'y';				//variable to hold a user response for re-running the program

	do
	{		
		//constant declarations
		const double VALUE_OF_QUARTER = 0.25;	//constant to hold the value, in cents, of a quarter
		const double INTEREST_RATE = 0.045;		//constant representing the annual interest rate of 4.5%
		const int INVESTMENT_TERM = 5;			//constant value representing the number of years in an investment term
		
		//variable declarations
		int numberOfQuarters = 0;			    //variable to hold the total number of quarters contained in a piggy bank
		double totalCash = 0.0;					//variable to hold the result of calculating the total amount of cash in a piggy bank
		double investmentValue = 0.0;			//variable to hold the total value of the investment after compound interest
		
		
		/******************
		*	INPUT
		******************/
		do
		{
			cout << "Enter the total number of quarters: "; //prompt the user to enter a value
			cin >> numberOfQuarters;                        //store the value in the numberOfQuarters variable
		} while(!ValidateInput(numberOfQuarters)); //while it is true that the ValidateInput() function returns a value of false, continue to loop
		
		
		/******************
		*	PROCESSING
		******************/
		//find total cash amount in piggy bank by calling FindTotalCash() and assigning its return value
		totalCash = FindTotalCash(numberOfQuarters, VALUE_OF_QUARTER);
		
		//determine total value of investment by calling CalculateInvestmentValue() and assigning its return value
		investmentValue = CalculateInvestmentValue(totalCash, INTEREST_RATE);
		
		/******************
		*	OUTPUT
		******************/
		system("cls");
		
		cout << "Number of quarters in Piggy Bank: " << fixed << setprecision(2) << numberOfQuarters 
			 << "\nTotal cash in Piggy Bank: $" << totalCash 
			 << "\nValue of investment: $" << investmentValue << endl;
		
		//determine comment to display based on totalCash value by Calling EvaluateTotalCash()
		EvaluateTotalCash(investmentValue);
		
		
		//prompt to re-run program
		do
		{
			cout << "\nWould you like to enter another amount (y/n)? ";
			cin >> anotherInput;
		} while(ValidateInput(anotherInput)); //while it is true that the ValidateInput() function returns a value of false, continue to loop
		
		system("cls");
		
	}while(tolower(anotherInput) == 'y');
	
	system("cls");
	
	cout << "Ending application.\n" << endl;
	
	//pause execution and end application
	system("pause");
	return 0;
}
/*****************************************************************************************************************************************************************
*	Function name: EvaluateTotalCash
*	Description: The EvaluateTotalCash function will output a message to the console based on the value of the theTotalCash parameter.
*				 If theTotalCash is less than or equal to the constant FIFTY_DOLLARS, the message "You're broke!" will be shown.
*				 If theTotalCash is less than or equal to the constant ONE_HUNDRED_DOLLARS, the message "You've got some cash!" will be shown.
*				 If theTotalCash is greater than 100, the message "You're rich!" will be shown.
*	@param theTotalCash The cash value to evaluate.
*****************************************************************************************************************************************************************/
//function definitions
void EvaluateTotalCash(double theTotalCash)
{
	//variable section
	const float FIFTY_DOLLARS = 50.00f;
	const float ONE_HUNDRED_DOLLARS = 100.00f;

	if (theTotalCash <= FIFTY_DOLLARS)
	{
		std::cout << "You are broke" << std::endl;
	}
	else if(theTotalCash <= ONE_HUNDRED_DOLLARS)
	{
		std::cout << "You've got some cash!" << std::endl;
	}
	else
	{
		std::cout << "You're rich!" << std::endl;
	}
}

/*****************************************************************************************************************************************************************
*	Function name: ValidateInput
*	Description: This overloaded version of the ValidateInput function will validate an integer input to determine if the user entered a value greater than zero.
*				 If the user entered a negative value they will be shown an error message.
*	@param theNumber The number that the user supplied as input.
*	@returns isValid A boolean value that returns true if the user entered a value greater than zero.
*****************************************************************************************************************************************************************/
bool ValidateInput(int theNumber);
{
	bool isValid = 0;
	if(theNumber > 0){
		return (isValid = 1);
	}else{
		return (isValid = 0);
	}
}

/*****************************************************************************************************************************************************
*	Function name: ValidateInput
*	Description: This overloaded version of the ValidateInput function will validate a character input to determine if the user entered 'y' or 'n'.
*				 If the user did not enter either of these values they will be shown an error message.
*	@param theResponse The character that the user supplied as input.
*	@returns isValid A boolean value that returns true if the user entered 'y' or 'n', otherwise it returns false.
*****************************************************************************************************************************************************/
bool ValidateInput(char theResponse);
{
	bool isValid = 0;
	if(theResponse == 'y' || theResponse == 'n'){
		return (isValid = 1);
	}
	else
	{
		return (isValid = 0);
	}
}


