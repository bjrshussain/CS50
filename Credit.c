#include <stdio.h>
#include <cs50.h>

// main program for credit card number verification
int main(void)
{
    //prompt user for card number
    long cardNumber = get_long("Number: ");

    //declare variables
    int sum = 0;
    int product = 0;
    int count = 1;
    long divisor = 1;
    long number = cardNumber;

    //loop to get product and sum of card digits
    while (number > 0)
    {
        int last = number % 10;
        number =  number / 10;

        //check if the index is even/odd. if odd add to sum, else take product * 2
        if (count % 2 != 0)
        {
            sum = sum + last;
        }
        else
        {
            int temp = last * 2;

            //check if the product is multidigit. if yes get digit sum
            if (temp >= 10)
            {
                last = temp % 10; // 12 % 10 = 2
                temp = last + (temp / 10); // 12 / 10 = 1
            }
            product = product + temp;
        }

        divisor = divisor * 10;
        count++;
    }

    //find first two digits, total and card length
    int digits = cardNumber / (divisor / 100);
    int total = sum + product;
    int length = count - 1;

    //check if card number satisfies the condition for verification
    if (total % 10 == 0)
    {
        if (length == 15 && (digits == 34 || digits == 37))
        {
            printf("AMEX\n");

        }
        else if (length == 16 && (digits == 51 || digits == 52 || digits == 53 || digits == 54 || digits == 55))
        {
            printf("MASTERCARD\n");

        }
        else if ((length == 13 || length == 16) && (digits / 10 == 4))
        {
            printf("VISA\n");

        }
        else
        {
            printf("INVALID\n");

        }

    }
    else
    {
        printf("INVALID\n");
    }

    return 0;

}
