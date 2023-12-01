#include <Wire.h>
#include "RTClib.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
uint8_t sensor1[8] = {0x28, 0x3D, 0xB2, 0x75, 0xD0, 0x01, 0x3C, 0x9C};
uint8_t sensor2[8] = {0x28, 0x7A, 0x73, 0x75, 0xD0, 0x01, 0x3C,
                      0x83};
uint8_t sensor3[8] = {0x28, 0xDE, 0xFE, 0x75, 0xD0, 0x01, 0x3C,
                      0x24};
uint8_t sensor4[8] = {0x28, 0xF1, 0x5E, 0x75, 0xD0, 0x01, 0x3C,
                      0x85};
uint8_t sensor5[8] = {0x28, 0xA9, 0x54, 0x75, 0xD0, 0x01, 0x3C,
                      0xB7};
uint8_t sensor6[8] = {0x28, 0xA4, 0x1E, 0x75, 0xD0, 0x01, 0x3C,
                      0xA9};
uint8_t sensor7[8] = {0x28, 0xC6, 0x0C, 0x75, 0xD0, 0x01, 0x3C,
                      0xFB};
uint8_t sensor8[8] = {0x28, 0x26, 0xC4, 0x75, 0xD0, 0x01, 0x3C,
                      0xCE};
uint8_t sensor9[8] = {0x28, 0x81, 0xDC, 0x75, 0xD0, 0x01, 0x3C,
                      0x55};
uint8_t sensor10[8] = {0x28, 0x25, 0xAF, 0x75, 0xD0, 0x01, 0x3C,
                       0xF6};
uint8_t sensor11[8] = {0x28, 0xEE, 0x20, 0x08, 0x14, 0x15, 0x01,
                       0x59};
RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday",
                             "Wednesday", "Thursday", "Friday", "Saturday"};
#include <SPI.h>
#include <SD.h>
File myFile;
// change this to match your SD shield or module;
const int chipSelect = 53;
69
#define VIN1 A0 // define the Arduino pin A0 as voltage input (V in)
#define VIN2 A1
#define VIN3 A2
    const float VCC = 5.0;        // supply voltage is from 4.5 to 5.5V.
