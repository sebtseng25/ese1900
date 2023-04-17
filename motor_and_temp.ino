#define ENABLE 5
#define DIRA 3
#define DIRB 4
#include <dht.h>


dht DHT;


#define DHT11_PIN 7


int i;
 
void setup() {
  //---set pin direction
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  Serial.begin(9600);
}


void loop() {
  // Serial.println("Start The Motors!");
  //---PWM example, full speed then slow
  int chk = DHT.read11(DHT11_PIN);
  Serial.println(DHT.temperature);
  delay(200);
  if (DHT.temperature > 25) {
    for (i=255;i>100;i--) {
    digitalWrite(DIRA,HIGH); //one way
    digitalWrite(DIRB,LOW);
    analogWrite(ENABLE,i); //enable on
    delay(20);
    }
    for (i=100;i<255;i++) {
    digitalWrite(DIRA,HIGH); //one way
    digitalWrite(DIRB,LOW);
    analogWrite(ENABLE,i); //enable on
    delay(20);  
  }
  }  else {
    digitalWrite(DIRA,LOW); //one way
    digitalWrite(DIRB,LOW);
  }
}

