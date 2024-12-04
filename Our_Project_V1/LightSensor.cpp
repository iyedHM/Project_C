/* @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/

#ifndef __LightSensor_CPP__
#define __LightSensor_CPP__

# include <iostream>
#include <Arduino.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <Wire.h>
#include "LightSensor.h"


void LightSensor :: init(int pin){
  pinAnalog = pin ;
}

float LightSensor :: readValue(void){
  return analogRead(pinAnalog);
}



#endif