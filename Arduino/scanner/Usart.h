
#ifndef __ARDUINOUNO3_USART_H
#define __ARDUINOUNO3_USART_H

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

void USART_init();
void USART_Write(uint8_t data);
uint8_t USART_Read();
int calculate_ubbr_ANM();
void USART_IRQHandler();



#endif