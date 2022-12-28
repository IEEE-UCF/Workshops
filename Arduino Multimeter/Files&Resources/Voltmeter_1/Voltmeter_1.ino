
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


const int VoltMeter = 2; 
float V = 0.00; 
  
void setup() { 
  Serial.begin(115200); 
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  
  delay(2000);
  display.clearDisplay();
  display.setTextColor(WHITE);
 
}
void loop() { 

  float R1 = 10000;//5100.00; 
  float R2 = 4700;//2000; //4700.00; 
  float resistor_ratio = 0.00;
  float adc_value = 0.00; 
  float voltage = 0.00; 
  resistor_ratio = (R2 / (R1 + R2)); 
  
  for (int i = 0; i < 20 ; i++) 
  { 
    adc_value = adc_value + analogRead(VoltMeter);
    delay(3); 
  } 
    adc_value = adc_value / 20; 
    voltage = ((adc_value * 5) / 1024); 
    V = voltage / resistor_ratio; 
   
  
display.setCursor(0,10);
  // Display static text 
  display.println("\n V is"); 
  display.print(V);
  display.print(" ");
  display.display();
  display.clearDisplay();
 
} 
