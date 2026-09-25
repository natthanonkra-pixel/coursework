#include <iostream>
#include "smartRelay.h"

int main() {
    // กำหนดค่าทดสอบ หลอดไฟ 15.5 วัตต์ ตามตัวอย่างในโจทย์ข้อ 2
    smartRelay bulb("AA:BB:CC:11:22:33", "ไฟห้องน้ำ", 15.5f);

    // 1. ดึงรายงานสรุป (getSummaryReport)
    std::cout << "--- Initial Report ---" << std::endl;
    std::cout << bulb.getSummaryReport() << std::endl;

    // เปิดใช้งานอุปกรณ์
    bulb.turnOn();
    std::cout << "\n--- After Turn On ---" << std::endl;
    std::cout << bulb.getSummaryReport() << std::endl;

    // 2. ดึงข้อมูลสถานะไปประมวลผลต่อ (getStatus)
    if (bulb.getStatus()) {
        std::cout << "\n[Server Log]: Device is active. Processing energy calculation..." << std::endl;

        // 3. คำนวณอัตราการใช้พลังงาน (calculateEnergyCost) - รับค่าจากผู้ใช้
        int hours;
        float rate;

        std::cout << "Enter usage hours: ";
        std::cin >> hours;

        std::cout << "Enter rate per unit (THB): ";
        std::cin >> rate;

        float cost = bulb.calculateEnergyCost(hours, rate);

        std::cout << "Energy Cost for " << hours << " hours (" << rate << " THB/unit): "
                  << cost << " THB" << std::endl;
    }

    return 0;
}