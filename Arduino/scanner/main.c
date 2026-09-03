

#include "string.h"
#include "scanner.h"
#include "Usart.h"

#include <stdio.h>
#include <stdint.h>
#include <avr/io.h>


#define TRIGGER_PORT _SFR_IO8(0x05)
#define ECHO_PORT _SFR_IO8(0x05)
#define TRIGGER_PIN 7
#define ECHO_PIN 8



// First step is getting the hardware to blink and/or printing Hello World
// Then we want to configure the echo/trigger pins for input/output respectively
// Set their gpio status (High/Low)

void scanner_init() {
  configure_echo(&TRIGGER_PORT, ECHO_PIN);
  configure_trigger(&ECHO_PORT, TRIGGER_PIN);
}

void configure_hardware() {
  USART_init();
  scanner_init();

}

int main() {
  configure_hardware();
  printf("Scanner Activated");

  int counter = 0;
  int start;
  int end;

  while(1) {
    // send_pulse(&TRIGGER_PORT, ECHO_PIN);
    // printf("->");

    // counter = 0;
    // while(!(ECHO_PORT & (1 << ECHO_PIN))) {}
    // start = counter;

    // while(ECHO_PORT & (1 << ECHO_PIN)) {
    //   counter++;
    // }
    // end = counter;
    
    // // stop_pulse(&TRIGGER_PORT, ECHO_PIN);
    // int duration = end - start;
    // float distance = calculate_distance(duration);
    counter++;
    printInt(counter);

    //_delay_ms(60);
  }
}