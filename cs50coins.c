#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float getChangeValue;

    // retrieve change amount from user but check for valid input
    do
    {
        getChangeValue = get_float("Change owed: ");
    }
    while (getChangeValue <= 0.00);

    // convert dollars to change values
    int c = 0;

    while (getChangeValue > 1)
    {
        c = c + 100;
        getChangeValue--;
    }

    int b = round(getChangeValue * 100) + c; // add converted dollars to change
    int totalCoins = 0;

    // convert quarters
    if (b >= 25)
    {
        totalCoins = b / 25;
        b = b - ((b / 25) * 25);
    }

    // dimes
    if (b >= 10)
    {
        totalCoins = totalCoins + (b / 10);
        b = b - ((b / 10) * 10);
    }

    // nickels
    if (b >= 5)
    {
        totalCoins = totalCoins + (b / 5);
        b = b - ((b / 5) * 5);
    }

    // pennies
    if (b >= 1)
    {
        totalCoins = totalCoins + (b / 1);
        b = b - ((b / 1) * 1);
    }

    // display result
    printf("%i\n", totalCoins);
}
