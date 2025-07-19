
int LED = 2;  //LED is delared as an integer of 2, this is because the LED will be defined as pin 2 on the board.

//void setup is a necesarry function that you create at the top of any arduino program. 
//Inside the setup function, the code runs one time before begining the loop of the program
void setup()
{
  pinMode(LED, OUTPUT); // pinMode declares pin numbers as inputs / outputs
}

//void loop is the other necesarry function for any arduino program.
//The loop function runs continuously while the arduino board is powered
void loop() 
{
  digitalWrite(LED, HIGH); // digitalWrite writes a HIGH or LOW voltage to a given pin
}
