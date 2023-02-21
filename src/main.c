#include <declarations.h>
#include <stdio.h>
#include <stdlib.h>
#include <sodium.h>

//quick function for freeing allocated two dimensions arrays
void destroyArray(char** array){
    for (int i = 0; i < 2; i++) {
        free(array[i]);
    }
        free(array);
}

int main (int argc, char* argv[]) {

        // Checks if libsodium could initialize correctly
        if (sodium_init() == -1) {
        fprintf(stderr,"ERROR: Could not initialize libsodium\n");
        return 1;
        } 

        // Gets the string values of arguments and abort if something is wrong
        char** flag_values = filterArgv(argc, argv);
        
        // Interprets the user input, making the arguments provided make sense
        size_t length = interpretLength(flag_values[0]);
        char* chars = interpretType(flag_values[1]);
        
        

        // Allocates space in memory for the password
        char password[length];

        // Generate password character by character and stores it in the "password" array
        for (int i = 0; i < length; i++) {
                //passes the chars pointer to string containing the possible characters selected by user
                password[i] = generateRandomChar(chars);
        }

        // Display the generated password properly
        displayPassword(password, length);

        //free memory
	free(chars);
        destroyArray(flag_values);
        // End program
        return 0;
}

