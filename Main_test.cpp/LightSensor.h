/*********************************************************************
 * @file  LCD.hpp
 * @author <Ducasse Thomas>
 * @brief Fichier source de l'application
 *********************************************************************/
#ifndef __LightSensor_H__
#define __LightSensor_H__

#include <inttypes.h>
#include "Print.h"
#include <Wire.h>
#include "Sensor.h"
#include "SHT31.h"
#include "LCD.h"

 class LightSensor : public Sensor {
  private :
    int pinAnalog ;
    LCD lcd;
  public :
    LightSensor(){};
    ~LightSensor(){};
    virtual void init(int pin);
    virtual float readValue(void);
    void Link_PCB(LCD lcd){
      this->lcd = lcd ;
    }
    class Erreur {
    public :
        static void verif(int erreur){};
    };
 };

#endif
 
