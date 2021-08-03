/*
* @Author: Nathaniel Armogan
* @Date:   2019-07-13 11:36:54
* @Application Name: Lab 3 part 1
* @Last Modified time: 2019-07-14 10:45:54
* @ Description: This is a simple calculator that will calculate the hypotense of the trangle.
*/
#include <iomanip>
#include <cmath>
#include "InputValidation.h"

using namespace validation;

//This function calculates the hyp of the triangle based on the usrs 2 inputted values
inline float FindHypotenuse(float lengthOfTriangleOne, float lengthOfTriangleTwo)
{
	return sqrt((pow(lengthOfTriangleOne,2)+pow(lengthOfTriangleTwo,2)));
}

int main(int argc, char const *argv[])
{
		/******************
		*	Variables
		******************/
	//constant declarations
	const float MIN = -100.00;//min limit that the usr can enter
	const float MAX = 100.00;//max limit that the usr can enter
	//variable declarations
	float lengthOfTriangleOne = 0.00f;//usr entered length 1
	float lengthOfTriangleTwo = 0.00f;//usr entered length 2
	
		/******************
		*	INPUT
		******************/
	lengthOfTriangleOne = GetValidInteger("Please enter the first length of the triangle: ", MIN, MAX);
	lengthOfTriangleTwo = GetValidInteger("Please enter the second length of the triangle: ", MIN, MAX);
		/******************
		*	OUTPUT
		******************/
	std::cout << fixed << setprecision(3) << "The hypotenuse is: "
		<< FindHypotenuse(lengthOfTriangleOne,lengthOfTriangleTwo) << std::endl;
	system("pause");
	return 0;
}

