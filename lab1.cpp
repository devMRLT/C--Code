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
 Application Name: Pizza pi lab
 Application Date: May 27, 2019
 Description: This lab will calcualte the number of totalSlicesFromThePizzas out of a pizza
 				to as close to 14.125
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
	float pizzaDiameter = 0.0f;
	int totalSlicesFromThePizza = 0;
	const float PIZZA_SLICE_SIZE = 14.125f;
			/*
				Prompt secion/Input
			*/
	std::cout << "Please enter the diameter of your pizza: ";
	std::cin >> pizzaDiameter;
			/*
				Calcsulation
			*/
	totalSlicesFromThePizza = ((M_PI*(pow((pizzaDiameter/2),2)))/PIZZA_SLICE_SIZE);
			/*
				Output Section
			*/
	std::cout << "\nA " << pizzaDiameter << "\" pizza will yield " 
		<< totalSlicesFromThePizza << " slices. \n" << std::endl;
		for (int i = 0; i < 12; ++i)
		{
			std::cout << "=";
		}

	system("pause");
	return 0;
}