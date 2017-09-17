int dirM1_1 = 4;
int dirM1_2 = 5;
int dirM2_3 = 6;
int dirM2_4 = 7;
int pin8 = 8;
int speedM1 = 3;
int speedM2 = 10;
// defines pins numbers
const int trigPin = 12;
const int echoPin = 11;
// defines variables
long duration;
int distance;
byte var;

void setup() {
  pinMode(pin8, INPUT);
  pinMode(dirM1_1, OUTPUT);
  pinMode(dirM1_2, OUTPUT);
  pinMode(dirM2_3, OUTPUT);
  pinMode(dirM2_4, OUTPUT);
  pinMode(speedM1, OUTPUT);
  pinMode(speedM2, OUTPUT); 
 pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input 
  Serial.begin(9600);
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
distance= duration*0.034/2;
Serial.print("Distance: ");
Serial.println(distance);
  
  if(distance > 30 && distance < 1000)
  {
    digitalWrite(dirM1_1, 1);
    digitalWrite(dirM1_2, 0);    
    digitalWrite(dirM2_3, 0);
    digitalWrite(dirM2_4, 1);    
    analogWrite(speedM1, 105);
    analogWrite(speedM2, 100);
  }
  if(distance < 30 && distance > 10)
  {
    digitalWrite(dirM1_1, 1);
    digitalWrite(dirM1_2, 0);    
    digitalWrite(dirM2_3, 1);
    digitalWrite(dirM2_4, 0);    
    analogWrite(speedM1, 105);
    analogWrite(speedM2, 100);
  }
  if(distance < 10)
   {
    analogWrite(speedM1, 0);
    analogWrite(speedM2, 0);
   }
}
