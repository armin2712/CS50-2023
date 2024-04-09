#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    bool istrue=true;

    if(argc!=2)
    {
        printf("Usage: ./substitution key \n");
        istrue=false;
    }

    else if(strlen(argv[1])!=26)
    {
     printf("Key must contain 26 characters. \n");
     istrue=false;
    }

    else
    {
     for(int i = 0; i < strlen(argv[1]); i++)
     {
        if(isdigit(argv[1][i]))
        {
         printf("Key must contain only contain alphabetic characters. \n");
         istrue=false;

        }

        for(int j = i+1; j < strlen(argv[1]); j++ )
        {
            if(argv[1][i]==argv[1][j])
            {
                printf("Key must not contain repeated characters.\n");
                istrue=false;

            }

        }
      }

      }



      if(istrue==true)
      {

     string text = get_string("plaintext: ");
     printf("ciphertext: ");

     for(int k = 0; k < strlen(text); k++)
     {
        if(isupper(text[k]))
        {
            int binary=(int)text[k]-65;
            if(isupper(argv[1][binary])) printf("%c",argv[1][binary]);
            else
            {
                int binary_low=(int)argv[1][binary]-97;
                char abc=binary_low + 65;
                printf("%c", abc);
            }
        }
        else if(islower(text[k]))
        {
            int binary=(int)text[k]-97;
            if(islower(argv[1][binary])) printf("%c",argv[1][binary]);
            else
            {
                int binary_upp=(int)argv[1][binary]-65;
                char abc=binary_upp + 97;
                printf("%c", abc);
            }

        }

        else
        {
            printf("%c",text[k]);
        }

     }
     printf("\n");
      }

}

