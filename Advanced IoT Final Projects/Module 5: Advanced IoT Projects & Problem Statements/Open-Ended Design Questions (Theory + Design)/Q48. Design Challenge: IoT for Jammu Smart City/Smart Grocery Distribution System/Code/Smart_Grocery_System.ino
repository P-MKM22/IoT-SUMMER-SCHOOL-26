/*
Project: Smart Grocery Distribution System
Question: Q48
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Main program for the Smart Grocery Distribution
System. It initializes all hardware modules and
controls the complete workflow.
*/

#include "Config.h"
#include "Credentials.h"
#include "Beneficiaries.h"
#include "Display_Manager.h"
#include "RFID_Manager.h"
#include "Inventory_Manager.h"
#include "Transaction_Manager.h"
#include "Cloud_Manager.h"
#include "Alert_Manager.h"
#include "Helper_Functions.h"

// Hardware objects
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
MFRC522 rfid(RFID_SS_PIN, RFID_RST_PIN);
HX711 scale;

void setup()
{
    Serial.begin(115200);

    Wire.begin();

    SPI.begin();

    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    pinMode(BUTTON_PIN, INPUT_PULLUP);

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        Serial.println("OLED Initialization Failed");

        while (true);
    }

    initializeAlerts();

    initializeRFID();

    initializeLoadCell();

    printProjectInfo();

    showStartupScreen();

    if (connectWiFi())
    {
        printSuccess("Wi-Fi Connected");
    }
    else
    {
        printError("Running Without Internet");
    }

    systemReady();

    showWaitingScreen();
}

void loop()
{
    Beneficiary *person = authenticateBeneficiary();

    if (person == nullptr)
    {
        return;
    }

    authenticationSuccessAlert();

    showAuthenticationSuccess(person);

    printBeneficiary(person);

    Serial.println("Press Button To Dispense Grocery");

    waitForButtonPress();

    float quantity = DEFAULT_RICE_WEIGHT;

    dispenseGrocery(quantity);

    float measuredWeight = readWeight();

    float stockLevel = readStockLevel();

    printInventory(measuredWeight, stockLevel);

    showDistribution(measuredWeight);

    completeTransaction(
        person,
        "Rice",
        measuredWeight
    );

    showTransactionComplete();

    transactionCompleteAlert();

    synchronizeCloud();

    if (isLowStock(stockLevel))
    {
        lowStockAlert();

        showLowStock();

        printError("Inventory Running Low");
    }

    delay(3000);

    clearAlerts();

    resetTransaction();

    systemReady();

    showWaitingScreen();
}
