#include <iostream>	
#include <cstdlib> // for atoi() and atof()

using namespace std;

namespace validation
{
	/***************************************************************************************************************************************
	*	Function Name: GetValidDouble()
	*	Description: The GetValidDouble() Function will prompt users for, and capture, input of a double value.
	*				 The input is subjected to selection which determines whether or not the supplied value is valid.
	*
	*	@param theInputPrompt Supplies a prompt to be used to capture data type specific input
	*	@param MIN The minimum allowable input value
	*	@param MAX The maximum allowable input value
	*	@returns The validated double value captured by input
	***************************************************************************************************************************************/
	double GetValidDouble(string, const double MIN, const double MAX);
	
	
	/***************************************************************************************************************************************
	*	Function Name: GetValidInteger()
	*	Description: The GetValidInteger() Function will prompt users for, and capture, input of an integer value.
	*				 The input is subjected to selection which determines whether or not the supplied value is valid.
	*
	*	@param theInputPrompt Supplies a prompt to be used to capture data type specific input
	*	@param MIN The minimum allowable input value
	*	@param MAX The maximum allowable input value
	*	@returns The validated integer value captured by input
	***************************************************************************************************************************************/
	int GetValidInteger(string, const int MIN, const int MAX);
	
	
	/***************************************************************************************************************************************
	*	Function Name: GetValidDouble()
	*	Description: The overloaded GetValidDouble() Function will capture the input of a double value without accepting a prompt argument.
	*				 The input is subjected to selection which determines whether or not the supplied value is valid.
	*
	*	@param MIN The minimum allowable input value
	*	@param MAX The maximum allowable input value
	*	@returns The validated double value captured by input
	***************************************************************************************************************************************/
	double GetValidDouble(const double MIN, const double MAX);
	
	
	/*******************************************************************************************************************************************
	*	Function Name: GetValidInteger()
	*	Description: The overloaded GetValidInteger() Function will capture the input of an integer value without accepting a prompt argument.
	*				 The input is subjected to selection which determines whether or not the supplied value is valid.
	*
	*	@param MIN The minimum allowable input value
	*	@param MAX The maximum allowable input value
	*	@returns The validated integer value captured by input
	*******************************************************************************************************************************************/
	int GetValidInteger(const int MIN, const int MAX);
	

	/***************************************************************************************************************************************
	*	Function Name: GetValidDouble()
	*	Description: The overloaded GetValidDouble() Function will capture the input of a double value without accepting any arguments.
	*				 The input is subjected to selection which determines whether or not the supplied value is valid.
	*				 This function is to be used after a cout prompt is issued and class functions supply range validation.
	*
	*	@returns The validated double value captured by input
	***************************************************************************************************************************************/
	double GetValidDouble();
	
	
	/*******************************************************************************************************************************************
	*	Function Name: GetValidInteger()
	*	Description: The overloaded GetValidInteger() Function will capture the input of an integer value without accepting any arguments.
	*				 The input is subjected to selection which determines whether or not the supplied value is valid.
	*				 This function is to be used after a cout prompt is issued and class functions supply range validation.
	*
	*	@returns The validated integer value captured by input
	*******************************************************************************************************************************************/
	int GetValidInteger();
	
	double GetValidDouble(string theInputPrompt, const double MIN, const double MAX)
	{
		bool isValid = true; 			//partial loop control
		int decimalCount = 0; 			//counts number of decimal characters in input (maximum allowable is 1)
		string theInput = ""; 			//user input storage
		double validatedInput = 0.0;  	//store the converted user input
		
		//take input as usual
		cout << theInputPrompt;
		cin >> theInput;
		
		//loop while count remains less than length of input string and input is still valid
		for (int count = 0; count < theInput.length() && isValid; count++)
		{
			char currentCharacter = (char) theInput.at(count); //assign char value at current count position
			
			if (!isdigit(currentCharacter)) //if the input is not a numeric digit
			{
				if(currentCharacter == '+' || currentCharacter == '-') //it wasn't a digit but it is an allowable sign
				{
					if (count != 0 || theInput.length() == 1) //signs may only occupy the very first position and cannot be the only value
					{
						isValid = false; //input was invalid
					}
				}
				else if (currentCharacter == '.') //it wasn't a digit but it is a decimal
				{
					decimalCount++; //increase decimal count
					
					if (decimalCount > 1 || theInput.length() == 1) //if decimal count ever exceeds 1 or a decimal was the only value
					{
						isValid = false; //input was invalid
					}
				}
				else //it wasn't a digit or any allowable non-digit
				{
					isValid = false; //input was invalid
				}
			}
		}
		
		if (isValid) //input was a valid double value
		{
			validatedInput = atof(theInput.c_str()); //convert the string to a double
			
			
			if(validatedInput < MIN || validatedInput > MAX) //is the double outside of the allowable range?
			{
				//range error prompt
				cerr << "Error. Value must be between " << MIN << " and " << MAX << " inclusive.\nPlease try again.\n" << endl;
				
				//recursive call to start over
				validatedInput = GetValidDouble("Please enter a valid double value: ", MIN, MAX);
			}
		}
		else //input was not a valid double value
		{
			//generally invalid error prompt
			cerr << "Error. Input is in an invalid format.\nPlease try again.\n" << endl;
			
			//recursive call to start over
			validatedInput = GetValidDouble("Please enter a valid double value: ", MIN, MAX);
		}
		
		//if we ever reach this point, everything was good
		return validatedInput;
	}
	
