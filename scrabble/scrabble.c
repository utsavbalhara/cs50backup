#include <cs50.h>
#include <stdio.h>
#include <string.h>

int wordscore(string word);
int charscore(char character);

int main(void)
{
    string player1 = get_string("Player 1's word: ");
    string player2 = get_string("Player 2's word: ");

    int player_1s_score = wordscore(player1);
    int player_2s_score = wordscore(player2);

    if (player_1s_score > player_2s_score)
    {
        printf("Player 1 wins!\n");
    }
    else if (player_1s_score < player_2s_score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int wordscore(string word)
{
    int sum = 0;
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        // pick the i_th char from word and calc its score and add it to sum.
        sum += charscore(word[i]);
    }
    return sum;
}

int charscore(char character)
{
    int POINTS[] = {1, 3, 3,  2, 1, 4, 2, 4, 1, 8, 5, 1,  3, 1,
                    1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10, 0};
    // check the char against its corrosponding value and return

    //interesting idea to map alpabets to its corrospodning place in SCORE[] and thus its value.
    if (character >= 65 && character <= 90)
    {
        character -= 65;
    }
    else if (character >= 97 && character <= 122)
    {
        character -= 97;
    }
    else
    {
        // set the last value of POINTS[] to 0 to asign it to any other character other alpahbets
        // (for eg: punctuations).
        character = 26;
    }
    int i = character;
    return POINTS[i];
}
