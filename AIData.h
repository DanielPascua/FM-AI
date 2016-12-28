#pragma once

#include <vector>
#include "AbstractObjects.h"
#include "PuzzleData.h"

struct InputTheory
{

};
struct Theory
{
	InputTheory leftTheory, upTheory, rightTheory, downTheory;
	InputTheory pinkSqTheory, yellowSqTheory, GraySqTheory;
};

class WorldVarManager : AbstractVarContainer
{
public:
	WorldVarManager(int knownVarCount)
	{
		for (int i = 0; i < knownVarCount; i++)
			knownVariables.push_back(0);
	}

	void AddHiddenVar()
	{
		hiddenVariables.push_back(0);
	}

	void SetVar(int varNum, int value)
	{
		if (varNum < knownVariables.size())
		{

			knownVariables[varNum] = value;
		}
		else if (varNum < knownVariables.size() + hiddenVariables.size())
		{
			hiddenVariables[varNum - knownVariables.size()] = value;
		}
	}

	int getNumVars()
	{
		return knownVariables.size() + hiddenVariables.size();
	}

	int getValueOfVar(int varNum)
	{
		if (varNum < knownVariables.size())
		{

			return knownVariables[varNum];
		}
		else if (varNum < knownVariables.size() + hiddenVariables.size())
		{
			return hiddenVariables[varNum - knownVariables.size()];
		}
		else
			return 0;
	}

private:
	std::vector<int> knownVariables;
	std::vector<int> hiddenVariables;
};