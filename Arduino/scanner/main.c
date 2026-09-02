

#include "string.h"
#include "Usart.h"

#include <stdio.h>
#include <stdint.h>

#ifndef

#define TRIGGER_PORT
#define TRIGGER_PIN
#define ECHO_PORT
#define ECHO_PIN

#endif


// First step is getting the hardware to blink and/or printing Hello World
// Then we want to configure the echo/trigger pins for input/output respectively
// Set their gpio status (High/Low)

void scanner_init() {
  configure_echo(ECHO_PORT, ECHO_PIN);
  configure_trigger(TRIGGER_PORT, TRIGGER_PIN);
}

void configure_hardware() {
  USART_init();
  scanner_init();

}

int main() {
  configure_hardware();
  printf("Scanner Activated");

  while(1) {
    
  }
}