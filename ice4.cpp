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
 Application Name: ice 4
 Application Date: , 2019
 Description: calc intrest rate with the if statements
 -------------------------------                         
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
	const double SMALL_INVESTMENT = 2000.00;
	const double MEDIUM_INVESTMENT = 5000.00;

	const int SMALL_COMPOUND_PERIOD = 6;
	const int MEDIUM_COMPOUND_PERIOD = 10;
	const int LARGE_COMPOUND_PERIOD = 20;

	const double SMALL_INTREST_RATE = 0.025;
	const double MEDIUM_INTREST_RATE = 0.0375;
	const double LARGE_INTREST_RATE = 0.05;

	double initalInvestment = 0.0;
	double intrestRate = 0.0;
	int compoundingPeriods = 0;
	double finalValue = 0.0;

	//input
	std::cout << "please enter initial investment: ";
	std::cin >> initalInvestment;
	//proccessing
	if(initalInvestment <= SMALL_INVESTMENT)
	{
		intrestRate = SMALL_INTREST_RATE;
		compoundingPeriods = SMALL_COMPOUND_PERIOD;
	}
	else if(initalInvestment <= MEDIUM_INVESTMENT)
	{
		intrestRate = MEDIUM_INTREST_RATE;
		compoundingPeriods = MEDIUM_COMPOUND_PERIOD;
	}
	else
	{
		intrestRate = LARGE_INTREST_RATE;
		compoundingPeriods = LARGE_COMPOUND_PERIOD;
	}

	finalValue = initalInvestment * pow(1+intrestRate, compoundingPeriods);

	std::cout << fixed << setprecision(2) << "inital investment $: " << initalInvestment
			  << "\nIntrest Rate: " << intrestRate * 100
			  << "\n Number of compounding periods: " << compoundingPeriods
			  << "\nValue of investment: " << finalValue << std::endl; 

	system("pause");
	return 0;
}
