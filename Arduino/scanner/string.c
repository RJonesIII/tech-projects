

#include "string.h"

// Prints out strings
void printf(char* string) {
  while(*string) {
    USART_Write(*string++);
  }
  USART_Write('\r\n');
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