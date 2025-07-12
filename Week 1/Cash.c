#include <stdio.h>

int main(void) {
    int Change;
    
    do {
        printf("Change owed: ");
        scanf("%d", &Change);
    } while (Change < 1);

    int quarters, dimes, nickels, pennies, sub;

    quarters = Change / 25;
    sub = Change % 25;
    dimes = sub / 10;
    sub = sub % 10;
    nickels = sub / 5;
    pennies = sub % 5;

    Change = quarters + dimes + nickels + pennies;

    printf("%d", Change);

    return 0;
}