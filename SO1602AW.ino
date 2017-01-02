//////////////////////////////////////////////////////////
//
// SO1602AW.ino - a simple library for SO1602AWWB, SO1602AWGB, SO1602AWYB
//
// OLED Character Display Module 16x2
//   http://akizukidenshi.com/catalog/g/gP-08277/ (White)
//   http://akizukidenshi.com/catalog/g/gP-08276/ (Green)
//   http://akizukidenshi.com/catalog/g/gP-08278/ (Yellow)
//
// How to use:
//     #include <Wire.h>
//
//     void setup() {
//       Wire.begin(5, 4); //SCL, SDA
//       so1602aw_init();
//       so1602aw_print("hello world");
//     }
//     void loop() {}
//
// OLED Character Display Module Pin Assign
//   1 GND
//   2 Vdd (3.3V)
//   3 C/S (short to GND)
//   4 I2C Slave Address (L->0x3c, H->0x3d)
//   5 NC
//   6 NC
//   7 SCL (I2C clock)
//   8 SDA IN (I2C data)
//   9 SDA OUT (I2Cdata)
//   10～14 NC
//
//   ※ short (1,3,4) and (8,9)...![](img02.png)
//
// License:
//     Copyright (c) 2017 yoggy <yoggy0@gmail.com>
//     Released under the MIT license
//     http://opensource.org/licenses/mit-license.php;//
//

#define S01602AW_ADDR 0x3c

void so1602aw_init() {
  so1602aw_clear();
  so1602aw_on();
  so1602aw_contrast(0x40);
}

void so1602aw_clear() {
  so1602aw_cmd(0x01);
  so1602aw_move_home();
}

void so1602aw_on() {
  so1602aw_cmd(0x0F);
}

void so1602aw_contrast(const uint8_t &val) {
  so1602aw_cmd(0x2a); // RE=1
  so1602aw_cmd(0x79); // SD=1
  so1602aw_cmd(val);  // contrasl value 0x00-0xff
  so1602aw_cmd(0x78); // SD=0
  so1602aw_cmd(0x28); // 0x2C->large font, 0x28->normal font
}

void so1602aw_print(const char *str) {
  if (str == NULL) {
     so1602aw_clear();
  }

  so1602aw_move_home();
  
  int len = strlen(str);
  if (len > 32) len = 32;
  
  for (int i = 0; i < 32; ++i) {
    if (i >= len) {
      so1602aw_char(0x20);
    }
    else {
      so1602aw_char(str[i]);
    }

    if (i  == 15) {
      so1602aw_move_cursor(0, 1);
    }
  }
}

void so162aw_print(const char *str, const int &y) {
  so1602aw_move_cursor(0, y);

  int len = strlen(str);
  if (len > 16) len = 16;

  for (int i = 0; i < 16; ++i) {
    if (i >= len) {
      so1602aw_char(0x20);
    }
    else {
      so1602aw_char(str[i]);
    }
  }
}

void so1602aw_move_home() {
  so1602aw_cmd(0x02);
}

void so1602aw_move_cursor(uint8_t x, uint8_t y) {
  if (y == 0) {
    so1602aw_cmd(0x80 + x);
  }
  else if (y == 1) {
    so1602aw_cmd(0x80 + 0x20 + x);
  }
}

void so1602aw_cmd(char d) {
  so1602aw_data(0x00, d);
}

void so1602aw_char(char d) {
  so1602aw_data(0x40, d);
}

void so1602aw_data(char c, char d) {
  Wire.beginTransmission(S01602AW_ADDR);
  Wire.write(c);
  Wire.write(d);
  Wire.endTransmission();
  delayMicroseconds(20);
}

