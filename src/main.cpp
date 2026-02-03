#include <Arduino.h>
#define trigpin 9
#define echopin 10
void setup() {
// write your initialization code here
    pinMode(trigpin,OUTPUT);
    pinMode(echopin,INPUT);
}

void loop() {
// write your code here
    digitalWrite(trigpin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigpin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigpin,LOW);
    long duration = pulseIn(echopin,HIGH);
    long distance = duration * 0.034/2;
    Serial.print("distance :");
    Serial.print(distance);
    Serial.println(" cm");
    delay(1000);
}
