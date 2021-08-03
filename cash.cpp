/*
* @Author: Nathaniel Armogan
* @Date:   2019-07-13 11:36:54
* @Application Name: Lab 3 part 2
* @Last Modified time: 2019-07-14 10:45:18
* @ Description: This is a simple calculator that sorts the total Cash inputted into the common pocket change 100,50,20,10,5,2,1
*/
#include <iomanip>
#include <cmath>
#include "InputValidation.h"

using namespace validation;

//sorts the inputted cash from main into 100,50,20,10,5,2,1
void SortCash(int, int&, int&, int&, int&, int&, int&, int&);

int main(int argc, char const *argv[])
{
		/******************
		*	Variables
		******************/
	int totalCashInputted = 0;
	int looniesStored = 0;
	int tooniesStored = 0;
	int fivesStored = 0;
	int tensStored = 0;
	int twentiesStored = 0;
	int fiftiesStored = 0;
	int hundredsStored = 0;

	//sets the minimum value for the input section
	const int MIN = 1;
	//sets the maximum value for the input secion
	const int MAX = 1000;
	const int LOOPMAXVALUE = 3;
	//loops the code base 3 times allowing for the input to be collected the set amount.
	for (int inputSectionStep = 0; inputSectionStep < LOOPMAXVALUE; ++inputSectionStep)
	{
		//sets the total cash equal to the input function in the header file
		totalCashInputted = GetValidInteger("Please enter a total dollar amount:",MIN,MAX );
		//calls the sortCash function and passes the params through as reference (initiate the proccessing section)
		SortCash(totalCashInputted, looniesStored, tooniesStored, fivesStored, tensStored, twentiesStored, fiftiesStored, hundredsStored);
		/******************
		*	OUTPUT		  *
		******************/
		std::cout << "Number of loonies: " << looniesStored << std::endl
			<< "Number of Toonies: " << tooniesStored << std::endl
			<< "Number of Fives: " << fivesStored << std::endl
			<< "Number of Tens: " << tensStored << std::endl
			<< "Number of Twenties: " << twentiesStored << std::endl
			<< "Number of Fifties: " << fiftiesStored << std::endl
			<< "Nuber of Hundreds: " << hundredsStored << std::endl;
	}
	system("pause");
	return 0;
}
//sorts the inputted cash from main into 100,50,20,10,5,2,1
void SortCash(int totalCashInputted, int& looniesStored, int& tooniesStored, int& fivesStored, int& tensStored, int& twentiesStored, int& fiftiesStored, int& hundredsStored){
		//declared consts
		const int LOONIES = 1;
		const int TOONIES = 2;
		const int FIVES = 5;
		const int TENS = 10;
		const int TWENTIES = 20;
		const int FIFTIES = 50;
		const int HUNDREDS = 100;

		/******************
		*	PROCESSING    *
		******************/
		//sets the value of hundred by dividing total cash by 100 then sets the remainder after using modulus (don't think we have covered this yet but it's how I would normally write it in comp sci)
		hundredsStored = totalCashInputted/HUNDREDS;
		totalCashInputted = totalCashInputted%HUNDREDS;

		fiftiesStored = totalCashInputted/FIFTIES;
		totalCashInputted = totalCashInputted%FIFTIES;

		twentiesStored = totalCashInputted/TWENTIES;
		totalCashInputted = totalCashInputted%TWENTIES;

		tensStored = totalCashInputted/TENS;
		totalCashInputted = totalCashInputted%TENS;

		fivesStored = totalCashInputted/FIVES;
		totalCashInputted = totalCashInputted%FIVES;

		tooniesStored = totalCashInputted/TOONIES;
		totalCashInputted = totalCashInputted%TOONIES;

		looniesStored = totalCashInputted/LOONIES;
		totalCashInputted = totalCashInputted%LOONIES;

}
