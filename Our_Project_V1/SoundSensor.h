/*********************************************************************
 * @file  LCD.hpp
 * @author <Ducasse Thomas>
 * @brief Fichier source de l'application
 *********************************************************************/
#ifndef __SoundSensor_H__
#define __SoundSensor_H__

#include <inttypes.h>
#include "Print.h"
#include <Wire.h>
#include "Sensor.h"

 class SoundSensor : public Sensor {
  private :
    int pinIO ;
  public :
    SoundSensor(){};
    ~SoundSensor(){};
    virtual void init(int pin);
    virtual float readValue(void);
    class Erreur {
    public :
        static void verif(int erreur){};
    };
 };

#endif
 
