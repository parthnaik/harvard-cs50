#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

// Function Declarations
char caesarEncryption(char p, int k);

int main(int argc, string argv[]) {
    // Error if invalid command line arguments or invalid key
    if (argc != 2) {
        printf("Please use one command line argument to specify cipher key.\n");
        return 1;
    }
    
    for (int i = 0, n = strlen(argv[1]); i < n; i++) {
        if (isalpha(argv[1][i]) == false) {
            printf("Invalid key. Please use only alphabetical characters for key.\n");
            return 1;
        }
    }
    
    // Variable Declarations
    string k = argv[1];
    string p;
    int counter = 0, kLength = strlen(k);
    int kArray[kLength];
    
    // Convert key into lowercase
    for (int i = 0; i < kLength; i++)
        if (isupper(k[i]))
            k[i] = tolower(k[i]);        
    
    // Store key in an array
    for (int i = 0; i < kLength; i++) {
        kArray[i] = k[i] - 97;
    }
    
    // Get plaintext
    p = GetString();
    
    // Vigenere Cipher Encryption
    for (int i = 0, n = strlen(p); i < n; i++) {
        if (!isalpha(p[i])) {
            printf("%c", p[i]);
        } else {
            printf("%c", caesarEncryption(p[i], kArray[counter]));
            
            // Increment counter when appropriate
            if (counter < kLength - 1)
                counter++;
            else
                counter = 0;
        }
    }
    
    printf("\n");
}

char caesarEncryption(char p, int k) {
    if(islower(p)) {
        return (((p - 'a' + k) % 26) + 'a');
    } else {
        return (((p - 'A' + k) % 26) + 'A');
    }
}
