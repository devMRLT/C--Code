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
 Application Name: Lab2 Pizza Pi 2
 Application Date: June 22, 2019
 Description: Loops through the program prompting the user for input as to how
 			  large the pizza is and calculates the how many slices based on 
 			  the pizza size.
 -------------------------------                         
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
			/*
			MAIN FUN VARS(FULL AX TO SUB BLOCKS)
			*/
	//stores the di of the pizza from user (not given inital because asked prompted from usr)
	float diameterOfPizza;
	//bool value allows for the program to run contained and ended when asked easily
	bool endOfProgram = false;
	//begining of program
	while(endOfProgram == false){
				   /***************
					*INPUT SECTION*
					***************/
		std::cout << "Please enter the diameter of your pizza (0 to end of program): ";
		std::cin >> diameterOfPizza;
		if(diameterOfPizza >= 12){
					/*
					CONST variables for block
					*/
			//pizza that has 8 slices 4 the formula
			const int EIGHT_SLICES_RANGE = 8;
			//pizza that has 12 slices 4 the formula
			const int TWELVE_SLICES_RANGE = 12;
			//pizza that has 16 slices 4 the formula
			const int SIXTEEN_SLICES_RANGE = 16;
					/*
					Reg Vars for block
					*/
			int tempSlicesRange = 0;
			float sliceArea = 0.00f;
					/*
					START OF OUTPUT SECTION
					*/
			std::cout << fixed << setprecision(0) << "Pizza diameter: " << diameterOfPizza << "\"" << std::endl;
			//quicker to code
			for (int i = 0; i < 80; ++i) std::cout << "=";
			//drops line to look clean
			std::cout << std::endl;
					/*
					PROCCESSING SECTION
					*/
			//start of branching for ranges
			if(diameterOfPizza >= 12 && diameterOfPizza <= 20){
				//formula 1 for calc of area of slice
				sliceArea = ((M_PI*(pow((diameterOfPizza/2),2)))/EIGHT_SLICES_RANGE);
				//display statemeant 1
				std::cout << fixed << setprecision(2) << "Cut into 8 slices results in area of: " << sliceArea 
				<< "\" per slice"<< std::endl;

			}else if(diameterOfPizza > 20 && diameterOfPizza <= 24){
				//formula 1 for calc of area of slice
				sliceArea = ((M_PI*(pow((diameterOfPizza/2),2)))/EIGHT_SLICES_RANGE);
				//display statemeant 1
				std::cout << fixed << setprecision(2) << "Cut into 8 slices results in area of: " << sliceArea 
				<< "\" per slice"<< std::endl;

				//formula 2 for calc of area of slice
				sliceArea = ((M_PI*(pow((diameterOfPizza/2),2)))/TWELVE_SLICES_RANGE);
				//display statemeant 2
				std::cout << fixed << setprecision(2) << "Cut into 12 slices results in area of: " << sliceArea 
				<< "\" per slice"<< std::endl;
			}else if(diameterOfPizza > 24 && diameterOfPizza <= 30){
				//formula 1 for calc of area of slice
				sliceArea = ((M_PI*(pow((diameterOfPizza/2),2)))/EIGHT_SLICES_RANGE);
				//display statemeant 1
				std::cout << fixed << setprecision(2) << "Cut into 8 slices results in area of: " << sliceArea 
				<< "\" per slice"<< std::endl;

				//formula 2 for calc of area of slice
				sliceArea = ((M_PI*(pow((diameterOfPizza/2),2)))/TWELVE_SLICES_RANGE);
				//display statemeant 2
				std::cout << fixed << setprecision(2) << "Cut into 12 slices results in area of: " << sliceArea 
				<< "\" per slice"<< std::endl;

				//formula 3 for calc of area of slice
				sliceArea = ((M_PI*(pow((diameterOfPizza/2),2)))/SIXTEEN_SLICES_RANGE);
				//display statemeant 3
				std::cout << fixed << setprecision(2) << "Cut into 16 slices results in area of: " << sliceArea 
				<< "\" per slice"<< std::endl;
			}else if(diameterOfPizza > 30){
				//formula 1 for calc of area of slice
				sliceArea = ((M_PI*(pow((diameterOfPizza/2),2)))/EIGHT_SLICES_RANGE);
				//display statemeant 1
				std::cout << fixed << setprecision(2) << "Cut into 8 slices results in area of: " << sliceArea 
				<< "\" per slice"<< std::endl;

				//formula 2 for calc of area of slice
				sliceArea = ((M_PI*(pow((diameterOfPizza/2),2)))/TWELVE_SLICES_RANGE);
				//display statemeant 2
				std::cout << fixed << setprecision(2) << "Cut into 12 slices results in area of: " << sliceArea 
				<< "\" per slice"<< std::endl;

				//formula 3 for calc of area of slice
				sliceArea = ((M_PI*(pow((diameterOfPizza/2),2)))/SIXTEEN_SLICES_RANGE);
				//display statemeant 3
				std::cout << fixed << setprecision(2) << "Cut into 16 slices results in area of: " << sliceArea 
				<< "\" per slice"<< std::endl;

				//I had a const for the 24 but just seemed like a waste so dropped it
				//formula 4 for calc of area of slice
				sliceArea = ((M_PI*(pow((diameterOfPizza/2),2)))/(TWELVE_SLICES_RANGE*2));
				//display statemeant 4
				std::cout << fixed << setprecision(2) << "Cut into 24 slices results in area of: " << sliceArea 
				<< "\" per slice"<< std::endl;
	}
		//final line to reset program
		diameterOfPizza -= diameterOfPizza;

	}else if(diameterOfPizza == 0){
			endOfProgram = true;
			std::cout << "exiting now";
	}else{
		std::cout << "ERROR OUT OF RANGE TRY AGAIN!!!!" << std::endl;
		//clear the screen
		system("cls");
	}
	}
	system("pause");
	return 0;
}
	