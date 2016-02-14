/* This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/

#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

// type substitutions to be more like Unreal code
using Ftext = std::string;
using int32 = int;

// function prototypes as outside a class, definitions are below
void PrintIntro();
void PlayGame();
void PrintGameSummary();
Ftext GetValidGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

// the entry point for our application
int main()
{
	bool bPlayAgain = true;
	do
	{
		PrintIntro();
		PlayGame();
		
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);

	return 0; // exit the application
}

// introduce the game
void PrintIntro()
{
	std::cout << "\n\nWelcome to Bulls and Cows, a fun word game.\n";
	std::cout << " ____ __  __ __   __   ___      __   _  _ ____      ___ _____ _    _ ___  " << std::endl;
	std::cout << "(  _ (  )(  |  ) (  ) / __)    /__\\ ( \\( |  _ \\    / __|  _  | \\/\\/ ) __) " << std::endl;
	std::cout << " ) _ <)(__)( )(__ )(__\\__ \\   /(__)\\ )  ( )(_) )  ( (__ )(_)( )    (\\__ \\ " << std::endl;
	std::cout << "(____(______|____|____|___/  (__)(__|_)\\_|____/    \___|_____|__/\\__|___/ \n" << std::endl;
	return;
}

// plays a single game to completion
void PlayGame()
{
	// prompt the user to select a difficulty so we can generate a word based on this.
	std::cout << "Please choose a difficulty!" << std::endl;
	std::cout << "1. Easy" << std::endl;
	std::cout << "2. Normal" << std::endl;
	std::cout << "3. Hard" << std::endl;

	int32 difficulty = 0;
	std::cin >> difficulty;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	BCGame.Reset(difficulty);

	int32 maxTries = BCGame.GetMaxTries();

	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I am thinking of?" << std::endl;
	// loop for the number of turns asking for guesses

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= maxTries)
	{
		Ftext Guess = GetValidGuess();

		// submit valid guess to the game
		FBullCowCount BCCount = BCGame.SubmitValidGuess(Guess);
		
		// print number of bulls and cows
		std::cout << "Bulls = " << BCCount.Bulls;
		std::cout << ", Cows = " << BCCount.Cows << "\n\n";

	}

	PrintGameSummary();
	
	return;
}
// Print winning or loosing message
void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "CONGRATULATIONS! YOU WON!\n";
	}
	else
		std::cout << "YOU LOST! BETTER LUCK NEXT TIME!\n";
}

// loop continually until the user gives a valid guess
Ftext GetValidGuess() 
{
	Ftext Guess = "NewString";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		std::cout << "Try " << BCGame.GetCurrentTry() << " of " << BCGame.GetMaxTries() << ". Enter your guess: ";
		
		std::getline(std::cin, Guess);

		Status = BCGame.checkGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Contains_Numbers:
			std::cout << "This word contains numbers! Please only enter letters.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "This word has uppercase letters! Please only enter lowercase letters.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "This word is not an isogram! Please enter a word without repeating letters.\n";
			break;
		default:
			// assume that guess is valid
			break;
		}
	} while (Status != EGuessStatus::OK); // Keep looping until we get no errors
	
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Would you like to play again with the same word? (y/n)" << std::endl;
	Ftext Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}