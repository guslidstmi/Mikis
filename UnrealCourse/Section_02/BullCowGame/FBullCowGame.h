/* This class provides the logic for the Bulls and Cows word game
based on the original peg game Mastermind
*/

#ifndef FBULLCOWGAME_H
#define FBULLCOWGAME_H

#include <string>


using FString = std::string;
using int32 = int; // type substitution to make more like Unreal code

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

enum class EResetStatus
{};

class FBullCowGame {
public:
	
	FBullCowGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus checkGuessValidity(FString) const; 

	void Reset(); 
	FBullCowCount SubmitValidGuess(FString);


private:

	bool IsIsogram(FString) const;

	int32 m_maxTries;
	int32 m_currentTry;
	FString m_hiddenWord;
	bool bHasWon;
};

#endif // FBULLCOWGAME_H