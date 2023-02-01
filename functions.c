#include <stdio.h>
#include <sodium.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "header.h"

// Checks for invalid arguments
char** filterArgv(int argc, char *argv[]) {
    // Checks for the number of arguments
    if (argc > 3) {
        fprintf(stderr, "Too many arguments, use ./spg.exe -h to get help on the usage");
    }

    bool l,t;
    char* flag_value = calloc(2, 3 * sizeof(char));
    char** flag_values = malloc(2 * sizeof(char*));

    for (int i = 1; i < argc; i++){
        char* full_argument = argv[i];
        char* value = strrchr(argv[i], '=') + sizeof(char);

        if ((strcmp(strtok(argv[i], "="), "-h")) == 0){
            displayHelpPage();
            exit(1);
        } else if (((strcmp(strtok(argv[i], "="), "length")) == 0) && !l){
            flag_value = value;
            flag_values[0] = flag_value;      //Insert length string into flag_values[0] 
            l = true;
        } else if (((strcmp(strtok(argv[i], "="), "type")) == 0) && !t){
            flag_value = value;
            flag_values[1] = flag_value;      //Insert types string into flag_values[1]
            t = true;
        } else {
            fprintf(stderr, "Invalid option: %s\nexample usage: ./spg.exe length=17  type=AS", strtok(full_argument, "="));
            exit(1);
        }
        }
        if (!l) {
            flag_values[0] = "40";
            printf("No length provided, setting password length to the default value 40. use ./spg.exe -h to see options\n");
        } else if (!t) {
            flag_values[1] = "X";
            printf("No possible chracters provided, using X(all characters) as default. use ./spg.exe -h to see options\n");
        }
        return flag_values;
    }

int interpretLength(char* argstring) {
    int length =  atoi(argstring);
    if (length != 0 && length > 7 && length < 100){
        return length;
    } else {
        fprintf(stderr, "Invalid length provided, please enter a password length between 8-99");
        exit(1);
    }
    
}

char* interpretType(char* type){
    char possible[70] = {'!','@','#','$','%','^','&','*','A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f', 'G', 'g', 'H', 'h', 'I', 'i', 'J', 'j', 'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'O', 'o', 'P', 'p','Q', 'q', 'R', 'r', 'S', 's', 'T', 't', 'U', 'u', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'y', 'Z', 'z','0','1','2','3','4','5','6','7','8','9'};
    bool A = false;
    bool N = false;
    bool S = false;
    
    for (int i = 0; i < strlen(type); i++)
    {
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
            fprintf(stderr, "One or more invalid types: %s", type);
            exit(1);
        }
    }

    size_t possibilities = 0;
    int index = 0;
    char* finalChars = malloc(possibilities);
    if (S) {
        finalChars = realloc(finalChars, possibilities + 8);
        memcpy(finalChars, possible, possibilities + 8);
        possibilities += 8;
    } 
    if (A) {
        finalChars = realloc(finalChars, possibilities + 52);
        memcpy(finalChars + possibilities, possible + 8, possibilities + 52);
        possibilities += 52;
    }
    if (N) {
        finalChars = realloc(finalChars, possibilities + 10);
        memcpy(finalChars + possibilities, possible + 60, possibilities + 10);
        possibilities += 10;
        }
    finalChars[possibilities] = 0;
    return finalChars;
}   


void destroyArray(char** array){
    free(*array);
    free(array);
}

char generateRandomChar(char* chars){
    int possibilities = strlen(chars);
    uint32_t index = randombytes_uniform(possibilities);
    return chars[index];
}

void displayHelpPage(void) {
    FILE* fptr = fopen("res/manpage.txt", "r");
    if (!fptr) {
        printf("There was an error opening the help page file.\n");
        exit(1);
    }
    char c;

    c = fgetc(fptr);
    while (c != EOF)
    {
        putc(c, stdout);
        c = fgetc(fptr);
    }
    fclose(fptr);
}