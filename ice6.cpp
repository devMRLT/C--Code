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
 Application Name: ICE 6
 Application Date: May 27, 2019
 Description: 
 -------------------------------                         
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	float initalInvestment = 0.00f;
	while(true)
	{
	if(initalInvestment <= 0)
	{
			bool r;//returns break 
			//collects inintial investmeant
			std::cout << "Please enter an inital investment: ";
			std::cin >> initalInvestment;
			system("cls");
		//runs so long as it hasn't been broken
		if(r == 0){
			while(true){
				//scope restart vaible for while loop
				char restartInput;
				//
				int tempCompundingPeriods = 0;
				float tempInvestmentInterest = 0.00f;
				float currentBalance = 0.00f;
				//variable section small
				const float SMALL_INVESTMEANT = 2000.00f;
				const int SMALL_INVESTMEANT_PERIOD = 3;
				const float SMALL_INVESTMEANT_INTEREST = 0.025f;
				//variable section medium
				const int MEDIUM_INVESTMEANT_PERIOD = 5;
				const float MEDIUM_INVESTMEANT_INTEREST = 0.0375f;
				//variable section large
				const float LARGE_INVESTMEANT = 5000.00f;
				const int LARGE_INVESTMEANT_PERIOD = 10;
				const float LARGE_INVESTMEANT_INTEREST = 0.05;
				//he asked for the inital invest before the table
				std::cout << "initial Investmeant: $" << initalInvestment << std::endl;
				//-------------------------------------------------------------
				//begining of table
				std::cout << "Year \t" << "Interest" << "\tBalance" << std::endl;
				//logic need
			//branching for desiding what varible section to use
				if(initalInvestment <= SMALL_INVESTMEANT){
					tempCompundingPeriods = SMALL_INVESTMEANT_PERIOD;
					tempInvestmentInterest = SMALL_INVESTMEANT_INTEREST;
				}
				else if(initalInvestment > SMALL_INVESTMEANT && initalInvestment < LARGE_INVESTMEANT){
					tempCompundingPeriods = MEDIUM_INVESTMEANT_PERIOD;
					tempInvestmentInterest = MEDIUM_INVESTMEANT_INTEREST;
				}
				else if(initalInvestment > LARGE_INVESTMEANT){
					tempCompundingPeriods = LARGE_INVESTMEANT_PERIOD;
					tempInvestmentInterest = LARGE_INVESTMEANT_INTEREST;
				}
				
				for(int year = 1; year <= tempCompundingPeriods; year++){
					currentBalance += initalInvestment*pow(1+tempInvestmentInterest, tempCompundingPeriods);

					std::cout << fixed << setprecision(2) << year << "\t$" 
						<< currentBalance*tempInvestmentInterest << "\t\t$" 
							<< initalInvestment*pow(1+tempInvestmentInterest, year) << std::endl;
				}
				//loop checks to see if the user wants todo the application again
				while(true){
				//do you want to restart
				std::cout << "Do you want to restart the application y or n: ";
				std::cin >> restartInput;
				if(restartInput == 'y'){
					std::cout << "will continue"<< std::endl;
					r = 0;
					//initalInvestment = 0;
					break;
				}
				//working
				else if(restartInput == 'n')
					std::cout << "will end now" << std::endl;
					system("cls");
					system("pause");
				}
				if(restartInput == 'y'){
					initalInvestment = 0;
					break;
				}
			}
		}
	} else if(initalInvestment >= 0){
		std::cout << "you must enter a value greater than zero. \n please try again" << std::endl;
	}
	}
	//system("pause");
	return 0;
}
