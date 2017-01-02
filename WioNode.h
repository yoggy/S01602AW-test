//
// WioNode.ino - a simple macro library for Arduinoize WioNode
//
// How to use:
//     #include "WioNode.h"
//     void setup() {
//       INIT_WIO_NODE();
//     }
//     void loop() {
//       if (digitalRead() == LOW) {    // if FUNC button pressed
//         digitalWrite(LED_BLUE, LOW); // Turn on the blue LED
//       }
//       else
//         digitalWrite(LED_BLUE, HIGH); // Turn off the blue LED
//       }
//     }
//
// License:
//     Copyright (c) 2017 yoggy <yoggy0@gmail.com>
//     Released under the MIT license
//     http://opensource.org/licenses/mit-license.php;//
//

#ifndef __WIO_NODE_H__
#define __WIO_NODE_H__

// for WioNode Pin Assign
#define PORT0_D0    3
#define PORT0_D1    1
#define PORT1_D0    5
#define PORT1_D1    4

#define I2C_SCL     PORT1_D0
#define I2C_SDA     PORT1_D1

#define BUTTON_FUNC 0

#define LED_BLUE    2
#define GROVE_PWR   15

// initialize functions for WioNode.
#define LED_ON()  {digitalWrite(LED_BLUE, LOW);}
#define LED_OFF() {digitalWrite(LED_BLUE, HIGH);}
#define ENABLE_GROVE_CONNECTOR_PWR() {pinMode(GROVE_PWR, OUTPUT);digitalWrite(GROVE_PWR, HIGH);}
#define INIT_WIO_NODE() {pinMode(BUTTON_FUNC, INPUT);pinMode(LED_BLUE, OUTPUT);ENABLE_GROVE_CONNECTOR_PWR();LED_OFF();}


#endif // #ifndef __WIO_NODE_H__
