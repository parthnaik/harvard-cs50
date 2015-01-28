#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(int argc, string argv[]) {
    // Error if invalid command line argument
    if (argc != 2) {
        printf("Please specify only one non-negative integer as an argument\n");
        return 1;
    }
        
    // Caesar Cypher
    void caesarEncryption(string p, int k);
    int k = atoi(argv[1]);
    string p;
    
    p = GetString();
    caesarEncryption(p, k);
}

void caesarEncryption(string p, int k) {
    for (int i = 0, n = strlen(p); i < n; i++) {
        if (islower(p[i]))
            printf("%c", ((p[i] - 'a' + k) % 26) + 'a');
        else if (isupper(p[i]))
            printf("%c", ((p[i] - 'A' + k) % 26) + 'A');
        else
            printf("%c", p[i]);
    }
    
    printf("\n");
}
