#ifndef ENVIRONMENT_SENSOR_H
#define ENVIRONMENT_SENSOR_H

#include <string>

class EnvironmentSensor {
private:
    std::string sensor_id;
    float temperature;
    float humidity;
    int error_count;

public:
    // Constructor กำหนดค่าเริ่มต้นให้กับตัวแปร
    EnvironmentSensor();

    // Setter Method และ Validation
    void initSensor(const std::string& id);
    bool updateReadings(float temp, float hum);

    // Getter Methods
    float getTemperature() const;
    float getHumidity() const;
    int getErrorCount() const;

    // Display Method
    void display() const;
};

#endif // ENVIRONMENT_SENSOR_H