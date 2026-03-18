#ifndef CONSTRUCTIONSITE_H
#define CONSTRUCTIONSITE_H

#include <string>
#include <vector>
#include "Machine.h"

using namespace std;

class ConstructionSite {
private:
    string name;
    int floors;
    double totalArea;

    ConstructionPhase phase;
    ConstructionStatus status;

    double earthworksDone;
    double frameDone;
    double finishingDone;

    vector<Machine*> assignedMachines;

    double moneySpent;
    double materialsSpent;

public:
    ConstructionSite(const string& n, int f, double area);
    ~ConstructionSite();

    string getName() const;
    int getFloors() const;
    double getArea() const;
    ConstructionPhase getPhase() const;
    ConstructionStatus getStatus() const;
    double getMoneySpent() const;
    double getMaterialsSpent() const;

    void pause();
    void resume();
    bool isCompleted() const;

    void assignMachine(Machine* machine);
    void clearAssignedMachines();

    double getPhaseTarget() const;
    double getPhaseProgress() const;
    void addProgress(double amount);
    void nextPhase();

    void simulateWeek();

    string phaseToString() const;
    string statusToString() const;
    void printInfo() const;
};

#endif
