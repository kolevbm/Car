#include <Servo.h> 
//when using servo library On boards other than the Mega,
//use of the library disables analogWrite() (PWM) functionality on pins 9 and 10,
//whether or not there is a Servo on those pins


            //defines my servo

int forward = 75;
int right = 0;
int left = 180;
int servoPin = 9;
//car motors PIN numbers
int dirM1_1 = 4;
int dirM1_2 = 3;
int dirM2_3 = 10;
int dirM2_4 = 7;
int pin8 = 8;
int speedM1 = 5;
int speedM2 = 6;

// defines pins numbers Ultrasonic sensor
const int trigPin = 12;
const int echoPin = 11;
long duration;

char var;
int distance_right = 0;
int distance_left = 0;
Servo myservo;
int reach;
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
  myservo.attach(servoPin);      // attach servo cotrol to pin 

  Serial.begin(9600);

  }
  
  void loop() {
    distance_left = 0;
    distance_right = 0;
  
  myservo.write(forward);
  delay(500);

  reach = Sensor_distance();
  Serial.println(reach);
  if(reach > 20 )
  {
    
    move_forward();
    Serial.println("forward");
    }
  if(reach >10 && reach <20){
    move_stop();
    myservo.write(left);
    delay(1000);
    distance_left = Sensor_distance();
    
    myservo.write(right);
    delay(1000);
    distance_right = Sensor_distance();

  }
  
  if(distance_right > distance_left){
    turn_right();
    Serial.println("right");
    move_stop();
  }
  if(distance_right < distance_left){
    turn_left();
    Serial.println("left");
    move_stop();
  }
  if(reach < 10){
    move_stop();
    Serial.println("stop");
    Serial.println(Sensor_distance());
  }

  }


  int Sensor_distance() {
    //Ultrasonic sensor
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
  int  distance = duration*0.034/2;
  return distance;
   }

   void turn_right(){
    digitalWrite(dirM1_1, 1);
    digitalWrite(dirM1_2, 0);    
    digitalWrite(dirM2_3, 1);
    digitalWrite(dirM2_4, 0);    
    analogWrite(speedM1, 105);
    analogWrite(speedM2, 100);
    delay(900);

    
   }
   void turn_left(){
    digitalWrite(dirM1_1, 0);
    digitalWrite(dirM1_2, 1);    
    digitalWrite(dirM2_3, 0);
    digitalWrite(dirM2_4, 1);    
    analogWrite(speedM1, 105);
    analogWrite(speedM2, 100);
    delay(900);

    
   }
   void move_stop(){
    analogWrite(speedM1, 0);
    analogWrite(speedM2, 0);    
   }
   void move_forward(){
    digitalWrite(dirM1_1, 0);   
    digitalWrite(dirM1_2, 1);    
    digitalWrite(dirM2_3, 1);
    digitalWrite(dirM2_4, 0);    
    analogWrite(speedM1, 105);
    analogWrite(speedM2, 100);
   }
   void move_back(){
    digitalWrite(dirM1_1, 1);   
    digitalWrite(dirM1_2, 0);    
    digitalWrite(dirM2_3, 0);
    digitalWrite(dirM2_4, 1);    
    analogWrite(speedM1, 105);
    analogWrite(speedM2, 100);
    delay(500);
    analogWrite(speedM1, 0);
    analogWrite(speedM2, 0);
   }
  
  
  
  