	int GetValidInteger(string theInputPrompt, const int MIN, const int MAX)
	{
		bool isValid = true; 		//partial loop control
		string theInput = ""; 		//user input storage
		int validatedInput = 0;  	//store the converted user input
		
		//take input as usual
		cout << theInputPrompt;
		cin >> theInput;
		
		//loop while count remains less than length of input string and input is still valid
		for (int count = 0; count < theInput.length() && isValid; count++)
		{
			char currentCharacter = (char) theInput.at(count); //assign char value at current count position
			
			if (!isdigit(currentCharacter)) //if the input is not a numeric digit
			{
				if(currentCharacter == '+' || currentCharacter == '-') //it wasn't a digit but it is an allowable sign
				{
					if (count != 0 || theInput.length() == 1) //signs may only occupy the very first position and cannot be the only value
					{
						isValid = false; //input was invalid
					}
				}
				else //it wasn't a digit or any allowable non-digit
				{
					isValid = false; //input was invalid
				}
			}
		}
		
		if (isValid) //input was a valid integer value
		{
			validatedInput = atoi(theInput.c_str()); //convert the string to an integer
			
			if(validatedInput < MIN || validatedInput > MAX) //is the integer outside of the allowable range?
			{
				//range error prompt
				cerr << "Error. Value must be between " << MIN << " and " << MAX << " inclusive.\nPlease try again.\n" << endl;
				
				//recursive call to start over
				validatedInput = GetValidInteger("Please enter a valid integer value: ", MIN, MAX);
			}
		}
		else //input was not a valid integer value
		{		
			//generally invalid error prompt
			cerr << "Error. Input is in an invalid format.\nPlease try again.\n" << endl;
			
			//recursive call to start over
			validatedInput = GetValidInteger("Please enter a valid integer value: ", MIN, MAX);
		}
		
		//if we ever reach this point, everything was good
		return validatedInput;
	}

	double GetValidDouble(const double MIN, const double MAX)
	{
		bool isValid = true; 			//partial loop control
		int decimalCount = 0; 			//counts number of decimal characters in input (maximum allowable is 1)
		string theInput = ""; 			//user input storage
		double validatedInput = 0.0;  	//store the converted user input
		
		//take input without a prompt
		cin >> theInput;
		
		//loop while count remains less than length of input string and input is still valid
		for (int count = 0; count < theInput.length() && isValid; count++)
		{
			char currentCharacter = (char) theInput.at(count); //assign char value at current count position
			
			if (!isdigit(currentCharacter)) //if the input is not a numeric digit
			{
				if(currentCharacter == '+' || currentCharacter == '-') //it wasn't a digit but it is an allowable sign
				{
					if (count != 0 || theInput.length() == 1) //signs may only occupy the very first position and cannot be the only value
					{
						isValid = false; //input was invalid
					}
				}
				else if (currentCharacter == '.') //it wasn't a digit but it is a decimal
				{
					decimalCount++; //increase decimal count
					
					if (decimalCount > 1 || theInput.length() == 1) //if decimal count ever exceeds 1 or a decimal was the only value
					{
						isValid = false; //input was invalid
					}
				}
				else //it wasn't a digit or any allowable non-digit
				{
					isValid = false; //input was invalid
				}
			}
		}
		
		if (isValid) //input was a valid double value
		{
			validatedInput = atof(theInput.c_str()); //convert the string to a double
						
			if(validatedInput < MIN || validatedInput > MAX) //is the double outside of the allowable range?
			{
				//range error prompt
				cerr << "Error. Value must be between " << MIN << " and " << MAX << " inclusive.\nPlease try again.\n" << endl;
				
				//recursive call to start over
				validatedInput = GetValidDouble("Please enter a valid double value: ", MIN, MAX);
			}
		}
		else //input was not a valid double value
		{
			//generally invalid error prompt
			cerr << "Error. Input is in an invalid format.\nPlease try again.\n" << endl;
			
			//recursive call to start over
			validatedInput = GetValidDouble("Please enter a valid double value: ", MIN, MAX);
		}
		
		//if we ever reach this point, everything was good
		return validatedInput;
	}
	
