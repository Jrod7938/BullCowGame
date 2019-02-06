/*This is the console executable, that makes use of the BullCow clss
This acts as the view in a MVC pattern, and is responsible for all users interaction. 
For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; //instantiate a new game

//Entry Point For Application.
int main() 
{
	std::cout << BCGame.GetCurrentTry();
	bool bPlayAgain = false;
	do 
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();		
	} 
	while (bPlayAgain);

	return 0;
}


void PrintIntro()	//Introduce the game
{
	constexpr int32 WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows, a fun word game!\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of? \n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	//loop for the number of turns asking for guesses
	//TODO change from FOR loop to WHILE loop once we have validated tries
	for (int32 count = 1; count <= MaxTries; count++)
	{
		FText Guess = GetGuess();//TODO make loop check if guess is valid

		//submit valid guess to game, and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		//Print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;

		std::cout << std::endl;
	}
	//TODO summarise game
}


FText GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();

	//Get guess from user
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (Y/n)";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}
