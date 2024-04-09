#include <cs50.h>
#include <stdio.h>

float llama_perYear(int start, int end);
int get_start(void);
int get_end(int start);

int main(void)
{
    // TODO: Prompt for start size

int start_size = get_start();

    // TODO: Prompt for end size
int end_size = get_end(start_size);

    // TODO: Calculate number of years until we reach threshold


    // TODO: Print number of years
    printf("To reach the end population it would take %.0f years!\n", llama_perYear(start_size , end_size));

}

float llama_perYear(start,end)
{

    int n=0;
    int year = start;
    int born_llamas;
    int pass_llamas;

    while ( year < end)
    {
        born_llamas = year / 3;
        pass_llamas = year / 4;

        year = year + (born_llamas - pass_llamas);

        n++;

    }


return n;

};

int get_start(void)
{
int starting;
    do {
        starting=get_int("What is the starting population? \n");
    }
    while (starting < 9);
    return starting;

};

int get_end(start)
{
     int ending;
    do {
        ending=get_int("What is the ending population? \n");
    }
    while (ending <= start);
    return ending;
};