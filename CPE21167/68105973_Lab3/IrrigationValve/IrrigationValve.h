#ifndef IRRIGATIONVALVE_H
#define IRRIGATIONVALVE_H

#include <string>
using namespace std;

class IrrigationValve {
private:
    string valve_id;
    string zone_name;
    bool is_open;
    float flow_rate;

public:
    
    void setupValve(string id, string zone, float flow);

    void openValve();

    void closeValve();

    string getId();

    void printStatus();
};

#endif