	int GetValidInteger(const int MIN, const int MAX)
	{
		bool isValid = true; 		//partial loop control
		string theInput = ""; 		//user input storage
		int validatedInput = 0;  	//store the converted user input
		
		//take input without a prompt
		cin >> theInput;
		
		//loop while count remains less than length of input string and input is still valid
		for (int count = 0; count < theInput.length() && isValid; count++)
		{
			char currentCharacter = (char) theInput.at(count); //assign char value at current count position
			
			if (!isdigit(currentCharacter)) //if the input is not a numeric digit
			{
				if(currentCharacter == '+' || currentCharacter == '-') //it wasn't a digit but it is an allowable sign
				{
					if (count != 0 || theInput.length() == 1) //signs may only occupy the very first position and cannot be the only value
					{
						isValid = false; //input was invalid
					}
				}
				else //it wasn't a digit or any allowable non-digit
				{
					isValid = false; //input was invalid
				}
			}
		}
		
		if (isValid) //input was a valid integer value
		{
			validatedInput = atoi(theInput.c_str()); //convert the string to an integer
			
			if(validatedInput < MIN || validatedInput > MAX) //is the integer outside of the allowable range?
			{
				//range error prompt
				cerr << "Error. Value must be between " << MIN << " and " << MAX << " inclusive.\nPlease try again.\n" << endl;
				
				//recursive call to start over
				validatedInput = GetValidInteger("Please enter a valid integer value: ", MIN, MAX);
			}
		}
		else //input was not a valid integer value
		{		
			//generally invalid error prompt
			cerr << "Error. Input is in an invalid format.\nPlease try again.\n" << endl;
			
			//recursive call to start over
			validatedInput = GetValidInteger("Please enter a valid integer value: ", MIN, MAX);
		}
		
		//if we ever reach this point, everything was good
		return validatedInput;
	}
	
	double GetValidDouble()
	{
		bool isValid = true; 			//partial loop control
		int decimalCount = 0; 			//counts number of decimal characters in input (maximum allowable is 1)
		string theInput = ""; 			//user input storage
		double validatedInput = 0.0;  	//store the converted user input
		
		//take input without a prompt
		cin >> theInput;
		
		//loop while count remains less than length of input string and input is still valid
		for (int count = 0; count < theInput.length() && isValid; count++)
		{
			char currentCharacter = (char) theInput.at(count); //assign char value at current count position
			
			if (!isdigit(currentCharacter)) //if the input is not a numeric digit
			{
				if(currentCharacter == '+' || currentCharacter == '-') //it wasn't a digit but it is an allowable sign
				{
					if (count != 0 || theInput.length() == 1) //signs may only occupy the very first position and cannot be the only value
					{
						isValid = false; //input was invalid
					}
				}
				else if (currentCharacter == '.') //it wasn't a digit but it is a decimal
				{
					decimalCount++; //increase decimal count
					
					if (decimalCount > 1 || theInput.length() == 1) //if decimal count ever exceeds 1 or a decimal was the only value
					{
						isValid = false; //input was invalid
					}
				}
				else //it wasn't a digit or any allowable non-digit
				{
					isValid = false; //input was invalid
				}
			}
		}
		
		if (isValid) //input was a valid double value
		{
			validatedInput = atof(theInput.c_str()); //convert the string to a double
		}
		else //input was not a valid double value
		{
			//generally invalid error prompt
			cerr << "Error. Input is in an invalid format.\nPlease try again: ";
			
			//recursive call to start over
			validatedInput = GetValidDouble();
		}
		
		//if we ever reach this point, everything was good
		return validatedInput;
	}
	
	int GetValidInteger()
	{
		bool isValid = true; 		//partial loop control
		string theInput = ""; 		//user input storage
		int validatedInput = 0;  	//store the converted user input
		
		//take input without a prompt
		cin >> theInput;
		
		//loop while count remains less than length of input string and input is still valid
		for (int count = 0; count < theInput.length() && isValid; count++)
		{
			char currentCharacter = (char) theInput.at(count); //assign char value at current count position
			
			if (!isdigit(currentCharacter)) //if the input is not a numeric digit
			{
				if(currentCharacter == '+' || currentCharacter == '-') //it wasn't a digit but it is an allowable sign
				{
					if (count != 0 || theInput.length() == 1) //signs may only occupy the very first position and cannot be the only value
					{
						isValid = false; //input was invalid
					}
				}
				else //it wasn't a digit or any allowable non-digit
				{
					isValid = false; //input was invalid
				}
			}
		}
		
		if (isValid) //input was a valid integer value
		{
			validatedInput = atoi(theInput.c_str()); //convert the string to an integer
		}
		else //input was not a valid integer value
		{		
			//generally invalid error prompt
			cerr << "Error. Input is in an invalid format.\nPlease try again: ";
			
			//recursive call to start over
			validatedInput = GetValidInteger();
		}
		
		//if we ever reach this point, everything was good
		return validatedInput;
	}
}
