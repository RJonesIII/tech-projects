

#include "scanner.h"

void configure_echo(volatile uint8_t *PORT, uint8_t PIN) {
  uint8_t DDR = PORT-0x01;      // Data direction register, set to 1 for output / 0 for input
  DDR &= ~(1 << PIN);  // Ensure that Data Direction is 0 for input
  
  // NULL
}
void configure_trigger(volatile uint8_t *PORT, uint8_t PIN) {
  uint8_t DDR = PORT-0x01;      // Data direction register, set to 1 for output / 0 for input
  DDR &= (0 << PIN);  // Ensure that Data Direction is clear
  DDR &= (1 << PIN);    // then set for output
  // NULL
}
float calculate_distance(int delay) {
  float distance = delay * .343/2;
  return distance;
}
void send_pulse(volatile uint8_t *PORT, uint8_t PIN) {
  *PORT ^= (1 << PIN);
}
void stop_pulse(volatile uint8_t *PORT, uint8_t PIN) {
  *PORT &= ~(1 << PIN);
}