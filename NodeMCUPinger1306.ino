#include <ESP8266WiFi.h>
#include <ESP8266Ping.h>

// Libraries for SSD1306 OLED display
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const char* ssid = "ASTRO";
const char* password = "playstation74";

void setup() {
    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // END OF DISPLAY SHIT
  Serial.begin(115200);
  pinMode(14, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(14, LOW);
  digitalWrite(12, HIGH);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); Serial.print(".");
  }
  Serial.println("\nWiFi connected");
  Serial.print("Local IP: "); Serial.println(WiFi.localIP());
  Serial.print("Gateway IP: "); Serial.println(WiFi.gatewayIP());
  IPAddress ip (8, 8, 8, 8); // The remote ip to ping
  delay(1000);
  pingIp(ip);
}

void loop() {
  IPAddress ip (8, 8, 8, 8); // The remote ip to ping
  pingIp(ip);
  delay(1000);
}

void displayText(String text) {
  display.clearDisplay();
  display.setTextSize(5); // Draw 2X-scale text
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println(text);
  display.display();      // Show initial text
  delay(100);
}

void pingIp(IPAddress ip){
  Serial.print("Pinging IP:"); Serial.println(ip);
  if (Ping.ping(ip, 4)) {
    Serial.print("Ping success: ");
    int pingTime = Ping.averageTime();
    Serial.println(pingTime);
    displayText(String(Ping.averageTime()));
    digitalWrite(14, HIGH);
    digitalWrite(12, LOW);
  } else {
    Serial.println("Ping to gateway failed");
    displayText("FAILED");
    digitalWrite(14, LOW);
    digitalWrite(12, HIGH);
  }
}
