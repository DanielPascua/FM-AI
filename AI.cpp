#include <cassert>
#include "AI.h"

using namespace std;


AI::AI()
{
}


AI::~AI()
{
}

void AI::ResetActiveData()
{
	currentInputList.clear();
	dynamicStateList.clear();
	while (!nextInput.empty())
		nextInput.pop();
}

void AI::FullTestRunProcessing(TestRun testRun)
{
	testRuns.push_back(testRun);
}

Input AI::selectNextInput()
{
	Input result;

	//If we have a preplanned next input, use that
	if (!nextInput.empty())
	{
		result = nextInput.front();
		nextInput.pop();
	}
	else
	{
		result = RESET;
		//Do the actual input selection


	}

	return result;
}
void AI::processResult(Input inputSent, DynamicState state)
{
	if (inputSent == RESET)
	{
		//Finalize test run
		TestRun testRunResult;
		assert(currentInputList.size() == dynamicStateList.size());
		for (int i = 0; i < currentInputList.size(); i++)
		{
			testRunResult.inputResultList.push_back(pair<Input, DynamicState>(currentInputList[i], dynamicStateList[i]));
		}
		FullTestRunProcessing(testRunResult);

		//Reset
		ResetActiveData();
	}
	else
	{
		currentInputList.push_back(inputSent);
		dynamicStateList.push_back(state);

		//Do the actual processing (create theories)


	}
}
void AI::beginNewPuzzle(VisibleState state)
{
	//Reset active data
	ResetActiveData();
	//Set other puzzle data
	testRuns.clear();
	currentPuzzleInitialData = state;
}