#pragma once

#include <vector>
#include <queue>
#include "PuzzleData.h"
#include "AIData.h"


class InductiveAI
{
private:
	/*
	Prior data
	*/


	
	/*
	Current puzzle data
	*/

	//Known puzzle data
	VisibleState currentPuzzleInitialData; //Static data for current puzzle, received when new puzzle is started

	//Observations
	struct TestRun
	{
		std::vector<std::pair<Input, DynamicState>> inputResultList; //front being first input, back being last input, list of (input, result state)
	};
	std::vector<TestRun> testRuns;

	//Current puzzle theories
	Theory currentPuzzleTheory;

	void FullTestRunProcessing(TestRun testRun);

	//Active data about the current test run on the puzzle
	std::queue<Input> nextInput; //Preplanned next input
	std::vector<Input> currentInputList; //List of input since last reset, back being most recent
	std::vector<DynamicState> dynamicStateList; //List of dynamic states since last reset, back being most recent, back being the DynamicState after the first input
	
	void ResetActiveData();

public:
	InductiveAI();
	~InductiveAI();

	Input SelectNextInput();
	void ProcessResult(Input inputSent, DynamicState state);
	void BeginNewPuzzle(VisibleState state);

	Theory GetCurrentPuzzleTheory() const { return currentPuzzleTheory; }
	bool testTheory(); //Returns true when the InductiveAI believes it has found a valid theory for the puzzle
	void NoSolutionFound(); //Call when DeductiveAI is unable to find a solution when testing the current theory
};

