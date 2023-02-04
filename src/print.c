#include "declarations.h"

// Quick function for printing dashes, making a line
void printDashes(size_t amount) {
    for (int i = 0; i < amount; i++) {
                printf("--");
        }
        printf("\n");
}

// Display the the password generated in a proper way based on it's length
void displayPassword(char* passwd, size_t length) {
    printf("\n");
    printf("Your %d digit generated Password:\n" ,length);
    printDashes(length);
    printDashes(length);
    for (int i = 0; i < length; i++) {
            printf("%c", passwd[i]);
    }
    printf("\n");
    printDashes(length);
    printDashes(length);
    printf("END OF PASSWORD\n");
    printDashes(length);
    printf("\n");
}

// Display the help message contained in the manpage.txt fle
void displayHelpPage(void) {
    // Open file stream
    FILE* fptr = fopen("../res/helppage.txt", "r");
    // Checks for errors upon handling it
    if (!fptr) {
        printf("There was an error opening the help page file.\n");
        exit(1);
    }

    // Prints the file contents preserving format
    char c;
    c = fgetc(fptr);
    while (c != EOF)
    {
        putc(c, stdout);
        c = fgetc(fptr);
    }
    fclose(fptr);
}
