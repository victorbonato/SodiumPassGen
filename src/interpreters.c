#include <declarations.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Converts the length argument string to an int that can be used to set the password buf size
int interpretLength(char* argstring) {
    int length =  atoi(argstring);
    if (length != 0 && length > 7 && length < 100){
        return length;
    } else {
        fprintf(stderr, "Invalid length provided, please enter a password length between 8-99\n");
        exit(1);
    }
    
}

// Interprets the type's argument, making on running time a string containing the possible chars to be choosen by the generateRandomChar function
char* interpretType(char* type){

    // A base array containing all characters possiblities, independent from the user choice
    char possible[70] = {'!','@','#','$','%','^','&','*','A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f', 'G', 'g', 'H', 'h', 'I', 'i', 'J', 'j', 'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'O', 'o', 'P', 'p','Q', 'q', 'R', 'r', 'S', 's', 'T', 't', 'U', 'u', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'y', 'Z', 'z','0','1','2','3','4','5','6','7','8','9'};
    // Bool variables that will store whenever a user want a specific type of character or not
    bool A = false;
    bool N = false;
    bool S = false;
    
    // A loop that will find every type of character provided by the argument, setting the bool variables true;
    for (int i = 0; i < strlen(type); i++)
    {
        // X == ANS
        if (toupper(type[i]) == 'X') {
            A = true;
            N = true;
            S = true;
        } else if (toupper(type[i]) == 'A' && !A) {
            A = true;
        } else if (toupper(type[i]) == 'N' && !N) {
            N = true;
        } else if (toupper(type[i]) == 'S' && !S) {
            S = true;
        } else {
            // If invalid type argument provided, display the problematic argument and exits
            fprintf(stderr, "One or more invalid types: %s", type);
            exit(1);
        }
    }

    // Dinamically adds the desired charactes on a chunk, extracting from the base array and with a pointer to it "*finalChars" 
    // Initialize the counter variable, that keeps track of how many characters are being used, and uses it's value to dinamically perform operations
    size_t possibilities = 0;

    // Allocates initial 0 space to be reallocated later, assigning the ponter to it to "*finalChars"
    char* finalChars = malloc(possibilities);

    // If S(special) characters were selected, reallocate more 8 bytes (8 special characters) to the address pointed by finalChars and copy the characters to it
    if (S) {
        finalChars = realloc(finalChars, possibilities + 8);
        memcpy(finalChars, possible, 8);
        possibilities += 8;
    } 

    // If A(Alpha) characters were selected, reallocate more 52 bytes (26 uppercase and 26 lowercase) to the address pointed by finalChars and copy the characters to it
    if (A) {
        finalChars = realloc(finalChars, possibilities + 52);
        memcpy(finalChars + possibilities, possible + 8, 52);
        possibilities += 52;
    }

    // If N(numeric) characters were selected, reallocate more 10 bytes (0-9) to the address pointed by finalChars and copy the characters to it
    if (N) {
        finalChars = realloc(finalChars, possibilities + 10);
        memcpy(finalChars + possibilities, possible + 60, 10);
        possibilities += 10;
        }

    // Set the final byte to null, marking a string termination
    finalChars[possibilities] = 0;
    
    // Return pointer to the desired characters string 
    return finalChars;
}
