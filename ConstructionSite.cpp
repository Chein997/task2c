#include <iostream>
#include "ConstructionSite.h"

ConstructionSite::ConstructionSite(const string& n, int f, double area)
    : name(n), floors(f), totalArea(area),
      phase(EARTHWORKS), status(ACTIVE),
      earthworksDone(0), frameDone(0), finishingDone(0),
      moneySpent(0), materialsSpent(0) {}

ConstructionSite::~ConstructionSite() {
    assignedMachines.clear();
}

string ConstructionSite::getName() const { return name; }
int ConstructionSite::getFloors() const { return floors; }
double ConstructionSite::getArea() const { return totalArea; }
ConstructionPhase ConstructionSite::getPhase() const { return phase; }
ConstructionStatus ConstructionSite::getStatus() const { return status; }
double ConstructionSite::getMoneySpent() const { return moneySpent; }
double ConstructionSite::getMaterialsSpent() const { return materialsSpent; }

void ConstructionSite::pause() {
    if (status == ACTIVE) status = PAUSED;
}

void ConstructionSite::resume() {
    if (status == PAUSED) status = ACTIVE;
}

bool ConstructionSite::isCompleted() const {
    return status == DONE;
}

void ConstructionSite::assignMachine(Machine* machine) {
    if (machine != nullptr) {
        assignedMachines.push_back(machine);
    }
}

void ConstructionSite::clearAssignedMachines() {
    assignedMachines.clear();
}

double ConstructionSite::getPhaseTarget() const {
    switch (phase) {
        case EARTHWORKS: return totalArea * 0.25;
        case FRAME: return totalArea * 0.45;
        case FINISHING: return totalArea * 0.30;
        default: return 0.0;
    }
}

double ConstructionSite::getPhaseProgress() const {
    switch (phase) {
        case EARTHWORKS: return earthworksDone;
        case FRAME: return frameDone;
        case FINISHING: return finishingDone;
        default: return totalArea;
    }
}

void ConstructionSite::addProgress(double amount) {
    switch (phase) {
        case EARTHWORKS: earthworksDone += amount; break;
        case FRAME: frameDone += amount; break;
        case FINISHING: finishingDone += amount; break;
        default: break;
    }
}

void ConstructionSite::nextPhase() {
    if (phase == EARTHWORKS) phase = FRAME;
    else if (phase == FRAME) phase = FINISHING;
    else if (phase == FINISHING) {
        phase = COMPLETED;
        status = DONE;
    }
}

void ConstructionSite::simulateWeek() {
    if (status == PAUSED) {
        cout << "Объект \"" << name << "\" приостановлен.\n";
        return;
    }

    if (status == DONE) {
        cout << "Объект \"" << name << "\" уже завершен.\n";
        return;
    }

    double weeklyProgress = 0.0;
    double weeklyMoney = 0.0;
    double weeklyMaterials = 0.0;

    for (size_t i = 0; i < assignedMachines.size(); i++) {
        Machine* m = assignedMachines[i];
        if (m->canWorkInPhase(phase)) {
            weeklyProgress += m->getWeeklyProductivity(phase);
            weeklyMoney += m->getWeeklyServiceCost();
            weeklyMaterials += m->getWeeklyMaterialUse();
        }
    }

    if (weeklyProgress == 0) {
        cout << "На объекте \"" << name << "\" нет подходящей техники.\n";
        return;
    }

    double remain = getPhaseTarget() - getPhaseProgress();
    if (weeklyProgress > remain) weeklyProgress = remain;

    addProgress(weeklyProgress);
    moneySpent += weeklyMoney;
    materialsSpent += weeklyMaterials;

    cout << "Объект: " << name << endl;
    cout << "Фаза: " << phaseToString() << endl;
    cout << "Прогресс за неделю: " << weeklyProgress << " м2" << endl;
    cout << "Деньги за неделю: " << weeklyMoney << endl;
    cout << "Материалы за неделю: " << weeklyMaterials << endl;

    if (getPhaseProgress() >= getPhaseTarget()) {
        cout << "Фаза завершена: " << phaseToString() << endl;
        nextPhase();

        if (status == DONE)
            cout << "Объект полностью завершен.\n";
    }
}

string ConstructionSite::phaseToString() const {
    switch (phase) {
        case EARTHWORKS: return "Земляные работы";
        case FRAME: return "Каркас";
        case FINISHING: return "Отделка";
        case COMPLETED: return "Завершено";
        default: return "Неизвестно";
    }
}

string ConstructionSite::statusToString() const {
    switch (status) {
        case ACTIVE: return "Активен";
        case PAUSED: return "Приостановлен";
        case DONE: return "Завершен";
        default: return "Неизвестно";
    }
}

void ConstructionSite::printInfo() const {
    cout << "Название: " << name << endl;
    cout << "Этажей: " << floors << endl;
    cout << "Площадь: " << totalArea << endl;
    cout << "Фаза: " << phaseToString() << endl;
    cout << "Статус: " << statusToString() << endl;
    cout << "Потрачено денег: " << moneySpent << endl;
    cout << "Потрачено материалов: " << materialsSpent << endl;
}
