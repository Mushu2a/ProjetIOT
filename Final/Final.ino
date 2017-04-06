// Librairie NFC
#include <SPI.h>
#include <PN532_SPI.h>
#include <PN532.h>
#include <NfcAdapter.h>

// Libraire moteur
#include <Stepper.h>

// utilisation de NDEF
PN532_SPI pn532spi(SPI, 10);
NfcAdapter nfc = NfcAdapter(pn532spi);

// Pins Arduino moteur
int in1Pin = 2;
int in2Pin = 3;
int in3Pin = 4;
int in4Pin = 5;
 
// change this to the number of steps on your motor
#define STEPS 512
 
Stepper motor(STEPS, in1Pin, in2Pin, in3Pin, in4Pin); 

// Constante LED
// const int redPin = 6;
// const int greenPin = 7;
// const int bluePin = 8;

void setup() {
  Serial.begin(9600);
  delay(500);
  nfc.begin();
  Serial.println("Attente d'un tag NFC");

  // Vitesse du moteur
  motor.setSpeed(20);

  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
  
  // pinMode(redPin, OUTPUT);
  // pinMode(greenPin, OUTPUT);
  // pinMode(bluePin, OUTPUT);
}
void loop() {  
  // Si présence d'un tag, affichage ID
  if (nfc.tagPresent()) {
    Serial.println();
    NfcTag tag = nfc.read();
    Serial.print("{\"ID\":");
    Serial.print(tag.getUidString());
    Serial.print("}");
    Serial.println();

    // Allume le moteur et tourne dans le sens des aiguilles d'une montre
    motor.step(300);

    // LED Allumer
    // analogWrite(redPin, 0);
    // analogWrite(greenPin, 0);
    // analogWrite(bluePin, 255);
  } else {
    // LED Eteinte
    // analogWrite(redPin, 255);
    // analogWrite(greenPin, 0);
    // analogWrite(bluePin, 0);
  }

  // Revient à la valeur initiale du moteur
}
