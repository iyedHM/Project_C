/*********************************************************************
 * @file  RgbLcd.cpp
 * @author Hamrouni Iyed
 * @brief Gestion d'un écran LCD RGB avec plusieurs fonctionnalités
 *********************************************************************/



#include "LCD.h"
 


  // Constructeur
  LCD::LCD() : red(255), green(255), blue(255) {} // Couleur par défaut : Blanc

  LCD::~LCD(){};

  // Méthode pour initialiser l'écran
  void LCD::init() {
      lcd.begin(16, 2); // Initialise un écran 16x2
      setColor(255, 255, 255); // Définit la couleur par défaut (Blanc)
      lcd.print("LCD Ready!"); // Message d'accueil
      delay(2000);
      lcd.clear();
  }


  // Méthode pour définir la couleur de l'écran
  void LCD::setColor(int r, int g, int b) {
      red = r;
      green = g;
      blue = b;
      lcd.setRGB(red, green, blue);
  }


  // Méthode pour afficher un message
  void LCD::printMessage(const String &message, int line ) {
      lcd.setCursor(0, line); // Positionne le curseur
      lcd.print(message);
  }


  // Méthode pour effacer l'écran
  void LCD::clearScreen() {
      lcd.clear();
  }


  // Méthode pour faire clignoter le texte
  void LCD::blinkText(const String &message, int duration, int interval ) {
      for (int i = 0; i < duration / interval; i++) {
          lcd.clear();
          delay(interval);
          lcd.setCursor(0, 0);
          lcd.print(message);
          delay(interval);
      }
  }


  // Méthode pour afficher des couleurs disponibles
  void LCD::displayAvailableColors() {
      clearScreen();
      printMessage("Colors: ", 0);
      delay(1000);
      lcd.clear();
      setColor(255, 0, 0); // Rouge
      printMessage("Red", 1);
      delay(1000);
      lcd.clear();
      setColor(0, 255, 0); // Vert
      printMessage("Green", 1);
      delay(1000);
      lcd.clear();
      setColor(0, 0, 255); // Bleu
      printMessage("Blue", 1);
      delay(1000);
      lcd.clear();
      setColor(255, 255, 0); // Jaune
      printMessage("Yellow", 1);
      delay(1000);
      lcd.clear();
      setColor(255, 255, 255); // Blanc
      printMessage("White", 1);
      delay(1000);
  }