Normally 5V. const int model = 1; // enter the model number (see below)
float cutOffLimit = 1.01;         // set the current which below that value,
doesn't matter. Or set 0.5 float sensitivity[] = {
    0.185, // for ACS712ELCTR-05B-T
    0.100, // for ACS712ELCTR-20A-T
    0.066  // for ACS712ELCTR-30A-T

};
const float QOV1 = 0.5 * VCC; // set quiescent Output voltage of 0.5V
const float QOV2 = 0.5 * VCC;
const float QOV3 = 0.5 * VCC;
float voltage1; // internal variable for voltage
float voltage2;
float voltage3;
void setup()
{
    Serial.begin(9600);
    sensors.begin();
    while (!Serial)
    {
        ; // wait for serial port to connect. Needed for Leonardo only
    }
    delay(3000); // wait for console opening
    if (!rtc.begin())
    {
        Serial.println("Couldn't find RTC");
    }
    if (rtc.lostPower())
    {
        Serial.println("RTC lost power, lets set the time!");

        // Comment out below lines once you set the date & time.
        // Following line sets the RTC to the date & time this sketch was
        compiled
            rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

        70
        // Following line sets the RTC with an explicit date & time
        // for example to set January 27 2017 at 12:56 you would call:
        // rtc.adjust(DateTime(2017, 1, 27, 12, 56, 0));
    }
    Serial.print("Initializing SD card...");
    if (!SD.begin())
    {
        Serial.println("initialization failed!");
        return;
    }
    Serial.println("initialization done.");
    // open the file. note that only one file can be open at a time,
    // so you have to close this one before opening another.
    myFile = SD.open("test.txt", FILE_WRITE);
    // if the file opened okay, write to it:
    if (myFile)
    {
        Serial.print("Writing to test.txt...");
        // close the file:
        myFile.close();
        Serial.println("done.");
    }
    else
    {
        // if the file didn't open, print an error:
        Serial.println("error opening test.txt");
    }
    // re-open the file for reading:
    myFile = SD.open("test.txt");
    if (myFile)
    {
        Serial.println("test.txt:");
        pinMode(5, OUTPUT);
    }
}
void loop()
{
    DateTime now = rtc.now();

    Serial.println(" Date & Time: NOW ");
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    71 Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    sensors.requestTemperatures();
    Serial.print("Sensor 1: ");
    printTemperature(sensor1);
    delay(3000);
    Serial.print("Sensor 2: ");
    printTemperature(sensor2);
    delay(3000);
    Serial.print("Sensor 3: ");
    printTemperature(sensor3);
    delay(3000);
    Serial.print("Sensor 4: ");
    printTemperature(sensor4);
    delay(3000);
    Serial.print("Sensor 5: ");
    printTemperature(sensor5);
    delay(3000);
    Serial.print("Sensor 6: ");
    printTemperature(sensor6);
    delay(3000);
    Serial.print("Sensor 7: ");
    printTemperature(sensor7);
    delay(3000);
    Serial.print("Sensor 8: ");
    printTemperature(sensor8);
    delay(3000);
    Serial.print("Sensor 9: ");
    printTemperature(sensor9);
    delay(3000);
    Serial.print("Sensor 10: ");
    printTemperature(sensor10);
    delay(2000);
    Serial.print("Sensor 11: ");
    printTemperature(sensor11);
    delay(3000);
    Serial.println();
    // read the input on analog pin 0.1.2:
    72 int V1R = analogRead(A3);
    int V2R = analogRead(A4);
    int V3R = analogRead(A5);
    // Convert the analog reading (which goes from 0 - 1023) to a
    voltage(0 - 50V) : float voltage11 = V1R * (5.0 / 1024.0) * 10.1;
    float voltage22 = V2R * (5.0 / 1024.0) * 10.1;
    float voltage33 = V3R * (5.0 / 1024.0) * 10.1;
    Serial.print("V1: ");
    Serial.print(voltage11);
    Serial.println(" V");

    Serial.print("V2: ");
    Serial.print(voltage22);
    Serial.println(" V");

    Serial.print("V3: ");
    Serial.print(voltage33);
    Serial.println(" V");

    myFile = SD.open("test.txt", FILE_WRITE);

    // if the file opened okay, write to it:
    if (myFile)
    {
        Serial.print("Writing to test.txt...");
        myFile.println("testing 1, 2, 3.");
        myFile.println("Current Date & Time: ");
        myFile.print(now.year(), DEC);
        myFile.print('/');
        myFile.print(now.month(), DEC);
        myFile.print('/');
        myFile.print(now.day(), DEC);
        myFile.print(" (");
        myFile.print(daysOfTheWeek[now.dayOfTheWeek()]);
        myFile.print(") ");
        myFile.print(now.hour(), DEC);
        myFile.print(':');
        myFile.print(now.minute(), DEC);
        myFile.print(':');
        myFile.print(now.second(), DEC);
        myFile.println();
        myFile.print("Sensor 1: ");
        printTemperature(sensor1);
        73 myFile.println();
        myFile.print("Sensor 2: ");
        printTemperature(sensor2);
        myFile.println();
        myFile.print("Sensor 3: ");
        printTemperature(sensor3);
        myFile.println();
        myFile.print("Sensor 4: ");
        printTemperature(sensor4);
        myFile.println();
        myFile.print("Sensor 5: ");
        printTemperature(sensor5);
        myFile.println();
        myFile.print("Sensor 6: ");
        printTemperature(sensor6);
        myFile.println();
        myFile.print("Sensor 7: ");
        printTemperature(sensor7);
        myFile.println();
        myFile.print("Sensor 8: ");
        printTemperature(sensor8);
        myFile.println();
        myFile.print("Sensor 9: ");
        printTemperature(sensor9);
        myFile.println();
        myFile.print("Sensor 10: ");
        printTemperature(sensor10);
        myFile.println();
        myFile.print("Sensor 11: ");
        printTemperature(sensor11);
        myFile.println();
        myFile.println();
        myFile.print("V1: ");
        myFile.print(voltage11);
        myFile.print(" V");
        myFile.println();
        myFile.print("V2: ");
        myFile.print(voltage22);
        myFile.print(" V");
        myFile.println();
        74 myFile.print("V3: ");
        myFile.print(voltage33);
        myFile.print(" V");
        myFile.println();
        digitalWrite(5, LOW);
        delay(4000);
        float voltage1_raw = (5.0 / 1023.0) * analogRead(VIN1); // Read the
        voltage from sensor
            voltage1 = voltage1_raw - QOV1 + 0.012; // 0.000 is a value to make
        voltage zero when there is no current float current1 = voltage1 / sensitivity[model];

        float voltage2_raw = (5.0 / 1023.0) * analogRead(VIN2); // Read the
        voltage from sensor
            voltage2 = voltage2_raw - QOV2 + 0.012; // 0.000 is a value to make
        voltage zero when there is no current float current2 = voltage2 / sensitivity[model];
        float voltage3_raw = (5.0 / 1023.0) * analogRead(VIN3); // Read the
        voltage from sensor
            voltage3 = voltage3_raw - QOV3 + 0.012; // 0.000 is a value to make
        voltage zero when there is no current float current3 = voltage3 / sensitivity[model];

        Serial.print(current1, 2);
        Serial.println("A");
        Serial.print(current2, 2);
        Serial.println("A");
        Serial.print(current3, 2);
        Serial.println("A");
        myFile.println();
        myFile.print("current1");
        myFile.print(current1, 2);
        myFile.println("A");
        myFile.print("current2");
        myFile.print(current2, 2);
        myFile.println("A");
        myFile.print("current3");
        myFile.print(current3, 2);
        myFile.println("A");
        myFile.println();
        myFile.println();
        myFile.println();
        myFile.println();
        delay(1000);
        75 digitalWrite(5, HIGH);
        // close the file:
        myFile.close();
        Serial.println("done.");
    }
    else
    {
        // if the file didn't open, print an error:
        Serial.println("error opening test.txt");
    }

    delay(000);
}
void printTemperature(DeviceAddress deviceAddress)
{
    float tempC = sensors.getTempC(deviceAddress);
    Serial.print(tempC);
    Serial.print("C | ");
    Serial.print(DallasTemperature::toFahrenheit(tempC));
    Serial.println("F");
    myFile.print(tempC);
    myFile.print("C | ");
    myFile.print(DallasTemperature::toFahrenheit(tempC));
    myFile.print("F");
}