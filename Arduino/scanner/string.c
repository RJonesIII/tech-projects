

#include "string.h"

// Prints out strings
void printf(char* string) {
  while(*string) {
    USART_Write(*string++);
  }
  USART_Write('\r\n');
}

void printInt(uint16_t num) {  // Only works for ints from 0 to 65535

  // Start with a char array filled with '0'
  char result[] = {'0', '0', '0', '0', '0'};
  // Loops through the number and gets each digit 
  uint16_t power = 10;
  int index = 4;

  for(int i = 0; i < 5; i++) {
    uint8_t digit = (num % power)/(power/10); // This isolates the number and then turns it into a digit i.e 30 -> 3
    char c_digit = (digit + 48); // Turns the int to it's char counterpart
    result[index] = c_digit; // Adds them to the end of the character array
    index--;
    power *= 10; // Power goes up for the next digit
  }

  index = 0;
  while(result[index] == '0') { // After, checks to see when the first digits starts and doesn't print till then
    index++;
    if(index == 4) {
      USART_Write('0');
      return;
    }
  }

  while(index < 5) {
    USART_Write(result[index]);
    index++;
  }
  USART_Write('\r\n'); // Newline
}

// Changes integers to strings
char* to_string(int num) {
  char buffer[10];
  sprintf(buffer, "%d", num);
  return buffer;
}

// Appends string 2 onto string 1
char*  append(char* str1, char* str2) {
  int i = 0;
  int new_size = sizeof(str1) + sizeof(str2);
  char* buffer[new_size];

  for(i = 0; i < sizeof(str1); i++) {
    buffer[i] = str1[i];
  }

  for(int j = 0; j < sizeof(str2); j++) {
    buffer[i] = str2[j];
  }

  return buffer;
}