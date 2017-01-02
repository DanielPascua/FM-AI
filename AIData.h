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
	WorldVarManager(int knownVarCount);

	void AddHiddenVar();
	void SetVar(int varNum, int value);
	int getNumVars();
	int getValueOfVar(int varNum);

private:
	std::vector<int> knownVariables;
	std::vector<int> hiddenVariables;
};

struct WorldTheory
{

};