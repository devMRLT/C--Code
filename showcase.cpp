/*********************************************************************
*	Application Name: RightTriangleShowcase.cpp
*	Application Author: Nathaniel Armogan
*	Creation Date: August 20
*	Description: This file contains the outline to a final project that I was doing for finding the hypotensuse of a triangle. This does this by 
					reciving input into objects held in an array then finds the hypotense of the triangle. It also calculates the average side lengths
					and hypotensuse of the triangle based on the 3 iterations it goes through
*	
*********************************************************************/

#include <iomanip> //needed for setprecision
#include "RightTriangle.h" //stores the class details
#include "InputValidation.h" //stores the functions for the input
#include <stdexcept> 	//needed for the exception handling
#include <cmath> //stores the abs() function for converting all values to postive from the usr

using namespace validation; //namespace has all of the inputvalidation functions/code

//This function will calculate the averages of all the values in the Right trinagle class
void DisplayTriangleAverages(int, RightTriangle RightTriangleArray[]);

int main()
{
	/*
	VARIABLE SECTION
	*/
	const int RightTriangle_ARRAY_SIZE = 2;	//Companion constant for RightTriangle array
	RightTriangle RightTriangleArray[RightTriangle_ARRAY_SIZE]; 	//Create RightTriangle array
	
	for (int rightTriangleCounter = 0; rightTriangleCounter < RightTriangle_ARRAY_SIZE; rightTriangleCounter++)
	{
		std::cout << "RightTriangle EDITOR\nTriangle number" << rightTriangleCounter + 1 << std::endl;
		
		try //beginning of Exception Handling code
		{
			//instantiate default RightTriangle Object for input purposes
			RightTriangle currentRightTriangle = RightTriangle();
			
			/************
			*	INPUT	*
			************/
			//prompt for RightTriangle SideOne for each RightTriangle
			std::cout << "Please enter the length for side 1: ";
			//call SetSideOne() Mutator for default RightTriangle Object using GetValidDouble()
			currentRightTriangle.SetSideOne(abs(GetValidDouble());//the inputval is wrapped in the absolute function to make sure the value is returned postitive

			//prompt for RightTriangle SideTwo for each RightTriangle
			std::cout << "\nPlease enter the length for side 2:"
			//call SetSideTwo() Mutator for default RightTriangle Object using GetValidDouble()
			currentRightTriangle.SetSideTwo(abs(GetValidDouble());//the inputval is wrapped in the absolute function to make sure the value is returned postitive
			currentRightTriangle.FindHypotenuse();
			
			/****************
			*	PROCESSING	*
			****************/
			//Add RightTriangle Object in to the array
			RightTriangleArray[rightTriangleCounter] = currentRightTriangle;
		}
		catch (out_of_range errorMessage) //"Catch" any out_of_range "Exception" that was "Thrown" by the previous code
		{
			//display out_of_range exception error message
			cerr << errorMessage.what() << std::endl;
			rightTriangleCounter--;	//decrement rightTriangleCounter to force user to input for current RightTriangle again
		}
		
		std::cout << std::endl;
		system("pause");
		system("cls");
	}
	
	/************
	*	OUTPUT	*
	************/
	for (int loopCounter = 0; loopCounter < RightTriangle_ARRAY_SIZE; loopCounter++)
	{
		RightTriangleArray[loopCounter].ToString(); //displays the output of the class
	}
	//calls the function that calculates the averages for the objects in the array (side 1 & 2 and hypo)
	DisplayTriangleAverages(RightTriangle_ARRAY_SIZE,RightTriangleArray);
	
	system("pause");//pause system once the program is done
	return 0;
}
//this function goes through each object stored in the right triangle array and finds the average of the sidelengths as well as the hypotenuses
//then it displays them to the usr
void DisplayTriangleAverages(int RightTriangle_ARRAY_SIZE, RightTriangle RightTriangleArray[])
{
	/*
	VARIABLE SECTION
	*/
	double averageSideOne = 0.0; //will store the average of sideone
	double averageSideTwo = 0.0; //will store the average of sidetwo
	double averageHypotenuse = 0.0; //will store the average of the hyps

	//each loop iteration will add the values to the previous iteration
	for (int  arrayCounter = 0; arrayCounter < ARRAY_SIZE; ++arrayCounter)
	{
		averageSideOne += RightTriangleArray[arrayCounter].GetSideOne(); //sideOne summed
		averageSideTwo += RightTriangleArray[arrayCounter].GetSideTwo(); //sideTwo summed
		averageHypotenuse += RightTriangleArray[arrayCounter].GetHypotenuse(); //hypotenuse summed
	}
	//displays the output section for the average values
	std::cout << "\n=============================================================\n" << "AVERAGES\n" << "SideOne average: " << averageSideOne/ARRAY_SIZE
		<< "\nSideTwo average: " << averageSideTwo/ARRAY_SIZE << "\nHypotenuse average: " << averageHypotenuse/ARRAY_SIZE << std::endl; 
}

