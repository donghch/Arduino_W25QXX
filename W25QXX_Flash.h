#ifndef W25QXX_FLASH_H
#define W25QXX_FLASH_H

#include <Arduino.h>

class W25QXX_Flash {

  public:
    W25QXX_Flash(int cs);

    /**
    Enable Write Mode.
    Returns:
    - true if the Write Mode is enabled.
    - false if the Write Mode is not enabled.
    */
    bool write_enable();

    /**
    Disable Write Mode.
    Returns:
    - true if the Write Mode is disabled.
    - false if the Write Mode is not disabled.
    */
    bool write_disable();

    /**
    Read Register (7, 0) into a byte. R7 is MSB.
    Returns:
      - Register values
    */
    char read_reg_1();

    /**
    Read Register (15, 8) into a byte. R15 is MSB.
    Returns:
      - Resgister values
    */
    char read_reg_2();
     
    /**
    Read Register (23, 16) into a byte. R23 is MSB.
    Returns:
      - Register values
    */
    char read_reg_3();

    /**
    Erase a flash sector (4kB).
    Returns:
      - true if success
      - false if fail.
    Post Condition:
      - Write will be disabled
      - Current sector may be locked
    */
    bool sector_erase(char* address);

    /**
    Erase a flash block (64kB).
    Returns:
      - true if success
      - false if fail.
    Post conditions:
      - Write will be disabled
      - Current sector may be locked
    */
    bool block_erase(char* address);

    /**
    Erase whole flash chip
    Returns:
      - true if success
      - false if fail.
    Post conditions:
      - Write will be disabled
      - Current sector may be locked
    */
    bool chip_erase();

  private:
    int pin;
    bool write_enabled();
};



#endif