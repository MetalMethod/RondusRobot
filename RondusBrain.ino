#include <NewPing.h>
#include <NewTone.h>

// NewPing library inicializations
#define TRIGGER_PIN  12  //branco Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     13  //cinza Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

// After creating this NewPing object, timer  can be used to inicialize functions
//NewPing::timer_ms(frequency, function) - Call function every frequency milliseconds



//event-driven inicializations
unsigned int pingSpeed = 50; // How frequently are we going to send out a ping (in milliseconds). 50ms would be 20 times a second.
unsigned long pingTimer;     // Holds the next ping time.


 
// Left Motor inicializations
const int enableMotorLPin = 9;    // H-bridge enable pin / PWM

const int motorRPinA = 2;   // H-bridge motorL control Pin A
const int motorRPinB = 3;   // H-bridge motorL control Pin B

 //Right Motor inicializations
const int enableMotorRPin = 10;    // H-bridge enable pin / PWM

const int motorLPinC = 4;   // H-bridge motorR control Pin C
const int motorLPinD = 5;   // H-bridge motorR control Pin D




unsigned int pingCm = 0;



// LED heart pin (after resistor on +V)  - using NewPing class timer method
const int heartPin = 6;

// Speaker control pin - using NewTone library
//8

//Analog Pins setup
// A0  // to use as random number seed

// Infra-red cliff, stairs sensors
//A1
//A0






void setup() {

Serial.begin(14400); // Open serial monitor at 115200 baud to see ping results.

//Heart LED setup
pinMode(heartPin, OUTPUT);
NewPing::timer_ms(500, heartBeat); 



 // start timer 
 pingTimer = millis(); // Start now.
 
 
 
 //MOTORS TEST
 // set motors pins as outputs:
    pinMode(motorRPinA, OUTPUT);
    pinMode(motorRPinB, OUTPUT);

 pinMode(motorLPinC, OUTPUT);
 pinMode(motorLPinD, OUTPUT);

    pinMode(enableMotorLPin, OUTPUT);
 pinMode(enableMotorRPin, OUTPUT);
//END OF TEST CODE
}



//Funtion definitions goes here, to remove the code block and separate into another tab

void heartBeat() {
  //digitalWrite(heartPin, !digitalRead(heartPin)); // Toggle the LED without delay
 
  int x =1;
  for (int i = 0; i > -1; i = i + x){
   analogWrite(heartPin, i);
     if (i ==255) {
       x = -1;
     }
   delay(2);
  }
}




void brake(){
    digitalWrite(enableMotorLPin, LOW);
    digitalWrite(enableMotorRPin, LOW);
   
   digitalWrite(motorRPinA, LOW);
   digitalWrite(motorRPinB, LOW);
   
   digitalWrite(motorLPinC, LOW);
   digitalWrite(motorLPinD, LOW);
  delay(200);
  
    }

void forward(){
  // set enablePin high so that motor can turn on 
      digitalWrite(enableMotorLPin, HIGH);
      digitalWrite(enableMotorRPin, HIGH);
      
      digitalWrite(motorRPinA, HIGH );   // set leg 1 of the H-bridge high
      digitalWrite(motorRPinB, LOW);    // set leg 2 of the H-bridge low
 
      digitalWrite(motorLPinC, HIGH);   // set leg 1 of the H-bridge high
      digitalWrite(motorLPinD, LOW);    // set leg 2 of the H-bridge low

  
}

void spinLeft(){
  // set enablePin high so that motor can turn on 
    digitalWrite(enableMotorLPin, HIGH);
    digitalWrite(enableMotorRPin, HIGH);
      
    digitalWrite(motorRPinA, HIGH );   // set leg 1 of the H-bridge high
    digitalWrite(motorRPinB, LOW);    // set leg 2 of the H-bridge low
 
    digitalWrite(motorLPinC, LOW);   // set leg 1 of the H-bridge high
    digitalWrite(motorLPinD, HIGH);    // set leg 2 of the H-bridge low
}


void spinRight(){
  // set enablePin high so that motor can turn on
     analogWrite(enableMotorLPin, 180);
      analogWrite(enableMotorRPin, 180);
      
      digitalWrite(motorRPinA, LOW );   // set leg 1 of the H-bridge high
      digitalWrite(motorRPinB, HIGH);    // set leg 2 of the H-bridge low
 
 digitalWrite(motorLPinC, HIGH);   // set leg 1 of the H-bridge high
    digitalWrite(motorLPinD, LOW);    // set leg 2 of the H-bridge low
     delay(50);
  
}



void echoCheck() { // Timer2 interrupt calls this function every 24uS where you can check the ping status.
  // Don't do anything here!
  if (sonar.check_timer()) { // This is how you check to see if the ping was received.
    // Here's where you can add code.
    Serial.print("Ping: ");
    Serial.print(sonar.ping_result / US_ROUNDTRIP_CM); // Ping returned, uS result in ping_result, convert to cm with US_ROUNDTRIP_CM.
    Serial.println(" cm de caralha");
  }
  // Don't do anything here!
}






void drive(){

Serial.println(pingCm);
pingCm = sonar.ping_cm();


if (pingCm >= 40 || pingCm == 0) { 
 delay(100);  
  forward();
  }
  else if (pingCm < 40 && pingCm != 0) {
  Serial.print("STOP");
  delay(100);
  brake();
  spinLeft();
  
  }
}





void loop() {
// put your main code here, to run repeatedly:

drive();


  
  
  
  
  

  
}
