#pragma once

#include <vector>
#include "AIData.h"
#include "PuzzleData.h"

class DeductiveAI
{
public:
	DeductiveAI();
	~DeductiveAI();

	std::vector<Input> FindSolution(VisibleState state, Theory theory);
};

