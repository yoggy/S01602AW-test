//
// S01602AW-test.ino - a sample sketch for for SO1602AWWB, SO1602AWGB, SO1602AWYB
//
// OLED Character Display Module 16x2
//   http://akizukidenshi.com/catalog/g/gP-08277/ (White)
//   http://akizukidenshi.com/catalog/g/gP-08276/ (Green)
//   http://akizukidenshi.com/catalog/g/gP-08278/ (Yellow)
//
// license:
//     Copyright (c) 2017 yoggy <yoggy0@gmail.com>
//     Released under the MIT license
//     http://opensource.org/licenses/mit-license.php;//
//
#include <Wire.h>
#include "WioNode.h"

void setup() {
  INIT_WIO_NODE();
  Wire.begin(PORT1_D1, PORT1_D0); //SDA (White), SCL(Yellow)
  so1602aw_init();
  so1602aw_print("hello SO1602AWGB!!!!12345678");
}

void loop() {
}
