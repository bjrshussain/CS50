#include <stdio.h>
#include <cs50.h>


// Hello Program for cs50 pset1
int main(void)
{
    printf("hello world\n");
    string name = get_string("Enter name\n");
    printf("Name is %s", name);
    return 0;
}
