/* This class provides the logic (no view code or direct user interaction) 
for the Bulls and Cows word game based on the original peg game Mastermind
*/

#ifndef FBULLCOWGAME_H
#define FBULLCOWGAME_H

#include <string>
#include <stdlib.h>
#include <time.h>

// type substitutions to be more like Unreal code
using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;	
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase,
	Contains_Numbers

};

class FBullCowGame {
public:
	
	FBullCowGame(); // default constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus checkGuessValidity(const FString) const; 

	void Reset(const int32); 
	FBullCowCount SubmitValidGuess(const FString);


private:

	bool IsIsogram(FString) const;
	FString generateHiddenWord(const int32);
	int32 m_currentTry;
	FString m_hiddenWord;
	bool bHasWon;
};

#endif // FBULLCOWGAME_H