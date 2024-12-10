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
#include "LCD.h"


void LightSensor :: init(int pin){
  try {
    if (pin<0){
      throw 1 ;
    }

  } catch (int e) {
    lcd.printMessage("Erreur initLight");
    lcd.printMessage("Pin negative !",1);
  }
  pinAnalog = pin ;
}

float LightSensor :: readValue(void){
  return analogRead(pinAnalog);
}



#endif
