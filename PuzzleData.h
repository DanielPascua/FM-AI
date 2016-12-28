#pragma once

#include <vector>
#include "AbstractObjects.h"

static enum PuzzleStatus {NO_X_HIT, RED_X_HIT, CLEARED};
static enum Input {LEFT, UP, RIGHT, DOWN, RESET}; //All allowed input for communicating with a puzzle

//Things about the puzzle that always remain the same
struct StaticState
{
	std::vector<std::pair<int, int>> yellowSquares, pinkSquares, graySquares; //list of (x,y) square positions
	std::pair<int, int> redX; //(x,y)
	std::pair<int, int> blueX; //(x,y)
};

//Things about the puzzle that can change
struct DynamicState : public AbstractVarContainer
{
	bool isDark;
	std::pair<int, int> circlePos; //(x,y) starting at 0, (-1,-1) if unknown
	PuzzleStatus puzzleStatus;

	int getNumVars() { return 4; }

	int getValueOfVar(int varNum)
	{
		int result = 0;
		switch (varNum)
		{
		case 0:
			if (isDark)
				result = 1;
			else
				result = 0;
			break;
		case 1:
			result = circlePos.first;
			break;
		case 2:
			result = circlePos.second;
			break;
		case 3:
			result = (int)puzzleStatus;
			break;
		default:
			result = 0;
		}
		return result;
	}
};

struct VisibleState
{
	StaticState staticState;
	DynamicState dynamicState;
};