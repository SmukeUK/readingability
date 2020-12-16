#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    int nchar = 0;
    int nwords = 1;
    int nsents = 0;

    // Get text to analyse from user
    char *text = get_string("Text: ");
    
    // Calculate number of characters in the string.
    int charlen = strlen(text);
    for (int i = 0; i != charlen; i++)
    {
        // Remove spaces
        if (isalnum(text[i]))
        nchar++;
        // Count numbers of words.
        else if (text[i] ==' ' || text[i] == '\0')
        nwords++;
    }
    // Count number of sentences
    for (int j = 0; j < charlen; j++)
    {
        // Count ./!/?
        if (text[j] == '.' || text[j] == '?' || text[j] == '!')
        {
            nsents++;
        }
    }
    
    // Calculate average number of letters per 100 words.
    float l = ((float)nchar/nwords)*100;
    
    // Calculate average number of sentences per 100 words.
    float s = ((float)nsents/nwords)*100;
    
    // Work out Coleman-Liau Index Grade
    float grade = (0.0588 * l) - (0.296 * s) - 15.8;
    
    // Print Grades
    if (roundf(grade) >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (roundf(grade) < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        int index = roundf(grade);
        printf("Grade %i\n", index);
    }
}
