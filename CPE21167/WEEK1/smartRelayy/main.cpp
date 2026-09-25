#include <iostream>
#include "smartRelay.h"

int main() {
    // 1. สร้างวัตถุพร้อม Data Member ครบถ้วน
    smartRelay relay("AA:11:BB:22:CC:33", "Smart Air ", 1800.0);

    // 2. เรียกแสดงรายงานสรุป
    std::cout << "--- Initial Status ---" << std::endl;
    std::cout << relay.getSummaryReport() << std::endl;

    // 3. เปิดใช้งานอุปกรณ์
    relay.turnOn();
    std::cout << "\n--- After Turning On ---" << std::endl;
    std::cout << relay.getSummaryReport() << std::endl;

    // 4. ตรวจสอบสถานะก่อนให้ผู้ใช้กรอกข้อมูล
    if (relay.getStatus()) {
        std::cout << "\n[main decision]: Device is ON, proceeding to energy calculation." << std::endl;

        int hours;
        double rate;

        // รับค่าชั่วโมงใช้งานและอัตราค่าไฟจากผู้ใช้
        std::cout << "Enter usage hours: ";
        std::cin >> hours;

        std::cout << "Enter rate per unit (THB): ";
        std::cin >> rate;

        double totalCost = relay.calculateEnergyCost(hours, rate);

        std::cout << "\nUsage: " << hours << " hours | Rate: " << rate << " THB/unit" << std::endl;
        std::cout << "Total Cost: " << totalCost << " THB" << std::endl;
    }

    return 0;
}