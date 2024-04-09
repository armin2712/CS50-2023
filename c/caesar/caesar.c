#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>



int main(int argc, string argv[])
{

if(argc!=2)
{
    printf("Usage: ./caesar key \n");
    return 1;
}
  for(int i=0,n=strlen(argv[1]); i < n; i++)
 {
    if(!isdigit(argv[1][i]))
    {
     printf("Usage: ./caesar key \n");
     return 1;
    }
 }

int key =atoi(argv[1]);

string plain_text=get_string("Plain text: ");
printf("Cipher text: ");
int x = strlen(plain_text);

for (int j=0; j < x ; j++)
{
    if(!isalpha(plain_text[j]))
    {
        printf("%c",plain_text[j]);

    }
    else if(isupper(plain_text[j]))
    {
        int binary=(int)plain_text[j]-65;
        int c = (binary+key) % 26;
        char alphabet = c + 65;
        printf("%c",alphabet);
    }
    else
    {
        int binary=(int)plain_text[j]-97;
        int c = (binary+key) % 26;
        char alphabet = c + 97;
        printf("%c",alphabet);
    }

}

printf("\n");

}



