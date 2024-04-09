// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string str);

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./no-vowels word \n");
        return 1;
    }


 printf("%s \n", replace(argv[1]));


}


string replace(string str)
{
    int length = strlen(str);
    for(int i = 0; i < length; i++ )
    {
         switch (str[i])
    {
        case 'a':
        str[i] = '6';
        break;
        case 'e':
        str[i] = '3';
        break;
        case 'i':
        str [i] = '1';
        break;
        case 'o':
        str [i] = '0';
        break;
    }

    }

    return str;




}