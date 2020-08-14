#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // initializing text promt and counters for equation 
    string text = get_string("Text: ");
    int lettercounter = 0;
    int wordcounter = 1;
    int sentencecounter = 0;

    // for loop to count letters words and sentences. 
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            lettercounter++;
        }
        else if (text[i] == ' ')
        {
            wordcounter++;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentencecounter++;
        }
    }
    // printf("%d letters\n", lettercounter);
    // printf("%d words\n", wordcounter);
    // printf("%d sentences\n" , sentencecounter);
    
    
    
    //  equation to calculate and output the grade
    float L = (lettercounter * 100) / wordcounter;
    float S = (sentencecounter * 100) / wordcounter;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);
    
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }
}
