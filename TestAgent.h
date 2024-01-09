#pragma once
#ifndef _TESTAGENT_H_
#define _TESTAGENT_H_
#include "BasicAgent.h"
#include <string>

class TestAgent : public BasicAgent
{
	int statisticAccuracy;
public:
	TestAgent();
	~TestAgent();
	void Track();
	void Transmit1();
	void Transmit2();
	void ExecuteAction(std::string actionName);
};

#endif
