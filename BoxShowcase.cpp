/******************************************************************************
*	Application Name: BoxShowcase.cpp
*	Application Author: Nathaniel Armogan
*	Date Created: August 9th, 2019
*	Description: This will take the user input for the volume of a box and calculate it
*
******************************************************************************/
#include "Box.h"
#include "InputValidation.h"

using namespace validation;

int main()
{
	//Minimum allowable input value
	const double MINIMUM = 1.0;
	//Maximum allowable input value
	const double MAXIMUM = 100.0;
	//Companion constant for box array
	const int ARRAY_SIZE = 2;
	//Declare Box Array
	Box boxArray [ARRAY_SIZE];
	
	/*************
	*	INPUT	*
	************/
	for (int indexStep = 0; indexStep < ARRAY_SIZE; indexStep++)
	{		
		//default box object for purposes of input
		Box currentBox = Box();
		//accept input for height

		currentBox.SetHeight(GetValidDouble("Please enter the Height:",MINIMUM,MAXIMUM));
		//accept input for length
		currentBox.SetLength(GetValidDouble("Please enter the length:",MINIMUM,MAXIMUM));
		//accept input for width
		currentBox.SetWidth(GetValidDouble("Please enter the Width:",MINIMUM,MAXIMUM));
		
		
		/****************
		*	PROCESSING	*
		****************/
		//place the box object in to the array at the current loop position
		boxArray[indexStep] = currentBox;
		system("cls");
	}
	
	
	/************
	*	OUTPUT	*
	************/
	for (int indexStep2 = 0; indexStep2 < ARRAY_SIZE; indexStep2++)
	{
		//Use a single cout statement for output
		std::cout << "Height For Box " << indexStep2 << " :"<< boxArray[indexStep2].GetHeight()
			<< "\nLength For Box " << indexStep2 << " :" << boxArray[indexStep2].GetLength()
				<< "\nLength For Box " << indexStep2 << " :" << boxArray[indexStep2].GetWidth()
					<< "\nvolume For Box " << indexStep2 << " :" << boxArray[indexStep2].FindVolume() 
						<< std::endl;
		//Call the relevant Member Functions from the Array itself
	}
	
	system("pause");
	return 0;
}
