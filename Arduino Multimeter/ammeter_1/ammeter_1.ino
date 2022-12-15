#include <Wire.h> 
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width in pixels
#define SCREEN_HEIGHT 64 // OLED display height in pixels 

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


const int Ammeter = A3; 
float I = 0.00; 

void setup(){

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
//void calculate_current() { 
  
  int sensitivity = 185;                           //in millivolts/A, based off of specific current sensor, outputs 66 millivolts per Amp read
  int adc_value = 0;                            //initializing variable for adc conversion
  float v_ref = 4.94;                         //reference voltage for arduino uno
  float voltage = 0.00;                     //initializing variable for output voltage being read
  float pure_voltage = 0.00;               //the fluctuation in output voltage by the current sensor caused by the load of whatever circuit is being measured
  float offset_voltage = 2.47;            //the amount of volts outputted by the sensor when its free of any load
  for (int i = 0; i < 40 ; i++) 
  { 
    adc_value = adc_value + analogRead(Ammeter); 
    delay(2); 
  } 
  adc_value = adc_value / 40;                 //reads the output voltage of the current sensor 40 times then averages it out
  voltage = ((adc_value * v_ref)/ 1024) ;    //converts output voltage to a binary number that can be displayed and manipulated by arduino
  pure_voltage = voltage - offset_voltage;  //measures how much of a change in voltage was caused by connecting current sensor to whatever is supplying the current

  pure_voltage = pure_voltage * 1000;     //since this is going to be tiny this converts it milliamps, also puts in in the same units as the sensitivity
  I = pure_voltage / sensitivity; //I(A) = pv(mV) / sens(mV/A)


display.setCursor(0,8);
  // Display static text 
  display.println (adc_value);
  display.println("/n I (A) is"); 
  display.print(I);
  display.print(" ");
  display.display();
  display.clearDisplay();
  

} 
