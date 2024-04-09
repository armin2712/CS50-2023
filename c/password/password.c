// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool lower=false;
    bool upper=false;
    bool number=false;
    bool symbol=false;

    int length = strlen(password);

    for( int i = 0; i < length; i++)
    {
        switch (password[i])
        {
            case 97 ... 122:
            lower=true;
            break;
            case 65 ... 90:
            upper=true;
            break;
            case 48 ... 57:
            number=true;
            break;
            case 33 ... 47:
            symbol=true;
            break;
            case 58 ... 64:
            symbol=true;
            break;
        }
    }

    if(lower==true && upper==true && number==true && symbol==true){
        return true;
    }
    return false;
}
