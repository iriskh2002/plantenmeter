#include <Servo.h>

int count = 1;

int input = 0;

int knop = 0;

int ledA = 0;

int ledB = 0;

int ledC = 0;

int ledD = 0;

int ledWET = 0;

int ledDRY = 0;

int grondvochtvoeler = 0;

int wijzen = 0;

Servo servo_4;
int analogPin = A1; // potentiometer wiper (middle terminal) connected to analog pin 3
                    // outside leads to ground and +5V
int meetwaarde = 0;  // variable to store the value read
void setup()
{
  pinMode(A1, INPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(8, INPUT);
  pinMode(2, OUTPUT);
  pinMode(6, OUTPUT);
  servo_4.attach(4, 500, 2500);
  Serial.begin(115200);           //  setup serial
  digitalWrite(2, LOW);



//FF ALLES TESTEN

Serial.println("FF UI TESTEN");


digitalWrite(5, LOW);
digitalWrite(8, LOW);
digitalWrite(9, LOW);
digitalWrite(10, LOW);
digitalWrite(2, LOW);
digitalWrite(6, LOW);


digitalWrite(5, LOW);
digitalWrite(8, LOW);
digitalWrite(9, LOW);
digitalWrite(10, LOW);
digitalWrite(2, LOW);
digitalWrite(6, LOW);



digitalWrite(5, HIGH);
delay(250); // Wait for 100 millisecond(s)

digitalWrite(5, LOW);
digitalWrite(3, HIGH);
delay(250); // Wait for 100 millisecond(s)

digitalWrite(3, LOW);
digitalWrite(9, HIGH);
delay(250); // Wait for 100 millisecond(s)

digitalWrite(9, LOW);
digitalWrite(10, HIGH);
delay(250); // Wait for 100 millisecond(s)

digitalWrite(10, LOW);
digitalWrite(6, HIGH);
delay(250); // Wait for 100 millisecond(s)



digitalWrite(6, LOW);
digitalWrite(2, HIGH);
delay(250); // Wait for 100 millisecond(s)

digitalWrite(2, LOW);
delay(250); // Wait for 100 millisecond(s)



Serial.println("klaar met testen, nu starten");
  
}

void loop()
{
  grondvochtvoeler = analogRead(A1);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  knop = digitalRead(8);
  if (knop == 1) {
    count = (count + 1);
  }
  if (count == 1) {                       // BLOEMEN
    Serial.println("bloemen");
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    
    meetwaarde = analogRead(analogPin);  // read the input pin
    Serial.println(meetwaarde);          // debug value
    Serial.println("\n");
    if (meetwaarde > 1023) {               // WET ALERT1023
      digitalWrite(2, HIGH);  
    }
    else {
      digitalWrite(2, LOW);  
    }
    if (meetwaarde < 30) {               // DRY ALERT
      digitalWrite(6, HIGH);  
    }
    else {
      digitalWrite(6, LOW);  
    }
    wijzen=(20/341)*meetwaarde+20;
    servo_4.write(wijzen);
  }


  
  if (count == 2) {                       // KRUIDEN
    Serial.println("kruiden");
    digitalWrite(9, HIGH);
    servo_4.write(90);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(10, LOW);
   
    meetwaarde = analogRead(analogPin);  // read the input pin
    Serial.println(meetwaarde);          // debug value
    Serial.println("\n");
    if (meetwaarde > 800) {               // WET ALERT800
      digitalWrite(2, HIGH);  
    }
    else {
      digitalWrite(2, LOW);  
    }
    if (meetwaarde < 30) {               // DRY ALERT
      digitalWrite(6, HIGH);  
    }
    else {
      digitalWrite(6, LOW);  
    }
    wijzen=(3/40)*meetwaarde+20;
    servo_4.write(wijzen);
    
  }
  if (count == 3) {                       // GRASSEN
    Serial.println("grassen");
    digitalWrite(3, HIGH);
    servo_4.write(135);
    digitalWrite(5, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    
    meetwaarde = analogRead(analogPin);  // read the input pin
    Serial.println(meetwaarde);          // debug value
    Serial.println("\n");
    if (meetwaarde > 600) {               // WET ALERT600
      digitalWrite(2, HIGH);  
    }
    else {
      digitalWrite(2, LOW);  
    }
    if (meetwaarde < 30) {               // DRY ALERT
      digitalWrite(6, HIGH);  
    }
    else {
      digitalWrite(6, LOW);  
    }
    wijzen=(meetwaarde/10)+20;
    servo_4.write(wijzen);
  }
  if (count == 4) {                       // CACTUSSEN
    Serial.println("kakkers");
    digitalWrite(5, HIGH);
    servo_4.write(180);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(3, LOW);
    
    meetwaarde = analogRead(analogPin);  // read the input pin
    Serial.println(meetwaarde);          // debug value
    Serial.println("\n");
    if (meetwaarde > 400) {               // WET ALERT400
      digitalWrite(2, HIGH);  
    }
    else {
      digitalWrite(2, LOW);  
    }
    if (meetwaarde < 30) {               // DRY ALERT
      digitalWrite(6, HIGH);  
    }
    else {
      digitalWrite(6, LOW);  
    }
    wijzen=(3/20)*meetwaarde+20;
    servo_4.write(wijzen);
  }
  if (count > 4) {
    count = 0;
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    servo_4.write(45);
  }
  delay(1000); // Wait for 1000 millisecond(s)
}
