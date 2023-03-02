#ifndef W25QXX_FLASH_H
#define W25QXX_FLASH_H

#include <Arduino.h>

class W25QXX_Flash {

  public:
    W25QXX_Flash();

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
      Enable Register Writing
    Returns:
    - true if enabled
    - false if not enabled
    */
    bool reg_write_enable();
    byte read_reg_1();
    bool write_reg_1(byte value);
    byte read_reg_2();
    bool write_reg_2(byte value);
    byte read_reg_3();
    bool write_reg_3(byte value);
    bool erase_all();
    bool erase_suspend();
    bool erase_resume();
    void power_down();
    void release_power_down();
    byte[] get_id();
    byte[] get_jedec_id();
    void global_lock();
    void global_unlock();
    void reset_enable();
    void reset();

  private:
    bool write_enabled();

};



#endif