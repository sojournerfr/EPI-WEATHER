#include <DHT.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);
  dht.begin();
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Erreur d'initialisation de l'écran OLED"));
    while (1);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("Capteur DHT11 initialisé"));
  display.display();
  delay(2000);
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Erreur de lecture du capteur DHT11 !");
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println(F("Erreur de lecture!"));
    display.display();
    return;
  }
  Serial.print("Température : ");
  Serial.print(temperature);
  Serial.print(" °C  Humidité : ");
  Serial.print(humidity);
  Serial.println(" %");
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print(F("Temp: "));
  display.print(temperature);
  display.print(F(" C"));
  display.setCursor(0, 10);
  display.print(F("Hum: "));
  display.print(humidity);
  display.print(F(" %"));
  display.display(); 
  delay(2000);
}
