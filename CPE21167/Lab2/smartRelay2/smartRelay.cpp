#include "smartRelay.h"
#include <sstream>
#include <iomanip>

smartRelay::smartRelay(std::string mac, std::string name, float watt)
    : mac_address(mac), device_name(name), is_on(false), power_watt(watt) {}

void smartRelay::turnOn() {
    is_on = true;
}

void smartRelay::turnOff() {
    is_on = false;
}

bool smartRelay::getStatus() const {
    return is_on;
}

float smartRelay::calculateEnergyCost(int hours, float rate_per_unit) const {
    // คำนวณหน่วยไฟฟ้า (kWh) = (Watt * Hours) / 1000
    float energy_kwh = (power_watt * hours) / 1000.0f;
    return energy_kwh * rate_per_unit;
}

std::string smartRelay::getSummaryReport() const {
    std::ostringstream oss;
    oss << "Device: " << device_name 
        << " | MAC: " << mac_address 
        << " | Power: " << std::fixed << std::setprecision(1) << power_watt << "W"
        << " | Status: " << (is_on ? "ON" : "OFF");
    return oss.str();
}