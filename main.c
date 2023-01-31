#include <stdio.h>
#include <sodium.h>
#include "header.h"


/*char generateRandomChar(void){
        char possible[60] = {'!','@','#','$','%','^','&','*','A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f', 'G', 'g', 'H', 'h', 'I', 'i', 'J', 'j', 'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'O', 'o', 'P', 'p','Q', 'q', 'R', 'r', 'S', 's', 'T', 't', 'U', 'u', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'y', 'Z', 'z'};

        uint32_t index = randombytes_uniform(60);
        return possible[index];
}*/

int main (int argc, char* argv[]) {
        if (sodium_init() == -1) {
        printf("ERROR: Could not initialize libsodium\n");
        return 1;
        }
        int length = 30;
        char password[length];
        for (int i = 0; i < length; i++) {
                password[i] = generateRandomChar();
        }
        for (int i = 0; i < length; i++) {
                printf("%c", password[i]);
        }
        printf("\n");
}

