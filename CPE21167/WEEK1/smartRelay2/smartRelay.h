#ifndef SMARTRELAY_H
#define SMARTRELAY_H

#include <string>

class smartRelay {
private:
    std::string mac_address;
    std::string device_name;
    bool is_on;
    float power_watt; // เปลี่ยนเป็น float ตามโจทย์ข้อ 2

public:
    // Constructor
    smartRelay(std::string mac, std::string name, float watt);

    // Control Methods
    void turnOn();
    void turnOff();

    // Getter & Member Methods
    bool getStatus() const;
    float calculateEnergyCost(int hours, float rate_per_unit) const;
    std::string getSummaryReport() const;
};

#endif