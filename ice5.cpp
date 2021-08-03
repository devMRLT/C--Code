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
 Application Name: looping compound periods
 Application Date: May 27, 2019
 Description: loop and check every year and calculate the interest made
 -------------------------------                         
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	float initalInvestment;
	const float INTEREST_RATE = 0.05f;

	while(initalInvestment <= 0)
	{
		std::cout << "Please enter an inital investment: ";
		std::cin >> initalInvestment;
	}

	std::cout << "Year \t" << "Interest" << "\tBalance" << std::endl;

	for (int compoundingPeriods = 1; compoundingPeriods < 11; ++compoundingPeriods)
	{
		std::cout << fixed << setprecision(2) << compoundingPeriods << "\t$" 
			<< (INTEREST_RATE*initalInvestment) << "\t\t$" 
				<< initalInvestment * pow(1+INTEREST_RATE, compoundingPeriods) 
					<< std::endl;
	}
	//I was working on the math for the Intrest col I know it's not right right now
	//system("pause");
	return 0;
}
