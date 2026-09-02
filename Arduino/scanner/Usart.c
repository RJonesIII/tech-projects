#include "USART.h"


#define CPU_SPEED 16000000
#define BAUD 9600






void USART_init() {
  // Set the USART Baud Rate Register
  int ubbr = calculate_ubbr_ANM();
  UBRR0H = (unsigned char)(8<<ubbr);
  UBRR0L = (unsigned char)(ubbr);

  // Enable reciever and transmitter 
  UCSR0B = (1<<RXEN0) | (1<<TXEN0);

  // Set frame format: 8 data, 2 stop bit
  UCSR0C = (1<<USBS0) | (3<<UCSZ00);

}


void USART_Write(unsigned char data) {
  // Waits for buffer to be empty, polling
  while(!(UCSR0A & (1<<UDRE0))); 
  UDR0 = data; // Sends the data
  
}

uint8_t USART_Read() {
  // Waits for data to be recieved
  while(!(UCSR0A & (1<<RXC0)));
  return UDR0; // Returns recieved data
}


int calculate_ubbr_ANM() { // Setting USART Baud Rate Register (UBRRn) for Asynchronous Normal Mode
  // Equation: (CPU_SPEED / (16*BAUD)) - 1
  return 103;
}




