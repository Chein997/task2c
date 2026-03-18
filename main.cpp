#include <iostream>
#include <locale>
#include "ConstructionCompany.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    ConstructionCompany company("СтройИнвест", 1000000);

    company.addConstructionSite(new ConstructionSite("ЖК Северный", 12, 3000));
    company.addConstructionSite(new ConstructionSite("Бизнес-центр Орбита", 8, 2000));

    company.buyMachine(new Bulldozer());
    company.buyMachine(new DumpTruck());
    company.buyMachine(new Crane());
    company.buyMachine(new Lift());
    company.buyMachine(new WeldingMachine());
    company.buyMachine(new PlasterStation());

    company.assignMachineToSite(0, 0);
    company.assignMachineToSite(1, 0);
    company.assignMachineToSite(2, 0);
    company.assignMachineToSite(3, 0);
    company.assignMachineToSite(4, 0);
    company.assignMachineToSite(5, 0);

    company.assignMachineToSite(0, 1);
    company.assignMachineToSite(1, 1);
    company.assignMachineToSite(2, 1);
    company.assignMachineToSite(3, 1);
    company.assignMachineToSite(4, 1);
    company.assignMachineToSite(5, 1);

    for (int week = 1; week <= 10; week++) {
        cout << "\n******** НЕДЕЛЯ " << week << " ********\n";

        if (week == 4) company.pauseSite(1);
        if (week == 6) company.resumeSite(1);

        company.simulateWeekForAll();
    }

    company.printAllSites();
    company.printCompanyStats();

    return 0;
}
