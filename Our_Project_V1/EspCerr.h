/* @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/

#ifndef __EspCerr_CPP__
#define __EspCerr_CPP__
#include "rgb_lcd.h"

rgb_lcd lcd;

class EspCerr {
public:
  template<typename T>
  EspCerr& operator<<(T message) {
    lcd.print(message);
    return *this;
  }
};

#endif