#include <cs50.h>
#include <stdio.h>




int main(void)
{
  string name=get_string("What is your name? \n");
  int age=get_int("What is your age? \n");
  string phone=get_string("What is your phone number? \n");

  printf("%s ,%i , Number:%s \n", name,age, phone);


}






