#include <cs50.h>
#include <stdio.h>

int size(void);
void print_bricks(int height);


int main(void)
{

    int blocks = size();
    print_bricks(blocks);


}

 int size(void)

 {
    int height;

    do
    {
        height=get_int("Please input a height size betwen 1 and 8.\n");
    }
    while(height > 8 || height < 1);
    return height;

 }


void print_bricks(int x)
{
    int row,column;
    int height = x;



    for ( row = 0; row < height; row++ )
    {
     printf("\n");
     for (column = 0; column < height - row-1; column++ )
     {
     printf(" ");
     }


     for (column = 0; column <= row; column++ )
     {
     printf("#");

     }
    }




printf("\n");

    }

