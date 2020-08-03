#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// main program to encrypt plaintext into ciphertext
int main(int argc, string argv[])
{
    // check and validate the command line argument
    if (argc != 2)
    {
        printf("Error! Check again1...\n");
        return 1;
    }

    // assign arguement to a variable
    string key = argv[1];

    int i = 0;
    int len = strlen(key);

    // print error message for invalid argument
    if (len != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // create an array of value 0
    string k[26] = { 0 };

    // cvalidate uniqueness of arguemejnt
    while (key[i] != '\0')
    {
        char c = key[i];
        if (isalpha(c) == 0)
        {
            printf("Key should only contain alphabets...\n");
            return 1;
        }

        int index = toupper(c) - 65;
        if (k[index] == 0)
        {
            k[index]++;

        }
        else
        {
            printf("Key must be unique.\n");
            return 1;
        }
        i++;
    }
    // get user input as text
    string text = get_string("plaintext: ");
    // print output as ciphettext
    printf("ciphertext: ");

    // check the user input and print respectiuve ciphet character
    i = 0;
    while (text[i] != '\0')
    {
        if (isupper(text[i]))
        {
            int letter = text[i] - 65;
            printf("%c", toupper(key[letter]));
        }
        else if (islower(text[i]))
        {
            int letter = text[i] - 97;
            printf("%c", tolower(key[letter]));
        }
        else
        {
            printf("%c", text[i]);
        }
        i++;
    }
    printf("\n");
}
