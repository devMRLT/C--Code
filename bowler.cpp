/*
* @Author: nathaniel armogan
* @Date:   2019-07-27 09:57:01
* @Last Modified by:   nathaniel
* @Last Modified time: 2019-07-28 17:21:00
* @Application name: Bowling application
* @Description: This program will take the usr input into an array and proccess the data into 
					an array then calc average and find highest and lowest values  
*/
#include "InputValidation.h"
#include <iomanip>//needed for the set precsision

//declares the bowling array size so that it can be used throughout the program
const int BOWL_ARRAY_SIZE = 6;

//links the namespace funstions form header file
using namespace validation;


//takes the average score from the array populated by the usr
double AverageFunction(int bowlingArray []);

// //uses a custom sort to set the highest value into the var and return it
int sortHigh(int bowlingArray []);

// //uses a custom sort to set the lowest value in the array to the var and return the var
int sortLow(int bowlingArray []);


int main(int argc, char const *argv[])
{
	/*
	Variable Section
	*/
	//declares the Minimum value that the usr can input
	const int MIN = 0;
	//declares the Maximum value that the usr can input
	const int MAX = 300;
	//initalize the user input to a value not Y or N
	char userInput = 'k';
	//set a bool to keep the program running within the loop
	bool innerProgram = false;

	while(innerProgram = true){
	//declare the array and fill with the global constant
	int bowlingArray [BOWL_ARRAY_SIZE];
	
	/*
	Input Section
	*/
	for (int i = 1; i < BOWL_ARRAY_SIZE; ++i)
	{
		std::cout << "Please enter score for game " << i << ":";
		//I know that I don't need to add the quotes in there but it was being buggy without it
		bowlingArray[i] = GetValidInteger("",MIN, MAX);
	}
	/*************
	Output Section
	**************/
	std::cout << "Bowler Scores" << "\n======================================================" << std::endl;
	for (int i = 1; i < BOWL_ARRAY_SIZE; ++i)
		std::cout << "Game " << i << ":" << bowlingArray[i] << " ";
	//I used the setprcision to sort hand the rounding for the average function
	std::cout << "\n======================================================\n" << "Average Score for Bowler: "
		<< fixed << setprecision(0) << AverageFunction(bowlingArray) << "\nHigh Score for Bowler: " << sortHigh(bowlingArray)
			<< "\nLow Score for Bowler: " << sortLow(bowlingArray) << std::endl;
	
	//gathers user input to restart or exit program
	while(userInput != 'Y'){
	std::cout << "Would you like to restart the program Y or N: ";
	std::cin >> userInput;
	if(userInput == 'N')
		system("pause");
	}
	//clears the screen for new loop
	system("cls");
	//resets the usrInput var so that it can be used again.
	userInput = 'K';
	}
	return 0;
}
//This function goes through each index in the array and sums up than dividies it by the number of indexs to calculate the average
double AverageFunction(int bowlingArray []){
	//declare the average value as double so that it can not have a division problem
	double average = 0;
	//goes trhough and adds up all the values in array
	for (int averageLoopcounter = 1; averageLoopcounter < BOWL_ARRAY_SIZE; ++averageLoopcounter)
		average += bowlingArray[averageLoopcounter];
	//returns the sum of array divided by the number of indexs
	return average/5;
}
//loops through the array and set the lowestscore variable equal to the lowest index in the array
int sortLow(int bowlingArray []){
	/*
	Variable Section
	*/
	//lowest score set to the max value to make sure that the input is below it
	int lowestScore = 300;
	//loops through and sets lowestScore equal to the lowests index in the array
	for (int lowScoreLoopCounter = 1; lowScoreLoopCounter < BOWL_ARRAY_SIZE; ++lowScoreLoopCounter)
		if(bowlingArray[lowScoreLoopCounter] < lowestScore)
			lowestScore = bowlingArray[lowScoreLoopCounter];
		//returns the lowest score in the array
		return lowestScore;
}
//loops through the array and set the highestscore variable equal to the highest index in the array
int sortHigh(int bowlingArray []){
	/*
	Variable Section
	*/
	//highest score set to zero/lowest entrie to search through array
	int highscore = 0;
	//looops through and sets the highest value equal to the highscore
	for (int highScoreLoopCounter = 1; highScoreLoopCounter < BOWL_ARRAY_SIZE; ++highScoreLoopCounter)
		if(bowlingArray[highScoreLoopCounter] > highscore)
			highscore = bowlingArray[highScoreLoopCounter];
		//returns the highscore value 
		return highscore;
}
