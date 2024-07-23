#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int change;
    int coins = 0;
    int leftover = 0;
    while (true)
    {
        change = get_int("Change owed: ");
        if (change >= 0)
        {
            break;
        }
    }

    coins += change / 25;
    leftover = change % 25;
    coins += leftover / 10;
    leftover %= 10;
    coins += leftover / 5;
    leftover %= 5;
    coins += leftover / 1;

    printf("%i\n", coins);
}
