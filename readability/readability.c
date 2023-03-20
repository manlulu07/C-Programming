#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int calculate_grade(string text);
int letters = 0;
int word = 1;
int sentences = 0;


int main(void)
{
//Getting user input
string text = get_string("Text: ");
printf("%s\n",text);

int l = strlen(text);
int length = strlen(text);
int i = 0;
//Calculating number of letters
for(i = 0; i < l; i++)
{
    if(islower(text[i]) || isupper(text[i]))
    letters++;
}
//calculating number of words
    for(i = 0; i < l; i++)
    {

        if(isspace(text[i]))
          word++;
    }
//Calculating number of sentences
    for(i = 0; i < l; i++)
    {
       if(text[i] == '?' || text[i] == '!' || text[i] == '.')
          sentences++;
    }
//Calculating the fina grade

    float index = (0.0588 * letters/word*100) - (0.296 * sentences/word*100) - 15.8;
     int result = round(index);
     if(result < 1)
     {
         printf("Before Grade 1\n");
         return 0;
     }
     else if(result > 16)
     {
         printf("Grade 16+\n");
         return 0;
     }
    else
   {
             printf("Grade %i\n",result);

   }
}






