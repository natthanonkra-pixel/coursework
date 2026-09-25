#include <iostream>
#include <string>
#include "EnvironmentSensor/EnvironmentSensor.h"

int main() {
    EnvironmentSensor sensor;
    std::string sensor_name;
    float input_temp, input_hum;
    char choice = 'y'; // ตัวแปรเก็บคำตอบว่าจะทำต่อหรือไม่

    // วนลูปทำงานไปเรื่อยๆ ตราบใดที่กด 'y' หรือ 'Y'
    while (choice == 'y' || choice == 'Y') {
        std::cout << "\n===================================" << std::endl;
        
        // 1. ถามชื่อเซ็นเซอร์ในทุกๆ รอบ
        std::cout << "Enter Sensor ID (e.g., Zone_A_DHT): ";
        std::cin >> sensor_name;
        sensor.initSensor(sensor_name);

        // 2. ถามค่าอุณหภูมิและความชื้น
        std::cout << "Enter Temperature (C): ";
        std::cin >> input_temp;
        std::cout << "Enter Humidity (%): ";
        std::cin >> input_hum;

        std::cout << std::endl;

        // 3. ตรวจสอบค่า (ถ้ามั่วจะขึ้นเตือน และนับ Error เพิ่ม)
        if (!sensor.updateReadings(input_temp, input_hum)) {
            std::cout << "[WARNING] Invalid sensor values detected! Data ignored." << std::endl;
        }

        // 4. แสดงผลสรุป
        sensor.display();

        // 5. ถามผู้ใช้ว่าจะทำต่อหรือไม่
        std::cout << "\nDo you want to test again? (y/n): ";
        std::cin >> choice;
    }

    std::cout << "Exiting program... Goodbye!" << std::endl;
    return 0;
}