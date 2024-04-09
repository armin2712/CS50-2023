#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>
#include <stdbool.h>


#define BLOCK_SIZE 512



int main(int argc, char *argv[])
{

    if(argc!=2)
    {
        printf("Invalid input! \n");
        return 1;
    }

   char *file=argv[1];

    FILE* mem_card=fopen(file,"r");
     if(mem_card==NULL)
    {
        printf("File not found.\n");
        return 1;
    }
    bool first_jpg=false;
    int file_counter=0;
    uint8_t buffer[BLOCK_SIZE];
    char img_name[8];
    FILE* img=NULL;

    while(fread(buffer,BLOCK_SIZE,1,mem_card)==1)
    {
        if(buffer[0]==0Xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3] & 0xf0) == 0xe0)
        {
             if(first_jpg)
           {
            fclose(img);
           }
           else
          {
            first_jpg=true;
          }

        sprintf(img_name,"%03i.jpg",file_counter);
        img=fopen(img_name,"w");
         if(img==NULL)
         {
            fclose(mem_card);
         }
         file_counter++;
        }
     if(first_jpg)
    {
        fwrite(buffer,BLOCK_SIZE,1,img);
    }
    }
    fclose(mem_card);
    if(first_jpg) fclose(img);
    return 0;
}