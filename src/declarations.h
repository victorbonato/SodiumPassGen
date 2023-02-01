#include <stdio.h>
#include <sodium.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

char generateRandomChar(char* chars);
void displayHelpPage(void);
char** filterArgv(int argc, char *argv[]);
void destroyArray(char** array);
int interpretLength(char* argstring);
char* interpretType(char* type);
void printDashes(size_t amount);
void displayPassword(char* passwd, size_t length);