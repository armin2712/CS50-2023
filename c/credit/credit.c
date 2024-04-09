#include <cs50.h>
#include <stdio.h>

int get_card(void);

int main(void)
{
int credit_card = get_card();
 int x = credit_card % 1000 / 100;
 printf("%i \n",x);
}





int get_card(void)
{
    int card = get_long("Number: \n");
    return card;
}

