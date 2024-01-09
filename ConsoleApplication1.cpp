#include <souffle/SouffleInterface.h>
#include <string>
#include <iostream>
#include "TestAgent.h"
#include <thread>
#include <mutex>

souffle::SouffleProgram* prog;
TestAgent* agent;
std::mutex mtx;
bool finished = false;

void Reason() {
    while (true) {
        mtx.lock();
        bool flag = false;
        souffle::Relation* relActionBegin = prog->getRelation("ActionBegin");
        souffle::Relation* relActionComplete = prog->getRelation("ActionComplete");
        for (auto& output : *relActionBegin) {
            std::string treeName;
            int nodeNum;
            std::string actionName;
            output >> treeName >> nodeNum >> actionName;
            souffle::tuple compTuple(relActionComplete);
            compTuple << treeName << nodeNum;
            if (!relActionComplete->contains(compTuple)) {
                agent->ExecuteAction(actionName);
                flag = true;
                relActionComplete->insert(compTuple);
            }
        }
        if(flag)
            prog->run();
        souffle::Relation* relFinish = prog->getRelation("Finish");
        souffle::tuple testFinish(relFinish);
        testFinish << "ruleDemo" << -1 << 1;
        if(relFinish->contains(testFinish)) {
            finished = true;
            mtx.unlock();
			break;
		}
		mtx.unlock();
    }
    
}

int main() {
    
    agent = new TestAgent();
    prog = souffle::ProgramFactory::newInstance("ruleDemo");
    prog->loadAll("facts");

    if (souffle::Relation* relStart = prog->getRelation("Start")) {
        souffle::tuple myTuple(relStart);
        myTuple << "ruleDemo" << souffle::RamSigned(-1);
        relStart->insert(myTuple);
    }
    else {
        std::cerr << "Failed to get input relation\n";
        return 1;
    }
    prog->run();
    std::thread t(Reason);
    t.detach();
    int r;
    std::cin >> r;
    if (souffle::Relation* relIntAttr = prog->getRelation("IntAttrInstance")) {
        souffle::tuple myTuple(relIntAttr);
        relIntAttr->begin();
        myTuple << "ruleDemo" << "TestAgent" << "statisticAccuracy" << souffle::RamSigned(r);
        relIntAttr->insert(myTuple);

    }
    else {
        std::cerr << "Failed to get input relation\n";
        return 1;
    }
    int s;
    std::cin >> s;
    if (souffle::Relation* relIntAttr = prog->getRelation("IntAttrInstance")) {
        souffle::tuple myTuple(relIntAttr);
        relIntAttr->begin();
        myTuple << "ruleDemo" << "TestAgent" << "planeNum" << souffle::RamSigned(s);
        relIntAttr->insert(myTuple);

    }
    else {
        std::cerr << "Failed to get input relation\n";
        return 1;
    }
    prog->run();
    /*bool flag = false;
    souffle::Relation* relActionBegin = prog->getRelation("ActionBegin");
    souffle::Relation* relActionComplete = prog->getRelation("ActionComplete");
    for (auto& output : *relActionBegin) {
        std::string treeName;
        int nodeNum;
        std::string actionName;
        output >> treeName >> nodeNum >> actionName;
        souffle::tuple compTuple(relActionComplete);
        compTuple << treeName << nodeNum;
        if (!relActionComplete->contains(compTuple)) {
            agent->ExecuteAction(actionName);
            flag = true;
            relActionComplete->insert(compTuple);
        }
    }
    if (flag)
        prog->run();*/
    while (!finished);
    if (finished) {
		std::cout << "finished\n";
        prog->printAll();
    }
    delete prog;
    return 0;
}