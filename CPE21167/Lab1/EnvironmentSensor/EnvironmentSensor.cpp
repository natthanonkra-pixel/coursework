#include "EnvironmentSensor.h"
#include <iostream>

// กำหนดค่าเริ่มต้น: temperature = 0.0, humidity = 0.0, error_count = 0
EnvironmentSensor::EnvironmentSensor() 
    : sensor_id(""), temperature(0.0f), humidity(0.0f), error_count(0) {}

void EnvironmentSensor::initSensor(const std::string& id) {
    sensor_id = id;
}

bool EnvironmentSensor::updateReadings(float temp, float hum) {
    // เงื่อนไข Validation:
    // 1. อุณหภูมิ -10.0 ถึง 60.0 องศาเซลเซียส
    // 2. ความชื้น 0.0 ถึง 100.0 เปอร์เซ็นต์
    if (temp >= -10.0f && temp <= 60.0f && hum >= 0.0f && hum <= 100.0f) {
        temperature = temp;
        humidity = hum;
        return true;
    } else {
        error_count++;
        return false;
    }
}

float EnvironmentSensor::getTemperature() const {
    return temperature;
}

float EnvironmentSensor::getHumidity() const {
    return humidity;
}

int EnvironmentSensor::getErrorCount() const {
    return error_count;
}

void EnvironmentSensor::display() const {
    std::cout << "========== Sensor Info ==========" << std::endl;
    std::cout << "Sensor ID   : " << sensor_id << std::endl;
    std::cout << "Temperature : " << temperature << " C" << std::endl;
    std::cout << "Humidity    : " << humidity << " %" << std::endl;
    std::cout << "Error Count : " << error_count << std::endl;
    std::cout << "=================================" << std::endl;
}