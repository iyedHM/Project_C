#include <ESP8266WiFi.h>

const char* ssid = "Nom_du_Réseau"; 
const char* password = "Mot_de_Passe"; 

class WiFiManager {
public:
    void connectToWiFi() {
        Serial.print("Connexion à Wi-Fi : ");
        Serial.println(ssid);

        // Initialisation de la connexion Wi-Fi
        WiFi.begin(ssid, password);

        // Boucle jusqu'à ce que la connexion soit établie
        while (WiFi.status() != WL_CONNECTED) {
            delay(1000);
            Serial.print(".");
        }

        // Connexion réussie
        Serial.println("\nConnexion réussie !");
        Serial.print("Adresse IP : ");
        Serial.println(WiFi.localIP());
    }

    void printWiFiStatus() {
        if (WiFi.status() == WL_CONNECTED) {
            Serial.println("Wi-Fi est connecté.");
            Serial.print("Force du signal (RSSI) : ");
            Serial.println(WiFi.RSSI());
        } else {
            Serial.println("Wi-Fi n'est pas connecté.");
        }
    }
};

// Instancier l'objet WiFiManager
WiFiManager wifiManager;

void setup() {
    // Initialiser la communication série pour le débogage
    Serial.begin(115200);

    // Connecter au Wi-Fi
    wifiManager.connectToWiFi();
}

void loop() {
    // Vérifier et afficher l'état de la connexion Wi-Fi
    wifiManager.printWiFiStatus();
    delay(5000); // Attendre 5 secondes avant de vérifier à nouveau
}
