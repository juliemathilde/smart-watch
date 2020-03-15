#include<SoftwareSerial.h>
#define RX 10
#define TX 11
SoftwareSerial BlueT(RX,TX);

void setup() {
  Serial.begin(9600);
  delay(500);
  Serial.println("Salutation, le tableau de bord est à jour");
  BlueT.begin(9600);
  delay(500);
  

}

void loop() {
  while (BlueT.available()) {
   Serial.print(char(BlueT.read())); }
  while (Serial.available()) {
   BlueT.write(char(Serial.read())); }
   

}
