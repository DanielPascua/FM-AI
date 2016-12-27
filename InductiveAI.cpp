#include <cassert>
#include "InductiveAI.h"

using namespace std;


InductiveAI::InductiveAI()
{
}


InductiveAI::~InductiveAI()
{
}

void InductiveAI::ResetActiveData()
{
	currentInputList.clear();
	dynamicStateList.clear();
	while (!nextInput.empty())
		nextInput.pop();
}

void InductiveAI::FullTestRunProcessing(TestRun testRun)
{
	testRuns.push_back(testRun);
}

Input InductiveAI::SelectNextInput()
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
void InductiveAI::ProcessResult(Input inputSent, DynamicState state)
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
void InductiveAI::BeginNewPuzzle(VisibleState state)
{
	//Reset active data
	ResetActiveData();
	//Set other puzzle data
	testRuns.clear();
	currentPuzzleInitialData = state;
}

//Returns true when the InductiveAI believes it has found a valid theory for the puzzle
bool InductiveAI::testTheory()
{
	return false;
}

//Call when DeductiveAI is unable to find a solution when testing the current theory
void InductiveAI::NoSolutionFound()
{

}