/* @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/

#ifndef __TemperatureSensor_CPP__
#define __TemperatureSensor_CPP__

# include <iostream>
#include <Arduino.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <Wire.h>
#include "TemperatureSensor.h"
#include "SHT31.h"


void TemperatureSensor:: init (int pin) {
  sht31.begin(); 
}

float TemperatureSensor:: readValue(void) {
  float temp = sht31.getTemperature();
  return temp ;
}

float TemperatureSensor :: getHum(void) {
  float hum = sht31.getHumidity();
  return hum ;
}

#endif