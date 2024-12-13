#include "Sensor.h"
#include "LightSensor.h"
#include "SoundSensor.h"
#include "SeuilCaptTemp.h"
#include "TemperatureSensor.h"
#include "Ultrasonic.h"
#include <Wire.h>
#include "rgb_lcd.h"
#include "Buzzer.h"
#include <Servo.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "LCD.h"


//SERVEUR WEB - DEBUT

// Replace with your network credentials
const char* ssid = "Wifi";
const char* password = "20142014";

// Create an instance of the server on port 80
ESP8266WebServer server(80);

// GPIO pin definitions
#define LED_PIN 0       // GPIO5 for LED
#define BUZZER_PIN 14   // GPIO4 for Buzzer
#define SERVO_PIN 15    // GPIO0 for Servo Motor

// States for GPIOs
bool ledState = false;
bool buzzerState = false;

// Servo object
Servo myServo;

// Variable to store the servo angle
int servoAngle = 90; // Default to mid-position

// HTML content for the web page
const char htmlPage[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <title>ESP8266 Control</title>
  <style>
    body { font-family: Arial, sans-serif; text-align: center; margin: 20px; }
    h1 { color: #333; }
    button, input[type="range"] { padding: 10px; font-size: 16px; margin: 10px; cursor: pointer; }
    .control { margin: 20px; }
  </style>
</head>
<body>
  <h1>ESP8266 Web Control</h1>

  <div class="control">
    <h2>Servo Motor Control</h2>
    <input type="range" id="slider" min="0" max="180" value="90" oninput="updateSliderValue(this.value)" />
    <p>Angle: <span id="sliderValue">90</span>&deg;</p>
    <button onclick="sendServoValue()">Set Angle</button>
  </div>

  <div class="control">
    <h2>LED Control</h2>
    <button onclick="toggleLED()">Toggle LED</button>
    <p>Current State: <span id="ledState">OFF</span></p>
  </div>

  <div class="control">
    <h2>Buzzer Control</h2>
    <button onclick="toggleBuzzer()">Toggle Buzzer</button>
    <p>Current State: <span id="buzzerState">OFF</span></p>
  </div>

  <script>
    // Update slider value display
    function updateSliderValue(value) {
      document.getElementById("sliderValue").innerText = value;
    }

    // Send slider value to server
    function sendServoValue() {
      const value = document.getElementById("slider").value;
      fetch(`/setServo?angle=${value}`).then(response => response.text()).then(data => {
        alert(data); // Display response from server
      });
    }

    // Toggle LED
    function toggleLED() {
      fetch('/toggleLED').then(response => response.text()).then(data => {
        alert(data);
        fetchState(); // Refresh state after toggling
      });
    }

    // Toggle Buzzer
    function toggleBuzzer() {
      fetch('/toggleBuzzer').then(response => response.text()).then(data => {
        alert(data);
        fetchState(); // Refresh state after toggling
      });
    }

    // Fetch the current states of the LED and Buzzer
    function fetchState() {
      fetch('/getState').then(response => response.json()).then(data => {
        document.getElementById("ledState").innerText = data.led ? "ON" : "OFF";
        document.getElementById("buzzerState").innerText = data.buzzer ? "ON" : "OFF";
      });
    }

    // Initial fetch of states
    fetchState();
    // Periodic refresh of states
    setInterval(fetchState, 5000);
  </script>
</body>
</html>
)rawliteral";

// Handle root route
void handleRoot() {
  server.send(200, "text/html", htmlPage);
}

//Handle slider for servo motor
void handleSetServo() {
  if (server.hasArg("angle")) {
    servoAngle = server.arg("angle").toInt();
    myServo.write(servoAngle);
    server.send(200, "text/plain", "Servo angle set to " + String(servoAngle));
  } else {
    server.send(400, "text/plain", "Missing 'angle' parameter");
  }
}

// Handle LED toggle
void handleToggleLED() {
  ledState = !ledState;
  digitalWrite(LED_PIN, ledState ? HIGH : LOW);
  server.send(200, "text/plain", ledState ? "LED is ON" : "LED is OFF");
}

// Handle buzzer toggle
void handleToggleBuzzer() {
  buzzerState = !buzzerState;
  digitalWrite(BUZZER_PIN, buzzerState ? HIGH : LOW);
  server.send(200, "text/plain", buzzerState ? "Buzzer is ON" : "Buzzer is OFF");
}

// Handle state fetching
void handleGetState() {
  String json = "{";
  json += "\"led\":" + String(ledState ? "true" : "false") + ",";
  json += "\"buzzer\":" + String(buzzerState ? "true" : "false");
  json += "}";
  server.send(200, "application/json", json);
}



//SERVEUR WEB - FIN

const int seuil_temp = 28;
const int seuil_bruit = 0;
const int seuil_luminosite = 50;
const int seuil_humidite = 70;
const float RsensorSeuil = 100;
const int colorR = 255;
const int colorG = 255;
const int colorB = 255;
//Ultrasonic ultra = Ultrasonic(15);
//LightSensor light = LightSensor();
SoundSensor sound = SoundSensor();
TemperatureSensor temp = TemperatureSensor();
Buzzer buzz = Buzzer();
rgb_lcd lcd0;
LCD lcd = LCD();
LightSensor light = LightSensor();
SeuilCaptTemp seuils = SeuilCaptTemp();


void setup() {

//Initialisation des capteurs

  pinMode(0, OUTPUT); //TEST LED AVEC TEMP SENS
  lcd.init();
  digitalWrite(0, LOW);

  buzz.init(14,false);
  //light.init(A0);
  temp.init(1); // mettre 1 par défaut

  light.Link_PCB(lcd);
  light.init(A0);

  //INITIALSATION WIFI - SITE WEB
  Serial.begin(115200);
  delay(10);

  // Initialize GPIO pins
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);    // Start with LED off
  digitalWrite(BUZZER_PIN, LOW); // Start with Buzzer off

  // Initialize servo motor
  myServo.attach(SERVO_PIN);
  myServo.write(servoAngle); // Set to default position

  // Connect to WiFi
  Serial.println();
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Define routes
  server.on("/", handleRoot);
  //server.on("/setServo", handleSetServo);
  server.on("/toggleLED", handleToggleLED);
  server.on("/toggleBuzzer", handleToggleBuzzer);
  server.on("/getState", handleGetState);

  // Start the server
  server.begin();
  Serial.println("HTTP server started");

  lcd.printMessage("Optimal",0);
  lcd.printMessage("Conditions",1);

}

