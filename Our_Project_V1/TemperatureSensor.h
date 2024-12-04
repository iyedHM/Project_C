/*********************************************************************
 * @file  LCD.hpp
 * @author <Ducasse Thomas>
 * @brief Fichier source de l'application
 *********************************************************************/
#ifndef __TemperatureSensor_H__
#define __TemperatureSensor_H__

#include <inttypes.h>
#include "Print.h"
#include <Wire.h>
#include "Sensor.h"
#include "SHT31.h"

 class TemperatureSensor: public Sensor {
  private :
    SHT31 sht31 = SHT31();
  public :
    TemperatureSensor(){};
    ~TemperatureSensor(){};
    virtual void init(int pin); // mettre 1 
    virtual float readValue(void); // renvoie la température
    float getHum(void); // renvoie l'humidité
    class Erreur {
    public :
        static void verif(int erreur){};
    };
 };

#endif
 
