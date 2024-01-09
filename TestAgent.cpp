#include "TestAgent.h"
#include <iostream>
#include <string>

TestAgent::TestAgent()
{
	statisticAccuracy = 0;
}

TestAgent::~TestAgent()
{
}

void TestAgent::ExecuteAction(std::string actionName) {
	if (actionName == "Track") {
		Track();
	}
	else if (actionName == "Transmit1") {
		Transmit1();
	}
	else if (actionName == "Transmit2") {
		Transmit2();
	}
	else {
		std::cout << "TestAgent::ExecuteAction() - Unknown action: " << actionName << std::endl;
	}
}

void TestAgent::Track() {
	std::cout << "TestAgent::Track()" << std::endl;
}

void TestAgent::Transmit1() {
	std::cout << "TestAgent::Transmit1()" << std::endl;
}

void TestAgent::Transmit2() {
	std::cout << "TestAgent::Transmit2()" << std::endl;
}