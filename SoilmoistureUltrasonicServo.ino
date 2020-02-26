#include <Servo.h>
Servo myservo;
int sensorPin = A0; 
int sensorValue;  
int limit = 1000; 
const int trigPin = 2;

const int echoPin = 4;

void setup() {
 Serial.begin(9600);
 pinMode(13, OUTPUT);
 myservo.attach(9);
}

void loop() {

 sensorValue = analogRead(sensorPin); 
 Serial.println("Analog Value : ");
 Serial.println(sensorValue);
 myservo.write(90);

 long duration, cm;

pinMode(trigPin, OUTPUT);

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH);

delayMicroseconds(20);

digitalWrite(trigPin, LOW);

pinMode(echoPin, INPUT);

duration = pulseIn(echoPin, HIGH);

// convert the time into a distance

cm = microsecondsToCentimeters(duration);

// the condition for the distance

if (  cm < 14)
{
 
 if (sensorValue<limit) {
 digitalWrite(13, HIGH);
 myservo.write(0);

 }
 else {
 digitalWrite(13, LOW); 
 myservo.write(180);

 }
}
Serial.print(cm);

Serial.print("cm");

Serial.println();
 
 delay(1000); 
}
long microsecondsToCentimeters(long microseconds) {

// The speed of sound is 340 m/s or 29 microseconds per centimeter.

// The ping travels out and back, so to find the distance of the

// object we take half of the distance travelled.

return microseconds / 29 / 2;

}
