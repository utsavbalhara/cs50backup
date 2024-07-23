#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string first_name = get_string("What is your first name? \n");
    printf("hello, %s\n", first_name);
}
