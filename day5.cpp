/* 
 __                       __       __  _______   __     ________ 
|  \                     |  \     /  \|       \ |  \   |        \
| $$____   __    __  __  | $$\   /  $$| $$$$$$$\| $$    \$$$$$$$$
| $$    \ |  \  |  \|  \ | $$$\ /  $$$| $$__| $$| $$      | $$   
| $$$$$$$\| $$  | $$ \$$ | $$$$\  $$$$| $$    $$| $$      | $$   
| $$  | $$| $$  | $$ __  | $$\$$ $$ $$| $$$$$$$\| $$      | $$   
| $$__/ $$| $$__/ $$|  \ | $$ \$$$| $$| $$  | $$| $$_____ | $$   
| $$    $$ \$$    $$ \$$ | $$  \$ | $$| $$  | $$| $$     \| $$   
 \$$$$$$$  _\$$$$$$$      \$$      \$$ \$$   \$$ \$$$$$$$$ \$$   
          |  \__| $$                                                  
           \$$    $$                                                  
            \$$$$$$  
 ------------------------------
 Author Name: Nathaniel Armogan    
 Application Name: Compound intrest calc
 Application Date: May 27, 2019
 Description: Taking the given formula for compound intrest calculate 
 				the output based on the users inputed information
 -------------------------------                         
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
		/*
			Defined variables
		*/
	//the constant is made for the intrest rate as it does not change
	const float INTREST_RATE = 0.045f;
	//need a float for hte investmeant as this money which uses 2 places
	float initalInvestmeant = 0.0f;
	//the years are calculated based on whole numbers 
	int compoundedPeriods = 0;
	float finalInvestmeantValue = 0.0f;
	
		/*
			Prompt/input Section
		*/
	std::cout << "Please enter the inital investmeant: ";
	std::cin >> initalInvestmeant;
	std::cout << "Please enter the comounded periods: ";
	std::cin >> compoundedPeriods;
		/*
			Proccessing Section
		*/
	finalInvestmeantValue = initalInvestmeant*(pow((1 + INTREST_RATE),compoundedPeriods));
		/*
			Output Section
		*/
	std::cout << "The final investmeant value is $" << fixed 
		<< setprecision(2) << finalInvestmeantValue << std::endl;

	return 0;
	system("pause");
}
