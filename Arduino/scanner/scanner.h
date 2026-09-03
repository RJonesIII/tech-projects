
#include <avr/io.h>
#include <stdint.h>


void configure_echo(volatile uint8_t *PORT, uint8_t PIN);
void configure_trigger(volatile uint8_t *PORT, uint8_t PIN);
void send_pulse(volatile uint8_t *PORT, uint8_t PIN);
void stop_pulse(volatile uint8_t *PORT, uint8_t PIN);
float calculate_distance(int delay);