#include <stdio.h>
#include <cs50.h>

int main(void) {
    int height;
    
    // Get pyramid height from user
    do {
        printf("Height: ");
        height = GetInt(); 
    } while (height < 0 || height > 23);
    
    if (height == 0)
        return 0;
    
    // Loop to print pyramid
    for (int i = 2; i <= height + 1; i++) {
        for (int k = 0; k <= (height - i); k++)
            printf(" ");
            
    for (int j = 1; j <= i; j++)
        printf("#");
        
    printf("\n");
    }
    
    return 0;
}
