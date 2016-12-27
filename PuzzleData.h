#pragma once

#include <vector>

static enum PuzzleStatus {NO_X_HIT, RED_X_HIT, CLEARED};
static enum Input {LEFT, UP, RIGHT, DOWN, RESET}; //All allowed input for communicating with a puzzle

//Things about the puzzle that always remain the same
struct StaticState
{
	std::vector<std::pair<int, int>> yellowSquares, pinkSquares, greySquares; //list of (x,y) square positions
	std::pair<int, int> redX; //(x,y)
	std::pair<int, int> blueX; //(x,y)
};

//Things about the puzzle that can change
struct DynamicState
{
	bool isDark;
	std::pair<int, int> circlePos; //(x,y) starting at 0, (-1,-1) if unknown
	PuzzleStatus puzzleStatus;
};

struct VisibleState
{
	StaticState staticState;
	DynamicState dynamicState;
};