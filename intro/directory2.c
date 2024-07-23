#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("Hello, what is your name? ");
    int age = get_int("\nAnd how old are you? ");
    string tele = get_string("\nWhat is your phone number? ");

    while(true)
    {
        char response = get_char("\nWould you like to view your details? ");

        if (response == 'y')
        {
            printf("Name: %s  Age: %i  tele: %s \n", name, age, tele);
            break; // Exit the loop
        }
        else if (response == 'n')
        {
            printf("Ok\n");
        }
        else
        {
            printf("Invalid response\n");
        }
    }
}
