#include <stdio.h>
#include <cs50.h>
#include <math.h>

float findAverage(int count, int words);
int grade(int num);

int main(void)
{
    string text = get_string("Text: ");

    int i = 0;
    int words = 0;
    int sentences = 0;
    int letters = 0;


    while (text[i] != '\0')
    {
        if (text[i] == 32)
        {
            words++;
        }
        else if ( text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences++;
        }
        else if ((text[i] >= 'a' && text[i] <='z') || (text[i] >= 'A' && text[i] <='Z'))
        {
            letters++;
        }
            i++;
    }
    words++;

    int index = round(0.0588 * findAverage(letters, words) - 0.296 * findAverage(sentences, words) - 15.8);


    grade(index);
}

float findAverage(int count, int words)
{
    return (float) count / (float) words * 100;

}

int grade(int value)
{
    if (value < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (value >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", value);
    }
    return 0;
}
