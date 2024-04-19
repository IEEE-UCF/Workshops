/*
// defines pins numbers
const int trigPin = 20; //make it so we cant later redefine trig and echo
const int echoPin = 21;

// defines variables
long duration; //data types for 
int distance;



void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  
}


void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;


  Serial.print("Distance: ");
  Serial.println(distance);
   
  

}

*/

// defines pins numbers
const int trigPin = 20; //make it so we cant later redefine trig and echo
const int echoPin = 21;
const int Button = 16;

// defines variables
long duration; //data types for 
int distance;
bool buttonState;


void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(Button, INPUT);
  
  Serial.begin(115200); // Starts the serial communication
  
}


void loop() {
  buttonState = digitalRead(Button);
  Serial.println(buttonState);
  if (Button == HIGH){
 
    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
  
  
    Serial.print("Distance: ");
    Serial.println(distance);
     
    }

}
