/*********************************************************************
This is an example for our Monochrome OLEDs based on SSD1306 drivers

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/category/63_98

This example is for a 128x32 size display using I2C to communicate
3 pins are required to interface (2 I2C and one reset)

Adafruit invests time and resources providing this open source code, 
please support Adafruit and open-source hardware by purchasing 
products from Adafruit!

Written by Limor Fried/Ladyada  for Adafruit Industries.  
BSD license, check license.txt for more information
All text above, and the splash screen must be included in any redistribution
*********************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <dht.h>
dht DHT;
//Constants
#define DHT22_PIN 2     // DHT 22  (AM2302) - what pin we're connected to

//Variables
float hum;  //Stores humidity value
float temp; //Stores temperature value

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 
#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif
int sensorPin = A0;
int sensorValue = 0;
void setup()   {                
  Serial.begin(9600);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  // init done
  
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  //display.display();
  //delay(2000);

  // Clear the buffer.
  
  display.clearDisplay();

  // text display tests
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("   BMSCE");
  display.setTextColor(BLACK, WHITE); // 'inverted' text
  display.setTextSize(1);
  display.println("      Bio-Tech       ");

  display.display();
  delay(2000);
  display.clearDisplay();

  }


void loop() {
  sensorValue = analogRead(sensorPin);
  // turn the ledPin on
  Serial.println(sensorValue);
  delay(500);
  display.clearDisplay();

  // text display tests
  display.setTextSize(2);
  display.setTextColor(BLACK, WHITE);
  
  display.setCursor(0,0);
  display.println("Gas Sensor");
  display.setTextColor(WHITE); // 'inverted' text
  display.print("    ");
  display.println(sensorValue);
  
  display.display();
  delay(2000);
  display.clearDisplay();
  int chk = DHT.read22(DHT22_PIN);
    //Read data and store it to variables hum and temp
    hum = DHT.humidity;
    temp= DHT.temperature;
    //Print temp and humidity values to serial monitor
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");
    delay(2000); //Delay 2 sec.
    display.clearDisplay();

  // text display tests
  display.setTextSize(2);
  display.setTextColor(BLACK, WHITE);
  
  display.setCursor(0,0);
  display.println(" Humidity ");
  display.setTextColor(WHITE); // 'inverted' text
  display.print("  ");
  display.print(hum);
  display.println("%");
  display.display();
  delay(2000);
  display.clearDisplay();
  // text display tests
  display.setTextSize(2);
  display.setTextColor(BLACK, WHITE);
  
  display.setCursor(0,0);
  display.println("   Temp   ");
  display.setTextColor(WHITE); // 'inverted' text
  display.print("  ");
  display.print(temp);
  display.println("oC");
  
  display.display();
  delay(2000);
  display.clearDisplay();
  
}



