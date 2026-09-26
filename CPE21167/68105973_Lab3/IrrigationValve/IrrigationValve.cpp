#include "IrrigationValve.h"
#include <iostream>

using namespace std;

void IrrigationValve::setupValve(string id, string zone, float flow) {
    valve_id = id;
    zone_name = zone;
    is_open = false;
    flow_rate = flow;
}

void IrrigationValve::openValve() {
    is_open = true;
}

void IrrigationValve::closeValve() {
    is_open = false;
}

string IrrigationValve::getId() {
    return valve_id;
}

void IrrigationValve::printStatus() {
    cout << "Valve ID: " << valve_id << endl;
    cout << "Zone: " << zone_name << endl;
    cout << "Status: " << (is_open ? "OPEN" : "CLOSED") << endl;
    cout << "Flow Rate: " << flow_rate << " L/min" << endl;
}