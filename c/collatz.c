#include <cs50.h>
#include <stdio.h>
#include <string.h>

int collatz(int n,int count);

int main(void)
{
int number=get_int("Input number: ");
int count=0;
printf("%i \n",collatz(number,count));

}

int collatz(int n,int count)
{
    if(n==1)
    {
        return count;
    }
    else if(n%2==0)
    {
        return collatz(n/2,count+=1);
    }
    else return collatz(3*n+1,count+=1);
}

