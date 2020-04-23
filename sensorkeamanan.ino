#include <LiquidCrystal.h>

const int trigPin = 8;
const int echoPin = 9;
long duration;
double distance;
LiquidCrystal lcd(2,3,4,5,6,7);
int status = 0;
int statusbaru;

void setup(){
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  pinMode(12,OUTPUT);
  pinMode(10,OUTPUT);
  matikan();
}

void loop(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= (duration/2)/29.154;
  Serial.println(distance);
  if(distance > 20){
    statusbaru = 0;
    if(status != statusbaru){
      matikan();
    }
  }else{ 
    bunyikan();
    statusbaru = 1;
    if(status != statusbaru){
      nyalakan();
    }
  }
  status = statusbaru;
}


void nyalakan(){
  digitalWrite(12,LOW);  
  digitalWrite(10,HIGH);
  statusbaru = 1;
  tulisan("BAHAYA", "SITUASI BAHAYA");
}

void matikan(){
  digitalWrite(12,HIGH);
  digitalWrite(10,LOW);
  statusbaru = 0;
  tulisan("AMAN", "SITUASI AMAN");
}

void bunyikan(){
  tone(13,50,200);    
}
void tulisan(String baris1, String baris2){
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print(baris1);
    lcd.setCursor(0,1);
    lcd.print(baris2);  
}
