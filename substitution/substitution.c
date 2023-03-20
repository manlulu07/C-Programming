#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //check that there is 1 command line
if (argc != 2)
{
    printf("Usage: ./substitution key\n");
    return 1;
}
//check that there is only 26 characters on the key
 string key = argv[1];
   for (int i = 0; i < strlen(key); i++)
     {
         if(strlen(key) != 26)
         {
             printf("Key must have 26 characters\n");
             return 1;
         }

         // check whether the key consists of alphabetic characters only
         if(!isalpha(key[i]))
         {
             printf("Usage: ./substitution key\n");
             return 1;
         }
     }
    for(int i = 0; i < strlen(key); i++)
         {
             for(int j = i + 1; j < strlen(key); j++)
             {
             if(toupper(key[i]) == toupper(key[j]))
             {
             printf("Usage: ./substitution key\n");
             return 1;
             }
             }
         }

         // Ask for text
         string plaintext = get_string("plaintext: ");

         //convert key to uppercase
    for(int i = 0; i < strlen(key); i++)
        {

         if(islower(key[i]))
         {
             key[i] -= 32;
         }
        }


         //print ciphertext
         printf("ciphertext: ");
    for ( int i = 0; i < strlen(plaintext); i++)
        {
             if(isupper(plaintext[i]))
             {
                 int letter = plaintext[i] - 65;
                 printf("%c",key[letter]);
             }
             else if(islower(plaintext[i]))
             {
                 int letter = plaintext[i] - 97;
                 printf("%c",key[letter] + 32);
             }
             else printf("%c",plaintext[i]);

        }
         printf("\n");


}



