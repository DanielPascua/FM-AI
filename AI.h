#pragma once

#include <vector>
#include <queue>
#include "PuzzleData.h"

class AI
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
	void FullTestRunProcessing(TestRun testRun);

	//Active data about the current test run on the puzzle
	std::queue<Input> nextInput; //Preplanned next input
	std::vector<Input> currentInputList; //List of input since last reset, back being most recent
	std::vector<DynamicState> dynamicStateList; //List of dynamic states since last reset, back being most recent, back being the DynamicState after the first input
	
	void ResetActiveData();

public:
	AI();
	~AI();
	Input selectNextInput();
	void processResult(Input inputSent, DynamicState state);
	void beginNewPuzzle(VisibleState state);
};

