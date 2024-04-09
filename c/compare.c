#include <cs50.h>
#include <stdio.h>

int main(void)
{
   int x = get_int("What's x? ");
   int y = get_int("What's y? ");

   if (x < y)
   {
    printf("Y is greater than x.\n");
   }
   else if (y < x)
   {
   printf("X is greater than y.\n");
   }
   else
   {
   printf("X and y are equal.\n");
   }
}