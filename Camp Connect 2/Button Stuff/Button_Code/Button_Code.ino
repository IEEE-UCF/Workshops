int LED = 8; //Initialize LED to digital pin 8
int BUTTON = 7; //Initialize BUTTON to digital pin 7

void setup() 
{
  pinMode(LED, OUTPUT); //pinMode declares given variable as input / output
  pinMode(BUTTON, INPUT); 
}

void loop()
{
  if (digitalRead(BUTTON) == HIGH) //if statement uses digitalRead to analyze if button input is HIGH
  {
    digitalWrite(LED, HIGH); //given a high digitalRead, digitalWrite OUTPUTS a high voltage at the LED pin
  }
  else if (digitalRead(BUTTON) == LOW) //else if statement uses digitalRead to analyze if button input is LOW
  {
    digitalWrite(LED, LOW); //given a low digitalRead, digitalWrite outputs a low voltage to the LED pin
  }
}
