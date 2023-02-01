#include <stdio.h>
#include <sodium.h>
#include "header.h"

int main (int argc, char* argv[]) {

        // Checks if libsodium could initialize correctly
        if (sodium_init() == -1) {
        printf("ERROR: Could not initialize libsodium\n");
        return 1;
        } 

        char** flag_values = filterArgv(argc, argv);
        
        int length = interpretLength(flag_values[0]);
        char* chars = interpretType(flag_values[1]);
        printf("First char %s\n", chars);
        char password[length];

        // Generate password character by character
        for (int i = 0; i < length; i++) {
                password[i] = generateRandomChar(chars);
        }

        // Display the generated password with an endline
        printf("Password:" );
        for (int i = 0; i < length; i++) {
                printf("%c", password[i]);
        }
        printf("\n");
        free(chars);
        destroyArray(flag_values);
}

