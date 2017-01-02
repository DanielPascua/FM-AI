#include "AIData.h"

using namespace std;

WorldVarManager::WorldVarManager(int knownVarCount)
{
	for (int i = 0; i < knownVarCount; i++)
		knownVariables.push_back(0);
}

void WorldVarManager::AddHiddenVar()
{
	hiddenVariables.push_back(0);
}

void WorldVarManager::SetVar(int varNum, int value)
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

int WorldVarManager::getNumVars()
{
	return knownVariables.size() + hiddenVariables.size();
}

int WorldVarManager::getValueOfVar(int varNum)
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