#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

long double get_words(string text);
long double get_letters(string text);
long double get_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    long double L = (get_letters(text) * 100) / get_words(text);
    long double S = (get_sentences(text) * 100) / get_words(text);
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index < 17)
    {
        printf("Grade %i\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }

    // testing
    //  printf("%Lf %Lf %Lf\n", get_letters(text), get_sentences(text), get_words(text));
    //  printf("L %Lf, S %Lf\n", L, S);
}

long double get_words(string text)
{
    // - total words

    long double words = 0;
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    if (text[len - 1] == '.')
    {
        words++;
    }
    return words;
}

long double get_letters(string text)
{
    // - total letters

    long double letters = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isupper(text[i]) || islower(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

long double get_sentences(string text)
{
    // - total number of sentences

    long double sentences = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }
    return sentences;
}
