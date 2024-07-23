#include <cs50.h>
#include <stdio.h>

void print_row(int space, int hash);

int main(void)
{
    int height = get_int("Height? ");

    for(int i = 0; i < height; i++)
    {
        print_row(height - i - 1, i + 1);
    }
}

void print_row(int space, int hash)
{
    for(int j = space; j > 0; j--)
        {
            printf(" ");
        }

    for(int k = 0; k < hash; k++)
        {
            printf("#");

        }
        printf("\n");
}
