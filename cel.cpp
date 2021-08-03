/*
* @Author: Nathaniel Armogan
* @Date:   2019-07-19 09:03:40
* @Last Modified by:   nathaniel
* @Last Modified time: 2019-07-26 15:21:26
* @Application Name: TempConverter
* @Description: This application allows for the usr to enter the temp for each day 
				of the week and it returns the days in F and C. It displays it in a 
				nice table allowing for the usr to see a full overview of the temp 
				in both mainstream conversions.
*/
#include <cmath>
#include <string>
#include <iomanip>
#include "InputValidation.h"


//Debugging in progress
using namespace validation;

//calc the day of the week from the int value that is given by the loop
string CaculateDayOfWeek(int);

//Converts the input value of celsius to fahrenheit
inline double CalculateDegrees(double cel)
{
	return (cel * 9)/5+32;
}
//takes the the function for calculating fheit and puts it into a table with the celsius calculation
template <class TempOutput>
	void Output(TempOutput celsius[]){
		const char DEGREE_SYMBOL = (char) 248;
		/***************
		Output Section
		****************/
		std::cout << "\n\tTHIS WEEK'S TEMPURATURE REPORT" 
			<< "\n\t=============================" << std::endl;
		for (int outputStep = 1; outputStep < 8; ++outputStep)
			std::cout << fixed << setprecision(2) << setw(15) 
				<< CaculateDayOfWeek(outputStep) << setw(7) 
					<< CalculateDegrees(celsius[outputStep]) << DEGREE_SYMBOL << "F"
						<< setw(12) << celsius[outputStep] << DEGREE_SYMBOL << "C" << std::endl;
}

int main(int argc, char const *argv[])
{
	/***************
	variable section
	****************/
	const double MIN = -90.0;
	const double MAX = 60.0;
	const int NUMBEROFDAYS = 8;

	//day of week array
	double celsius [NUMBEROFDAYS];
	/*************
	Input section
	**************/
	std::cout << "TEMPERATURE REPORTER" << "\n====================\n"
	<< "Please enter the temp for each day of the week" << std::endl;
	// function accepts inputstep passes to string array pulls index
	for (int inputStep = 1; inputStep < NUMBEROFDAYS; ++inputStep){
			//output message with function to bring back array
		std::cout << "Celsius tempurature for " << CaculateDayOfWeek(inputStep) << ": ";
			//set the new celsius array equal to the input from the usr
		celsius[inputStep] = GetValidDouble(MIN,MAX);
	}
		//function for output
		Output(celsius);
	system("pause");
	return 0;
}
//this function stores an array that has the days of the week and error message
string CaculateDayOfWeek(int inputStep){
	/*
	variable section
	*/
	const int ARRAYSIZE = 8;
	string daysOfTheWeek [ARRAYSIZE] = {"Invalid Input try again","Sunday", "Monday","Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
		return daysOfTheWeek[inputStep];
}