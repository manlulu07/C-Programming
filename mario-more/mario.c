#include <cs50.h>
#include <stdio.h>

int main(void)
{
int i, j, k, l;
do
{
i = get_int("enter height:");
}
while (i < 1 || i > 8);

for (j = 0; j < i ;j++)
{
   for (l = 0; l < i - j - 1; l++)
   printf(" ");
   for (k = 0; k <= j; k++)
   {
      printf("#");
   }
   printf("  ");

    for (k = 0; k <= j; k++)
   {
      printf("#");
}
   printf("\n");

}
}



