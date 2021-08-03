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
  
 Given Name: Nathaniel Armogan    
 Application Name: piggy
 Application Date: May 24, 2019
 Description: write a program that calculates the total amount in a piggy bank based on quarters                                 
*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	/*
	Varsection Section
	*/
	//declares the total in the piggybank
	int totalPiggyCoins = 10;
	//total amount in the piggy bank
	float totalInPiggy = 0.0f;
	//
	const float QUARTERS_COINS = 0.25;

	/*
	Calculation Section
	*/
	totalInPiggy = (totalPiggyCoins*QUARTERS_COINS)+totalInPiggy;
	/*
	Output Section
	*/
	std::cout << "The total number of Quarters: " << totalPiggyCoins << std::endl
		<< "Total in the bank: " << totalInPiggy << std::endl;
	system("pause");
	return 0;
}
