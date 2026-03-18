#ifndef MACHINE_H
#define MACHINE_H

#include <string>
using namespace std;

enum ConstructionPhase {
    EARTHWORKS,
    FRAME,
    FINISHING,
    COMPLETED
};

enum ConstructionStatus {
    ACTIVE,
    PAUSED,
    DONE
};

class Machine {
protected:
    string name;
    double purchaseCost;
    double weeklyServiceCost;
    double weeklyMaterialUse;

public:
    Machine(const string& n, double pCost, double wCost, double wMat);
    virtual ~Machine();

    string getName() const;
    double getPurchaseCost() const;
    double getWeeklyServiceCost() const;
    double getWeeklyMaterialUse() const;

    virtual bool canWorkInPhase(ConstructionPhase phase) const = 0;
    virtual double getWeeklyProductivity(ConstructionPhase phase) const = 0;
    virtual void printInfo() const;
};

class Bulldozer : public Machine {
public:
    Bulldozer();
    bool canWorkInPhase(ConstructionPhase phase) const override;
    double getWeeklyProductivity(ConstructionPhase phase) const override;
};

class DumpTruck : public Machine {
public:
    DumpTruck();
    bool canWorkInPhase(ConstructionPhase phase) const override;
    double getWeeklyProductivity(ConstructionPhase phase) const override;
};

class Crane : public Machine {
public:
    Crane();
    bool canWorkInPhase(ConstructionPhase phase) const override;
    double getWeeklyProductivity(ConstructionPhase phase) const override;
};

class Lift : public Machine {
public:
    Lift();
    bool canWorkInPhase(ConstructionPhase phase) const override;
    double getWeeklyProductivity(ConstructionPhase phase) const override;
};

class WeldingMachine : public Machine {
public:
    WeldingMachine();
    bool canWorkInPhase(ConstructionPhase phase) const override;
    double getWeeklyProductivity(ConstructionPhase phase) const override;
};

class PlasterStation : public Machine {
public:
    PlasterStation();
    bool canWorkInPhase(ConstructionPhase phase) const override;
    double getWeeklyProductivity(ConstructionPhase phase) const override;
};

#endif
