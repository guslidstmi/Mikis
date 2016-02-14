/* This is class contains the game logic for the BullCow Game */

#pragma once

#include "FBullCowGame.h"
#include <algorithm>
#include <map>

#define TMap std::map // to make syntax Unreal friendly

FBullCowGame::FBullCowGame() { Reset(1); } // default constructor
// Getters
int32 FBullCowGame::GetCurrentTry() const { return m_currentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return m_hiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bHasWon; }

int32 FBullCowGame::GetMaxTries() const
{
	TMap<int32, int32> WordLengthToMaxTries{ {3,4}, {4, 7}, {5,10}, {6,16}, {7,20}, {8,22}, {9,25}, {10,28} };

	return WordLengthToMaxTries[m_hiddenWord.length()];
}

// Resets the game, generating a new word based on difficulty and resetting the stats.
void FBullCowGame::Reset(const int32 difficulty)
{
	const FString HIDDEN_WORD = generateHiddenWord(difficulty); // this MUST be an isogram

	m_hiddenWord = HIDDEN_WORD;
	m_currentTry = 1;
	bHasWon = false;
	
	return;
}

EGuessStatus FBullCowGame::checkGuessValidity(const FString Guess) const
{
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

bool FBullCowGame::IsIsogram(const FString Guess) const
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

// Generate a word for the user to guess based on difficulty. 
FString FBullCowGame::generateHiddenWord(const int32 difficulty)
{
	srand(time(NULL));
	int32 randomNum = rand() % 10 + 1;

	TMap<int32, FString>EasyWords{ { 1, "cow" },{ 2, "cat" },{ 3, "dog" },{ 4, "hat" },{ 5, "rat" },
	{ 6, "monk" },{ 7, "crow" },{ 8, "frog" },{ 9, "harp" },{ 10, "king" } };
	TMap<int32, FString>NormalWords{ { 1, "mouse" },{ 2, "trash" },{ 3, "crown" },{ 4, "horse" },{ 5, "grams" },
	{ 6, "planet" },{ 7, "jockey" },{ 8, "mount" },{ 9, "python" },{ 10, "royal" } };
	TMap<int32, FString>HardWords{ { 1, "blacksmith" },{ 2, "gunpowder" },{ 3, "dumbing" },{ 4, "stumped" },
	{ 5, "isogram" },{ 6, "agents" },{ 7, "polarity" },{ 8, "jokingly" },{ 9, "chipmunk" },{ 10, "jumpable" } };

	switch (difficulty)
	{
	case 1: return EasyWords[randomNum]; break;
	case 2: return NormalWords[randomNum]; break;
	case 3: return HardWords[randomNum]; break;
	default: return "planet";

	}
}

// recieves a VALID guess, increments turn and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(const FString Guess)
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
