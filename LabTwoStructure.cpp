/***************************************************************************************************************************************************************************************************
* Application Author: Nathaniel Armogan
* Application Name: Pizza Pie Lab 2
* Creation Date: June 27, 2019
* Description: This application will first prompt users to input the size of a pizza's diameter in inches. 
*
*              Diameters may be entered as real numbers. At any time, the user may enter a diameter of 0 to exit the application.
*
*			   Once entered, the diameter is validated to be within the range of 12 and 36 inches (inclusive). 
*
*              An error message is shown when the diameter is outside of that range and the user is reprompted to enter a diameter.
*
*			   When the diameter entered is valid, users are shown the approximate area of each slice in a number of slice configurations 
*              that is based upon the size of the pizza area.
*
*			   Users are continuously prompted for a diameter after being shown the slice configurations until they enter a diameter of '0'.
***************************************************************************************************************************************************************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	//declare outer loop control
	bool needInput = true;
	
	//define outer loop
	do
	{
		/****************************************
		*   APPLICATION VARIABLE DECLARATIONS   *
		*****************************************/
		double pizzaDiameter = 0.0; 	//the diameter of the pizza
		//the maximum number of slices the pizza can be cut into
		//the calculated radius of the pizza (optional)
		//the calculated area of the pizza
		
		/*******************************************
		*   APPLICATION CONSTANT INITIALIZATIONS   *
		********************************************/
		
		/* PIZZA SIZE CONSTANTS */
		const int TWELEVE_INCH_PIZZA = 12;
		const int TWENTY_INCH_PIZZA = 20;
		const int TWENTYFOUR_INCH_PIZZA = 24;
		const int THIRTY_INCH_PIZZA = 30;
		const int THIRTYSIX_INCH_PIZZA = 36;
		
		/* PIZZA SLICE CONFIGURATIONS */
		const int EIGHT_SLICES = 8;
		const int TWELVE_SLICES = 12;
		const int SIXTEEN_SLICES = 16;
		const int TWENTYFOUR_SLICES = 24;
		
		/************
		*   INPUT   *
		*************/
		cout << "Please enter the diameter of your pizza (0 to end program): ";
		cin >> pizzaDiameter;
		
		//validation of input
		if(pizzaDiameter >= TWELEVE_INCH_PIZZA && pizzaDiameter <= THIRTYSIX_INCH_PIZZA) //range check (was pizzaDiameter >= minimum value and pizzaDiameter <= maximum value?)
		{
			//if we reach this point then pizzaDiameter input was good, begin processing
			//holds the max amount of slices
			int maxSlices = 0;
			/*****************
			*   PROCESSING   *
			******************/
			//selection to determine maximum number of slices
			//remember logical implication through the process of elimination
			
			if(pizzaDiameter >= TWELEVE_INCH_PIZZA && pizzaDiameter <= TWENTY_INCH_PIZZA) //smallest configuration
			{
				maxSlices = EIGHT_SLICES;
			}
			else if(pizzaDiameter > TWENTY_INCH_PIZZA && pizzaDiameter <= TWENTYFOUR_INCH_PIZZA) //medium configuration
			{
				maxSlices = TWENTYFOUR_SLICES;
			}
			else if(pizzaDiameter > TWENTYFOUR_INCH_PIZZA && pizzaDiameter <= THIRTY_INCH_PIZZA) //large configuration
			{
				maxSlices = THIRTY_INCH_PIZZA;
			}
			else //largest configuration
			{
				maxSlices = THIRTYSIX_INCH_PIZZA;
			}

			/*************
			*   OUTPUT   *
			**************/
			system("cls");
			
			cout << "\nPizza Diameter: " << pizzaDiameter << "\""
				<< "\n===========================================================================\n";
			
			//define for loop to handle ALL output combinations, do not use "i" as your counter name!
			//start slice counter at smallest slice number constant (8, use a constant, not a literal)
			//continuing looping so long as slice counter is less than maximum number of slices
			//increment slice counter by 4 after each iteration (instead of incrementing by 1)
			for (int sliceCounter = EIGHT_SLICES; sliceCounter <= maxSlices; sliceCounter+=4)
			{
				std::cout << fixed << setprecision(2) << "Cut into "<< sliceCounter << " slices results in area of: " 
					<< ((M_PI*(pow((pizzaDiameter/2),2)))/sliceCounter) << "\"" << std::endl;
				//a SINGLE cout statement to output each line of slice configurations
				//no other code should be in this loop
			}
			
			cout << endl; //just to clean up the output and get the next prompt on a new line
		}
		else if(pizzaDiameter == 0)
		{
			needInput = false;
		}
		else
		{
			std::cout << "ERROR OUT OF RANGE TRY AGAIN!!!!" << std::endl;
		}
	} while(needInput);
	return 0;
}
