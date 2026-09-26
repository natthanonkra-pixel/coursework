#ifndef SMARTRELAY_H
#define SMARTRELAY_H

#include <string>

class smartRelay {
private:
    std::string mac_address;
    std::string device_name;
    bool is_on;
    double power_watt;

public:
    // Constructor
    smartRelay(std::string mac, std::string name, double watt);

    // Control Methods
    void turnOn();
    void turnOff();

    // Getter & Member Methods
    bool getStatus() const;
    double calculateEnergyCost(int hours, double rate_per_unit) const;
    std::string getSummaryReport() const;
};

#endif