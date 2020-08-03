#include <stdio.h>
#include <cs50.h>

// main prgram to create a two sided pyramid
int main(void)
{
    //declare variables
    int height;
    char c = '#';

    //get input and validate it
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    //loop to create pyramid
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (j < height - (i + 1))
            {
                printf(" ");
            }
            else
            {
                printf("%c", c);
            }
        }
        printf(" ");
        printf(" ");

        for (int k = 0; k <= i; k++)
        {
            printf("%c", c);
        }
        printf("\n");
    }
}
