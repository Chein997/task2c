#include <iostream>
#include "ConstructionCompany.h"

ConstructionCompany::ConstructionCompany(const string& n, double b)
    : name(n), budget(b), totalPurchaseCosts(0) {}

ConstructionCompany::~ConstructionCompany() {
    for (size_t i = 0; i < sites.size(); i++) {
        delete sites[i];
    }
    sites.clear();

    for (size_t i = 0; i < machines.size(); i++) {
        delete machines[i];
    }
    machines.clear();
}

void ConstructionCompany::addConstructionSite(ConstructionSite* site) {
    if (site != nullptr) {
        sites.push_back(site);
    }
}

void ConstructionCompany::buyMachine(Machine* machine) {
    if (machine == nullptr) return;

    if (budget >= machine->getPurchaseCost()) {
        budget -= machine->getPurchaseCost();
        totalPurchaseCosts += machine->getPurchaseCost();
        machines.push_back(machine);
        cout << "Куплена техника: " << machine->getName() << endl;
    } else {
        cout << "Недостаточно денег для покупки.\n";
        delete machine;
    }
}

void ConstructionCompany::assignMachineToSite(int machineIndex, int siteIndex) {
    if (machineIndex < 0 || machineIndex >= (int)machines.size()) return;
    if (siteIndex < 0 || siteIndex >= (int)sites.size()) return;

    sites[siteIndex]->assignMachine(machines[machineIndex]);
}

void ConstructionCompany::simulateWeekForAll() {
    cout << "\n=== Новая неделя ===\n";
    for (size_t i = 0; i < sites.size(); i++) {
        sites[i]->simulateWeek();
    }
}

void ConstructionCompany::pauseSite(int index) {
    if (index >= 0 && index < (int)sites.size()) {
        sites[index]->pause();
    }
}

void ConstructionCompany::resumeSite(int index) {
    if (index >= 0 && index < (int)sites.size()) {
        sites[index]->resume();
    }
}

void ConstructionCompany::printCompanyStats() const {
    double totalMoney = totalPurchaseCosts;
    double totalMaterials = 0.0;

    for (size_t i = 0; i < sites.size(); i++) {
        totalMoney += sites[i]->getMoneySpent();
        totalMaterials += sites[i]->getMaterialsSpent();
    }

    cout << "\n===== Статистика компании =====\n";
    cout << "Компания: " << name << endl;
    cout << "Остаток бюджета: " << budget << endl;
    cout << "Затраты на технику: " << totalPurchaseCosts << endl;
    cout << "Общие денежные затраты: " << totalMoney << endl;
    cout << "Общие затраты материалов: " << totalMaterials << endl;
}

void ConstructionCompany::printAllSites() const {
    for (size_t i = 0; i < sites.size(); i++) {
        cout << "\nОбъект #" << i + 1 << endl;
        sites[i]->printInfo();
    }
}

void ConstructionCompany::printAllMachines() const {
    for (size_t i = 0; i < machines.size(); i++) {
        cout << "[" << i << "] ";
        machines[i]->printInfo();
    }
}
