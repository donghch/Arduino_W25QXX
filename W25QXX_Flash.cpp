
/*
  W25QXX_Flash.cpp - Library for manipulating W25Q series flash.
  Created by Houchuan(Henry) Dong, Feburary, 2023.
*/
#include "Arduino.h"
#include "W25QXX_Flash.h"
#include <SPI.h>


W25QXX_Flash::W25QXX_Flash() {
  pinMode(10, HIGH);
  SPI.begin();
}

bool W25QXX_Flash::write_enable() {
  if (write_enabled()) {
    return true;
  } else {
    digitalWrite(10, LOW);
    SPI.transfer(0x6);
    digitalWrite(10, HIGH);
    return write_enabled();
  }
}

bool W25QXX_Flash::write_enabled() {
  digitalWrite(10, LOW);
  SPI.transfer(0x5);
  byte result = SPI.transfer(0x0);
  digitalWrite(10, HIGH);
  if ((result & 0b00000010) != 0) {
    return true;
  } else {
    return false;
  }
}