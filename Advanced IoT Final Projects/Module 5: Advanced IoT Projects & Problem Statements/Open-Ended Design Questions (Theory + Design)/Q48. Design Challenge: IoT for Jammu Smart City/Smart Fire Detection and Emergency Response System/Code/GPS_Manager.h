#ifndef GPS_MANAGER_H
#define GPS_MANAGER_H

/*
Project: Smart Fire Detection and Emergency Response System
Question: Q48
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Provides incident location information.
Uses fixed coordinates in simulation and
supports real GPS modules for physical
implementation.
*/

#include "Config.h"
#include "Credentials.h"

// Current GPS coordinates
float currentLatitude = LATITUDE;
float currentLongitude = LONGITUDE;

// GPS availability
bool gpsAvailable = true;

// Initialize GPS
void initializeGPS()
{
    Serial.println("GPS Module Initialized");
}

// Update GPS location
void updateLocation()
{
    // Simulation uses fixed coordinates.
    // Replace this section with TinyGPS++
    // library when using a real GPS module.

    currentLatitude = LATITUDE;
    currentLongitude = LONGITUDE;
}

// Return latitude
float getLatitude()
{
    return currentLatitude;
}

// Return longitude
float getLongitude()
{
    return currentLongitude;
}

// Return formatted coordinates
String getCoordinates()
{
    String location = "";

    location += String(currentLatitude, 6);
    location += ", ";
    location += String(currentLongitude, 6);

    return location;
}

// Generate Google Maps link
String getGoogleMapsLink()
{
    String url = "https://maps.google.com/?q=";

    url += String(currentLatitude, 6);
    url += ",";
    url += String(currentLongitude, 6);

    return url;
}

// Display GPS information
void printGPSData()
{
    Serial.println();

    Serial.println("GPS Information");
    Serial.println("--------------------------------");

    Serial.print("Location : ");
    Serial.println(LOCATION_NAME);

    Serial.print("Zone     : ");
    Serial.println(ZONE_NAME);

    Serial.print("Latitude : ");
    Serial.println(currentLatitude, 6);

    Serial.print("Longitude: ");
    Serial.println(currentLongitude, 6);

    Serial.print("Google Maps: ");
    Serial.println(getGoogleMapsLink());

    Serial.println();
}

// Return GPS status
bool gpsReady()
{
    return gpsAvailable;
}

// Generate incident ID
String generateIncidentID()
{
    String id = "FIRE-";

    id += String(millis() / 1000);

    return id;
}

// Prepare incident information
Incident createIncident()
{
    Incident incident;

    incident.incidentID = generateIncidentID();

    incident.location = getCoordinates();

    incident.dateTime = String(millis() / 1000);

    incident.responseStatus = "Pending";

    return incident;
}

#endif
