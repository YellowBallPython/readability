#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//The function that makes the math:
int medicion(string text);

int main(void)
{
    //Our input:
    string text = get_string("Text: ");
    
    //Call to action:
    int grade = medicion(text);
    
    //The grade displayed in the users interface.
    if (grade < 0)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %0.f\n", round(grade));
    }
}

int medicion(string text)
{
    int n_letras = 0, n_oraciones = 0, n_palabras = 1;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            n_letras++;
        }
        else if (text[i] == ' ')
        {
            n_palabras++;
        }
        else if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            n_oraciones++;
        }
    }
    float avg_letras = (n_letras * 100) / (float) n_palabras;
    float avg_oraciones = (n_oraciones * 100) / (float) n_palabras;
    float index = 0.0588 * avg_letras - 0.296 * avg_oraciones - 15.8;
    return round(index);
}
