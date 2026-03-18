#include <iostream>
#include "Machine.h"

Machine::Machine(const string& n, double pCost, double wCost, double wMat)
    : name(n), purchaseCost(pCost), weeklyServiceCost(wCost), weeklyMaterialUse(wMat) {}

Machine::~Machine() {}

string Machine::getName() const { return name; }
double Machine::getPurchaseCost() const { return purchaseCost; }
double Machine::getWeeklyServiceCost() const { return weeklyServiceCost; }
double Machine::getWeeklyMaterialUse() const { return weeklyMaterialUse; }

void Machine::printInfo() const {
    cout << "Техника: " << name
         << ", цена покупки: " << purchaseCost
         << ", эксплуатация/неделя: " << weeklyServiceCost
         << ", материалы/топливо/неделя: " << weeklyMaterialUse << endl;
}

Bulldozer::Bulldozer() : Machine("Бульдозер", 80000, 5000, 300) {}
bool Bulldozer::canWorkInPhase(ConstructionPhase phase) const { return phase == EARTHWORKS; }
double Bulldozer::getWeeklyProductivity(ConstructionPhase phase) const {
    return (phase == EARTHWORKS) ? 250.0 : 0.0;
}

DumpTruck::DumpTruck() : Machine("Самосвал", 70000, 4500, 280) {}
bool DumpTruck::canWorkInPhase(ConstructionPhase phase) const { return phase == EARTHWORKS; }
double DumpTruck::getWeeklyProductivity(ConstructionPhase phase) const {
    return (phase == EARTHWORKS) ? 200.0 : 0.0;
}

Crane::Crane() : Machine("Кран", 150000, 9000, 500) {}
bool Crane::canWorkInPhase(ConstructionPhase phase) const { return phase == FRAME; }
double Crane::getWeeklyProductivity(ConstructionPhase phase) const {
    return (phase == FRAME) ? 180.0 : 0.0;
}

Lift::Lift() : Machine("Подъемник", 60000, 3500, 180) {}
bool Lift::canWorkInPhase(ConstructionPhase phase) const {
    return phase == FRAME || phase == FINISHING;
}
double Lift::getWeeklyProductivity(ConstructionPhase phase) const {
    if (phase == FRAME) return 80.0;
    if (phase == FINISHING) return 120.0;
    return 0.0;
}

WeldingMachine::WeldingMachine() : Machine("Сварочный аппарат", 25000, 1500, 100) {}
bool WeldingMachine::canWorkInPhase(ConstructionPhase phase) const { return phase == FRAME; }
double WeldingMachine::getWeeklyProductivity(ConstructionPhase phase) const {
    return (phase == FRAME) ? 90.0 : 0.0;
}

PlasterStation::PlasterStation() : Machine("Штукатурная станция", 40000, 2500, 220) {}
bool PlasterStation::canWorkInPhase(ConstructionPhase phase) const { return phase == FINISHING; }
double PlasterStation::getWeeklyProductivity(ConstructionPhase phase) const {
    return (phase == FINISHING) ? 220.0 : 0.0;
}
