/*********************************************************************
 * @file  LCD.hpp
 * @author <Ducasse Thomas>
 * @brief Fichier source de l'application
 *********************************************************************/
#ifndef __Sensor_H__
#define __Sensor_H__

class Sensor {
public:
    virtual void init(int pin) = 0;
    virtual float readValue(void) = 0; // Renvoie la valeur mesurée
    virtual ~Sensor() {};
};

#endif