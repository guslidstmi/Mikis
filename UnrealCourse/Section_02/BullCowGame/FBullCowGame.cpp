#include "FBullCowGame.h"
#include <algorithm>
#include <map>
#define TMap std::map

FBullCowGame::FBullCowGame() { Reset(); }
// Getters
int32 FBullCowGame::GetMaxTries() const { return m_maxTries; }
int32 FBullCowGame::GetCurrentTry() const { return m_currentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return m_hiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bHasWon; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	m_hiddenWord = HIDDEN_WORD;
	m_maxTries = MAX_TRIES;
	m_currentTry = 1;
	bHasWon = false;
	
	return;
}

EGuessStatus FBullCowGame::checkGuessValidity(FString Guess) const
{
	//if the guess is not an isogram 
	if (!IsIsogram(Guess)) // if the guess is not an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (std::any_of(Guess.begin(), Guess.end(), isdigit)) // if the guess contains numbers
	{
		return EGuessStatus::Contains_Numbers;
	}
	else if (std::any_of(Guess.begin(), Guess.end(), isupper)) //if the guess is not all lowercase
	{
		return EGuessStatus::Not_Lowercase; 
	}
	else if (Guess.length() != GetHiddenWordLength()) // if the guess length is wrong
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
		
	return EGuessStatus::OK; 
}

bool FBullCowGame::IsIsogram(FString Guess) const
{
	// treat 0 and 1 letter words as isograms
	if (Guess.length() < 2)
	{
		return true;
	}

	TMap<char, bool> LettersSeen; // create map

	for (auto letter : Guess)
	{
		letter = tolower(letter);
		if (LettersSeen[letter])
		{
			return false;
		}
		else
		{
			LettersSeen[letter] = true;
		}
	}
	return true;
}

// recieves a VALID guess, increments turn and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	++m_currentTry;
	FBullCowCount BullCowCount;
	int32 WordLength = m_hiddenWord.length(); // assuming same length as guess

	// loop through all the letters in the hidden word
	for (int32 HWChar = 0; HWChar < WordLength; ++HWChar)
	{	
		// compare letters against the guess 
		for (int32 GChar = 0; GChar < WordLength; ++GChar)
		{
			// if they match then
			if (Guess[GChar] == m_hiddenWord[HWChar])
			{
				if (HWChar == GChar) // increment bulls if they're in the same place
				{
					++BullCowCount.Bulls;
				}
				else // increment cows if not
				{
					++BullCowCount.Cows;
				}
			}	
		}
	}
	if (BullCowCount.Bulls == WordLength) 
	{ 
		bHasWon = true; 
	}
	return BullCowCount;
}
