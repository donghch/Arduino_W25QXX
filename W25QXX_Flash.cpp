
/*
  W25QXX_Flash.cpp - Library for manipulating W25Q series flash.
  Created by Houchuan(Henry) Dong, Feburary, 2023.
*/
#include "Arduino.h"
#include "W25QXX_Flash.h"
#include <SPI.h>


W25QXX_Flash::W25QXX_Flash(int cs) {
  pin = cs;
  pinMode(pin, OUTPUT);
}

//Public Functions

bool W25QXX_Flash::write_enable() {
  if (write_enabled()) {
    return true;
  } else {
    digitalWrite(pin, LOW);
    SPI.transfer(0x6);
    digitalWrite(pin, HIGH);
    return write_enabled();
  }
}

bool W25QXX_Flash::write_disable() {
  if (!write_enabled()) {
    return true;
  } else {
    digitalWrite(pin, LOW);
    SPI.transfer(0x4);
    digitalWrite(pin, HIGH);
    return !write_enabled();
  }
}


char W25QXX_Flash::read_reg_1() {
  digitalWrite(pin, LOW);
  SPI.transfer(0x5);
  char data = SPI.transfer(0x0);
  digitalWrite(pin, HIGH);
  return data;
}

char W25QXX_Flash::read_reg_2() {
  digitalWrite(pin, LOW);
  SPI.transfer(0x35);
  char data = SPI.transfer(0x0);
  digitalWrite(pin, HIGH);
  return data;
}

char W25QXX_Flash::read_reg_3() {
  digitalWrite(pin, LOW);
  SPI.transfer(0x15);
  char data = SPI.transfer(0x0);
  digitalWrite(pin, HIGH);
  return data;
}

bool W25QXX_Flash::sector_erase(char* address) {
  if (!write_enabled()) {
    return false;
  }
  digitalWrite(pin, LOW);
  SPI.transfer(0x20);
  SPI.transfer(address, 3);
  digitalWrite(pin, HIGH);
  while (read_reg_1() & 0x1) {
    ;
  }
  return true;
}

bool W25QXX_Flash::block_erase(char* address) {
  if (!write_enabled()) {
    return false;
  }
  digitalWrite(pin, LOW);
  SPI.transfer(0xd8);
  SPI.transfer(address, 3);
  digitalWrite(pin, HIGH);
  while (read_reg_1() & 0x1) {
    ;
  }
  return true;
}

bool W25QXX_Flash::chip_erase() {
  if (!write_enabled()) {
    return false;
  }
  digitalWrite(pin, LOW);
  SPI.transfer(0xc7);
  digitalWrite(pin, HIGH);
  while (read_reg_1() & 0x1) {
    ;
  }
  return true;
}

//Private Functions

bool W25QXX_Flash::write_enabled() {
  char result = read_reg_1();
  if ((result & 0b00000010) != 0) {
    return true;
  } else {
    return false;
  }
}