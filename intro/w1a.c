#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h = get_int("height? ");
    int i = 1;

    while(i <= h)
    {
        for(int k = h - i; k > 0; k--)
        {
            printf(" ");
        }

        for(int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("  ");
        for(int j = 1; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");

        i++;
    }
}
