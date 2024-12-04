/* @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/

#ifndef __SoundSensor_CPP__
#define __SoundSensor_CPP__

# include <iostream>
#include <Arduino.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <Wire.h>
#include "SoundSensor.h"



void SoundSensor :: init (int pin){
  this->pinIO = pin ;
}

float SoundSensor :: readValue(void){
  return analogRead(pinIO) ;
}


#endif