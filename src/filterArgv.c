#include "declarations.h"

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
    
    // Allocates space for a 2d array(an array of pointers that points to pointers, and these point to strings)
    // A pointer for 2 * 3 bytes spaces
    //char* flag_value = malloc(6);
    //char* flag_value = calloc(2,3);

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
                memcpy(flag_values[0], value, 4);
	    } else {
                fprintf(stderr,"Invalid length.\n");
		exit(1);
	    }
            //flag_values[0] = value;      //Insert length string into flag_values[0] 
            l = true;
            // If type detected add it to the return 2d array on index 1
        } else if (((strcmp(strtok(argv[i], "="), "type")) == 0) && !t){
	    if (strlen(value) <= 3){
                memcpy(flag_values[1], value, 3);	
	    } else {
                fprintf(stderr, "Invalid types of characters\n");
		exit(1);
	    }

            //flag_values[1] = value;      //Insert types string into flag_values[1]
            t = true;
            // If the option is not valid, display the not valid option to stderr and quit
        } else {
            fprintf(stderr, "Invalid option: %s\nexample usage: ./spg.exe length=17  type=AS\n", strtok(argv[i], "="));
            exit(1);
        }
        }

        // If mandatory options were not provided, set to default value, print to stderr and continue
        if (!l) {
            flag_values[0] = "40";
            fprintf(stderr,"No length provided, setting password length to the default value 40. use ./spg.exe -h to see options\n");
        } else if (!t) {
            flag_values[1] = "X";
            fprintf(stderr,"No possible chracters provided, using X(all characters) as default. use ./spg.exe -h to see options\n");
        }
        
        // Return the 2d array pointer
        return flag_values;
    }
