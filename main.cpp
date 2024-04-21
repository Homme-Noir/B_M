#include "OneWire_Methods.cpp"  // OneWire communication
#include "DS2781.cpp"            // DS2781 sensor
#include "C12832.h"
#include "mbed.h"                

// Defining DigitalInOut pin for OneWire communication
DigitalInOut one_wire_pin(PC_12);
// Initialize LCD
C12832 lcd(D11, D13, D12, D7, D10);

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

    // Convert voltage and current readings to strings
    char voltage_str[16];
    char current_str[16];
    sprintf(voltage_str, "Voltage: %.2f V", Voltage);
    sprintf(current_str, "Current: %.2f A", Current);

    // Clear the LCD screen
    lcd.cls();

    // Display the voltage and current readings on the LCD screen
    lcd.locate(0, 0);
    lcd.printf(voltage_str);
    lcd.locate(0, 10);
    lcd.printf(current_str);

    // Returning 0 to indicate successful execution
    return 0;
}
