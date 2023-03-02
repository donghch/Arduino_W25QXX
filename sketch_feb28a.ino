#include <SPI.h>
#include "W25QXX_Flash.h"

#define CS_PIN 10 // chip select pin for the W25Q64 flash
W25QXX_Flash flash = W25QXX_Flash();
void setup() {
  Serial.begin(9600);
  delay(500);
  if (flash.write_enable()) {
    Serial.print("Enabled");
  }
}

void loop() {

}