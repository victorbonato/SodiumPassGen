#include "declarations.h"

// Generates a ramdom uint32_t value, and use it to choose among the possible characters provided 
char generateRandomChar(char* chars){
    size_t possibilities = strlen(chars);
    uint32_t index = randombytes_uniform(possibilities);
    return chars[index];
}