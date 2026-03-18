#ifndef CONSTRUCTIONCOMPANY_H
#define CONSTRUCTIONCOMPANY_H

#include <string>
#include <vector>
#include "ConstructionSite.h"

using namespace std;

class ConstructionCompany {
private:
    string name;
    double budget;
    vector<ConstructionSite*> sites;
    vector<Machine*> machines;
    double totalPurchaseCosts;

public:
    ConstructionCompany(const string& n, double b);
    ~ConstructionCompany();

    void addConstructionSite(ConstructionSite* site);
    void buyMachine(Machine* machine);
    void assignMachineToSite(int machineIndex, int siteIndex);

    void simulateWeekForAll();

    void pauseSite(int index);
    void resumeSite(int index);

    void printCompanyStats() const;
    void printAllSites() const;
    void printAllMachines() const;
};

#endif
