// Including necessary header files
#include "OneWire_Methods.cpp"  // OneWire communication
#include "DS2781.cpp"            // DS2781 sensor
#include "mbed.h"                

// Defining DigitalInOut pin for OneWire communication
DigitalInOut one_wire_pin(PC_12);

int main() {
    // Variable declarations for storing voltage and current readings
    int VoltageReading, CurrentReading;
    float Voltage, Current;

    // Reading voltage from the sensor
    VoltageReading = ReadVoltage();
    // Converting voltage reading to actual voltage value
    Voltage = VoltageReading * 0.00967;

    // Reading current from the sensor
    CurrentReading = ReadCurrent();
    // Converting current reading to actual current value
    Current = CurrentReading / 6400.0;

    // Printing out the voltage and current readings
    lcd.printf("Voltage: %.2f V\n", Voltage);
    lcd.printf("Current: %.2f A\n", Current);

    // Returning 0 to indicate successful execution
    return 0;
}
