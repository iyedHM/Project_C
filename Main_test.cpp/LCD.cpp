#include "LCD.h"
#include <vector>
#include <tuple>


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



void LCD::displayAvailableColors() {
    // Define a vector of tuples for colors (R, G, B, Color Name)
    std::vector<std::tuple<int, int, int, String>> colors = {
        {255, 0, 0, "Red"},
        {0, 255, 0, "Green"},
        {0, 0, 255, "Blue"},
        {255, 255, 0, "Yellow"},
        {255, 255, 255, "White"}
    };

    clearScreen();
    printMessage("Colors:", 0); // Display title
    delay(1000);
    lcd.clear();

    // Iterate over the vector and display each color
    for (const auto& color : colors) {
        int r, g, b;
        String name;

        // Unpack the tuple
        std::tie(r, g, b, name) = color;

        // Set the color and display its name
        setColor(r, g, b);
        printMessage(name, 1);
        delay(1000);
        lcd.clear();
    }
}

