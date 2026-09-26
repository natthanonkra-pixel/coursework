#include "IrrigationValve/IrrigationValve.h"
#include <iostream>

using namespace std;

int main() {
    // สร้างวาล์ว 3 ตัวเก็บไว้ใน array
    IrrigationValve valves[3];

    // ตั้งค่าเริ่มต้นให้วาล์วแต่ละตัว
    valves[0].setupValve("V01", "Salad_Zone", 5.0);
    valves[1].setupValve("V02", "Fruit_Zone", 8.0);
    valves[2].setupValve("V03", "Nursery_Zone", 3.0);

    // สมมติว่านี่คือ ID ที่เซิร์ฟเวอร์กลางส่งคำสั่งมา
    string target_id;
    string command;

    cout << "Enter Valve ID: ";
    cin >> target_id;

    cout << "Enter Command (OPEN/CLOSE): ";
    cin >> command; // หรือ "CLOSE"

    bool found = false;

    // วนลูปค้นหาวาล์วที่มี ID ตรงกับคำสั่ง
    for (int i = 0; i < 3; i++) {
        if (valves[i].getId() == target_id) {
            found = true;

            if (command == "OPEN") {
                valves[i].openValve();
            } else if (command == "CLOSE") {
                valves[i].closeValve();
            }

            break; // เจอแล้วไม่ต้องวนต่อ
        }
    }

    if (!found) {
        cout << "Error: Valve ID not found!" << endl;
    }

    // แสดงสถานะของวาล์วทั้ง 3 ตัว
    cout << "----- Valve Status -----" << endl;
    for (int i = 0; i < 3; i++) {
        valves[i].printStatus();
        cout << "-------------------------" << endl;
    }

    return 0;
}