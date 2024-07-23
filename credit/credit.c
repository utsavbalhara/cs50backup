#include <cs50.h>
#include <stdio.h>

int get_digit(long number, int place);
int get_digits_count(long number);
int digit_adder(int number);

int main(void)
{
    // luhn's algo
    // start---
    int part1 = 0;
    int part2 = 0;
    int valid = 0;
    long number = get_long("Number: ");
    int digits_count = get_digits_count(number);

    if (digits_count % 2 == 0)
    {
        for (int i = 0; i < digits_count; i += 2)
        {
            int place = i + 2;
            part1 += digit_adder(2 * get_digit(number, place));
        }
        for (int i = 0; i < digits_count + 1; i += 2)
        {
            int place = i + 1;
            part2 += get_digit(number, place);
        }
    }
    else
    {
        for (int i = 0; i < digits_count - 1; i += 2)
        {
            int place = i + 2;
            part1 += digit_adder(2 * get_digit(number, place));
        }
        for (int i = 0; i < digits_count; i += 2)
        {
            int place = i + 1;
            part2 += get_digit(number, place);
        }
    }
    // end---

    // check credit card company using first digits
    if (get_digit(number, digits_count) == 3)
    {
        if (get_digit(number, digits_count - 1) == 4 || get_digit(number, digits_count - 1) == 7)
        {
            valid = 1;
        }
    }
    else if (get_digit(number, digits_count) == 5)
    {
        if (get_digit(number, digits_count - 1) == 1 || get_digit(number, digits_count - 1) == 2 ||
            get_digit(number, digits_count - 1) == 3 || get_digit(number, digits_count - 1) == 4 ||
            get_digit(number, digits_count - 1) == 5)
        {
            valid = 2;
        }
    }
    else if (get_digit(number, digits_count) == 4)
    {
        valid = 3;
    }

    // validate checksum and dsiplay result
    if ((part1 + part2) % 10 == 0)
    {
        if (valid == 1 && digits_count == 15)
        {
            printf("AMEX\n");
        }
        else if (valid == 2 && digits_count == 16)
        {
            printf("MASTERCARD\n");
        }
        else if (valid == 3 && digits_count == 13)
        {
            printf("VISA\n");
        }
        else if (valid == 3 && digits_count == 16)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

// supporting functions

// Get the required digit from the right
int get_digit(long number, int place)
{

    // adjusting to zero based index
    place--;

    for (int i = 0; i < place; i++)
    {
        number /= 10;
    }
    return number % 10;
}

// gets the total number of digits in a number
int get_digits_count(long number)
{

    int i = 1;
    long div = number / 10;
    while (div > 0)
    {
        div /= 10;
        i++;
    }
    return i;
}

// adds the digits of a number
int digit_adder(int number)
{
    int sum = 0;
    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}
