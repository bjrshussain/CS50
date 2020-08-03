#include <stdio.h>
#include <cs50.h>
#include <math.h>

//Main program to count coin numbers for greedy change/algorithm
int main()
{
    //declare variables and an array for coins
    int coins[4] = {25, 10, 5, 1};
    int count = 0;
    float amount;


    //get user input and validate
    do
    {
        amount = get_float("Amount Owed: ");
    }
    while (amount < 0);

    //change dollar amount to cents
    int cents = round(amount * 100);

    while (cents > 0)
    {
        if (cents >= 25)
        {
            cents -= 25;
            count++;
        }
        else if (cents >= 10)
        {
            cents -= 10;
            count++;
        }
        else if (cents >= 5)
        {
            cents -= 5;
            count++;
        }
        else
        {
           cents -= 1;
           count++;
        }

    }

    printf("%i\n", count);

    return 0;
}
