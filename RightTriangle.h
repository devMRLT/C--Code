/*********************************************************************
*	Application Name: RightTriangle.h
*	Application Author: Nathaniel Armogan
*	Creation Date: August 17th, 2019
*	Description: This file contains the class for the showcase file for our final project. This final project class goes through and takes user
					input to calculate the hypotense of a triangle based on the side lengths given by the users
*	
*********************************************************************/

#include <stdexcept>	// for out_of_range
#include <sstream>		// for stringstream
#include <iostream>		// for cout
#include <cmath> 		//sqr root 
#include <iomanip>		//setprecision

using namespace std;

class RightTriangle
{
	private:
		double sideOne; //first side of the triangle
		double sideTwo; //the second side of the traingle
		double hypotenuse; // the hypotenuse of the triangle
		
	public:
		RightTriangle(): sideOne(0.0), sideTwo(0.0), hypotenuse(0.0){ } //default constructor
		RightTriangle(double newSideOne, double newSideTwo); // param constructor
		
		double GetSideOne() const;
		double GetSideTwo() const;
		double GetHypotenuse() const;
		
		void SetSideOne(double newSideOne);
		void SetSideTwo(double newSideTwo);
		
		void FindHypotenuse();
		void ToString() const;
};

RightTriangle::RightTriangle(double newSideOne, double newSideTwo)
{
	SetSideOne(newSideOne);
	SetSideTwo(newSideTwo);
	FindHypotenuse();
}

double RightTriangle::GetSideOne() const
{
	return sideOne;
}

double RightTriangle::GetSideTwo() const
{
	return sideTwo;
}

double RightTriangle::GetHypotenuse() const
{
	return hypotenuse;
}


void RightTriangle::SetSideOne(double newSideOne)
{
	//Add Range Validation and Exception Handling to SetSideOne()	
	const double MINIMUM_ALLOWABLE_INPUT = -100.00;
	const double MAXIMUM_ALLOWABLE_INPUT  = 100.00;
	//checks the min allowed usr input and the max
	if(newSideOne >= MINIMUM_ALLOWABLE_INPUT && newSideOne <= MAXIMUM_ALLOWABLE_INPUT )
	{
		sideOne = newSideOne;
	}
	else
	{
		stringstream errorMessage;
		errorMessage << "Error out of range occured \nSide #1 must be between" << MINIMUM_ALLOWABLE_INPUT
			<< " and " << MAXIMUM_ALLOWABLE_INPUT << "." << std::endl;
		throw out_of_range(errorMessage.str());
	}
}

void RightTriangle::SetSideTwo(double newSideTwo)
{
	//Add Range Validation and Exception Handling to SetSideOne()	
	const double MINIMUM_ALLOWABLE_INPUT = -100.00;
	const double MAXIMUM_ALLOWABLE_INPUT  = 100.00;
	//checks the min allowed usr input and the max
	if(newSideTwo >= MINIMUM_ALLOWABLE_INPUT && newSideTwo <= MAXIMUM_ALLOWABLE_INPUT )
	{
		sideTwo = newSideTwo;
	}
	else
	{
		stringstream errorMessage;
		errorMessage << "Error out of range occured \nSide #2 must be between" << MINIMUM_ALLOWABLE_INPUT
			<< " and " << MAXIMUM_ALLOWABLE_INPUT << "." << std::endl;
		throw out_of_range(errorMessage.str());
	}
}

void RightTriangle::FindHypotenuse()
{
	SetHypotenuse(sqrt(pow(GetSideOne(), 2) + pow(GetSideTwo(), 2)));//calculates teh hypotense of the triangle based on the given lengths
}

void RightTriangle::ToString() const
{	
	//ouputs the data from the class
	std::cout << fixed << setprecision(2) << "\n=============================================================\n"
		<< "First side: " << GetSideOne() << "\nSecond Side: " << GetSideTwo() << "\n Hypotenuse: " << GetHypotenuse()
			<< << "\n=============================================================" << std::endl;
}
