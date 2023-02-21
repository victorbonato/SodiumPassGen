#include <declarations.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

// Identify arguments on argv[] strings and extract it's values to strings, then add the strings to the return 2d array
char** filterArgv(int argc, char *argv[]) {

    // Checks for the number of arguments and exits displaying an error message if wrong behaviour is found
    if (argc > 3) {
        fprintf(stderr, "Too many arguments, use ./spg.exe -h to get help on the usage");
        exit(1);
    }

    // Declares the bool variables length and type, that inform if the user have provided them or not, if not we're going to set default values, 
    // as C does not provide default parameters
    bool l,t;

    // A pointer to a space of 2 char pointers, each pointing to 3 byte strings
    char** flag_values = malloc(2 * sizeof(char*));
    for (int i = 0; i < 2; i++){
        flag_values[i] = malloc(4); 
	}
     
    // A loop to find keys and values in the argument
    for (int i = 1; i < argc; i++){

        // Extract the value from argument, the right side of '='
        char* value = strrchr(argv[i], '=') + 1;

       // Compare the key argument, left side of '=', if it matches valid key arguments, add it to the return array;
        // If -h flag detected, display and quit
        if ((strcmp(strtok(argv[i], "="), "-h")) == 0){
            displayHelpPage();
            exit(1);
            // If length detected add it to the return 2d array on index 0
        } else if (((strcmp(strtok(argv[i], "="), "length")) == 0) && !l){
	    if (strlen(value) <= 3){
                memcpy(flag_values[0], value, 2);
                flag_values[0][2] = 0;
	    } else {
                fprintf(stderr,"Invalid length.\n");
		        exit(1);
	    }
            //flag_values[0] = value;      //Insert length string into flag_values[0] 
            l = true;
            // If type detected add it to the return 2d array on index 1
        } else if (((strcmp(strtok(argv[i], "="), "type")) == 0) && !t){
        if (strlen(value) <= 3){
                memcpy(flag_values[1], value, strlen(value));
                flag_values[1][strlen(value)] = 0;	
	    } else {
                fprintf(stderr, "Invalid types of characters\n");
		        exit(1);
	    }

            //flag_values[1] = value;      //Insert types string into flag_values[1]
            t = true;
            // If the option is not valid, display the not valid option to stderr and quit
        } else {
            fprintf(stderr, "Invalid option: %s\nexample usage: ./sogen length=17  type=AS\n", strtok(argv[i], "="));
            exit(1);
        }
        }

        // If mandatory options were not provided, set to default value, print to stderr and continue
        if (!l) {
            char* default_l = "40";
            memcpy(flag_values[0], default_l, 2);
            flag_values[0][2] = 0;
            printf("No length provided, setting password length to the default value 40. use ./sogen -h to see options\n");
        } 
        if (!t) {
            char* default_type = "X";
            memcpy(flag_values[1], default_type, 1);
            flag_values[1][1] = 0;
            printf("No possible character types provided, using X(all characters) as default. use ./sogen -h to see options\n");
        }
        printf("%s %s\n", flag_values[0], flag_values[1]);
        // Return the 2d array pointer
        return flag_values;
    }
