#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>

// Program to convert plaintext into ciphertext
int main(int argc, string argv[])
{
    // validate command-line arguemnts
    if (argc != 2)
    {
        printf("Error! Use 2 arguments.\n");
        return 1;
    }

    string k = argv[1];
    int i = 0;
    // digit/non digit validate of command-line arguments
    while (k[i] != '\0')
    {
        if (isdigit(k[i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        i++;
    }

    int key = atoi(k);

    // get user input as plaintext
    string input = get_string("plaintext: ");

    printf("ciphertext: ");

    i = 0;
    // validate the user input and convert to ciphertext
    while (input[i] != '\0')
    {
        // check if char in inut is upper case letter
        if (isupper(input[i]))
        {
            int cipher = ((input[i] - 65 + key) % 26) + 65;
            printf("%c", cipher);
        }
        // check if char in inut is lower case letter
        else if (islower(input[i]))
        {
            int cipher = ((input[i] - 97 + key) % 26) + 97;
            printf("%c", cipher);
        }
        // anythong other than letter printed unchabged
        else
        {
            // print the ciphertext as output
            printf("%c", input[i]);
        }

        i++;
    }
    // print new line after the ciphertext output
    printf("\n");


}
