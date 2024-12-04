/*********************************************************************
 * @file  RgbLcd.cpp
 * @author Hamrouni Iyed
 * @brief Gestion d'un écran LCD RGB avec plusieurs fonctionnalités
 *********************************************************************/


#include <rgb_lcd.h>


#ifndef LCD_H_
#define LCD_H_


class LCD {
private:
    rgb_lcd lcd; // Instance de l'écran LCD
    int red, green, blue; // Variables pour les couleurs RGB


public:


    /**
     * @fn Buzzer();
     * @brief Constructeur par defaut
    */    
    LCD();
    /**
     * @fn ~Buzzer();
     * @brief Destructeur
    */    
    ~LCD();    
    /**
     * @fn void init(void)
     * @brief Fonction d'initialisation du Buzzer
    */
    void init();
    /**
     * @fn void on(void)
     * @brief Fonction de lancement du Buzzer
    */
    void setColor(int r, int g, int b);
    /**
     * @fn void off(void)
     * @brief Fonction d'arret du Buzzer
    */
    void printMessage(const String &message, int line = 0);
     /**
     * @fn void on(void)
     * @brief Fonction de lancement du Buzzer avec une frequence specifique
    */
    void clearScreen();
     /**
     * @fn void on(void)
     * @brief Fonction de lancement du Buzzer avec une frequence specifique
    */
    void blinkText(const String &message, int duration, int interval = 500);
     /**
     * @fn void on(void)
     * @brief Fonction de lancement du Buzzer pour une durée specifique
    */
    void displayAvailableColors();


};
#endif
