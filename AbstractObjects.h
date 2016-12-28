#pragma once

class AbstractVarContainer
{
public:
	virtual int getNumVars() = 0;
	virtual int getValueOfVar(int varNum) = 0;
};

