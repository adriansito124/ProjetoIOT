#include <Ultrasonic.h>
#include <Servo.h>

Servo servo;

Ultrasonic ultrasonic(4, 5);
int distance;


void setup() {
  Serial.begin(9600);
  servo.attach(8);
}

void loop() {
  distance = ultrasonic.read();
  Serial.print("Distancia em cm: ");
  Serial.println(distance);
  if(distance < 50)
  {
    for(int i=0; i<90; i++)
    servo.write(0);
  }
  else
  {
    servo.write(180);
  }
  delay(500);
}
