// Programme de lecture d'ID NFC
#include <SPI.h>
#include <PN532_SPI.h>
#include <PN532.h>
#include <NfcAdapter.h>

// utilisation de NDEF
PN532_SPI pn532spi(SPI, 10);
NfcAdapter nfc = NfcAdapter(pn532spi);

// const int redPin = 6;
// const int greenPin = 5;
// const int bluePin = 3;

void setup() {
  Serial.begin(9600);
  delay(500);
  nfc.begin();
  Serial.println("Attente d'un tag NFC");

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

    // analogWrite(redPin, 0);
    // analogWrite(greenPin, 0);
    // analogWrite(bluePin, 255);
  } else {
    // analogWrite(redPin, 255);
    // analogWrite(greenPin, 0);
    // analogWrite(bluePin, 0);
  }
  Serial.print(".");
  delay(500);
}
