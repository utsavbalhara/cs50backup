#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("Hello, what is your name? ");
    int age = get_int("\nAnd how old are you? ");
    string tele = get_string("\nWhat is your phone number? ");
    int i = 0;

    while (i == 0)
    {
    char response = get_char("\nWould you like to view your details? ");

        if (response == 'y')
        {
            printf("Name: %s  Age: %i  tele: %s \n", name, age, tele);
            i--;
        }
        else if (response == 'n')
        {
            printf("Ok");
        }
        else
        {
            printf("Invalid response");
        }
    }



}
