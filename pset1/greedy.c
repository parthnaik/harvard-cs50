#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void) {
	float dollars = -1.0;
	int cents, quarters, dimes, nickels, pennies;

	// Get user input
	while (dollars < 0) {
	    printf("O hai!  How much change is owed? ");
	    dollars = GetFloat();
	}

	// Round to nearest
	cents = (int) round (dollars * 100);

	// Greedy Algorithm

    // Quarters
    quarters = cents / 25;
    cents = cents % 25;
    
    // Dimes
    dimes = cents / 10;
    cents = cents % 10;

    // Nickels
    nickels = cents / 5;
    cents = cents % 5;
    
    // Remaining cents are pennies
    pennies = cents;

	printf("%i\n", quarters + dimes + nickels + pennies);

	return 0;
}
