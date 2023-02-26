#include <cs50.h>
#include <math.h>
#include <stdio.h>

void cash(float n)
{
    // turning dollars in cents
    int cents = round(n * 100);
    // variable that counts the number of coins
    int ncoins = 0;

    // while cents is bigger then 0 do
    while (cents > 0)
    {
        // subtract the bigger bite cent and increment ncoins
        if (cents >= 25)
        {
            cents -= 25;
            ncoins++;
        }
        else if (cents >= 10)
        {
            cents -= 10;
            ncoins++;
        }
        else if (cents >= 5)
        {
            cents -= 5;
            ncoins++;
        }
        else if (cents >= 1)
        {
            cents -= 1;
            ncoins++;
        }
    }

    // print the result
    printf("%i\n", ncoins);

};

int main(void)
{

    // preparing the variable input
    float value;
    do
    {
        value = get_float("Input the value that you need change (bigger then 0):");
    }
    while (value <= 0);
    // while value is lesser then 0 ask again

    // if value pass run the cash function
    if (value > 0)
    {
        cash(value);
    }

};