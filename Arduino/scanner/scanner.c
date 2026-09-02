

#include "scanner.h"

void configure_echo(uint8_t PORT, uint8_t PIN);
void configure_trigger(uint8_t PORT, uint8_t PIN);
float calculate_distance(int delay);
void send_pulse();
void stop_pulse();