int temperature = 0;
int humidite;
int valCapteurLum = 0;
float Rsensor = 0;
bool state;
bool led_off = true;


void loop() {

  // Handle client requests
  server.handleClient();
  delay(1000);
  temperature = temp.readValue();
  humidite = temp.getHum();
  valCapteurLum = light.readValue();
  Rsensor = (float)((1023-valCapteurLum)*10/valCapteurLum);



  if (temp > seuils) {
    buzz.on();
    state = true;
    myServo.write(180);
    delay(15);
    if (temperature > seuil_temp) {
      lcd.clearScreen();
      lcd.setColor(255,0,0);
      lcd.printMessage("ROOM TEMPERATURE",0);
      lcd.printMessage("TOO HIGH",1);
    }
    if (humidite > seuil_humidite) {
      lcd.clearScreen();
      lcd.setColor(255,0,0);
      lcd.printMessage("HIGH HUMIDITY",0);
    }
  }



  if (Rsensor > RsensorSeuil and led_off) {
    lcd.clearScreen();
    lcd.setColor(255,255,0);
    lcd.printMessage("LOW LIGHT",0);
    lcd.printMessage("LED TURNED ON",1);
    digitalWrite(0,HIGH);
    led_off = false;
    delay(5000);
    lcd.clearScreen();
    lcd.setColor(255,255,255);
    lcd.printMessage("Optimal",0);
    lcd.printMessage("Conditions",1);
  }



  if (Rsensor < RsensorSeuil and !led_off) {
    lcd.clearScreen();
    lcd.setColor(255,255,0);
    lcd.printMessage("ROOM WELL LIT",0);
    lcd.printMessage("LED TURNED OFF",1);
    digitalWrite(0,LOW);
    led_off = true;
    delay(5000);
    lcd.clearScreen();
    lcd.setColor(255,255,255);
    lcd.printMessage("Optimal",0);
    lcd.printMessage("Conditions",1);
  }



  if (temp < seuils) {
    buzz.off();
    myServo.write(0);
    delay(15);
    state = false;
    lcd.clearScreen();
    lcd.setColor(255,255,255);
    lcd.printMessage("Optimal",0);
    lcd.printMessage("Conditions",1);
  }

}