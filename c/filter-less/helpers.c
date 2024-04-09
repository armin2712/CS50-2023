#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i =0;i<height;i++)
    {
        for(int j=0; j<width;j++)
        {
           int aveg=(image[i][j].rgbtRed+image[i][j].rgbtGreen+image[i][j].rgbtBlue)/3;
           image[i][j].rgbtRed=aveg;
           image[i][j].rgbtGreen=aveg;
           image[i][j].rgbtBlue=aveg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
      for(int i =0;i<height;i++)
    {
        for(int j=0; j<width;j++)
        {
            int red=(int)(image[i][j].rgbtRed*0.393)+(int)(image[i][j].rgbtGreen*0.769)+(int)(image[i][j].rgbtBlue*0.189);
            int green=(int)(image[i][j].rgbtRed*0.349)+(int)(image[i][j].rgbtGreen*0.686)+(int)(image[i][j].rgbtBlue*0.168);
            int blue=(int)(image[i][j].rgbtRed*0.272)+(int)(image[i][j].rgbtGreen*0.534)+(int)(image[i][j].rgbtBlue*0.131);

            if(red > 255) image[i][j].rgbtRed=255;
            else image[i][j].rgbtRed=red;
            if(green > 255 ) image[i][j].rgbtGreen=255;
            else image[i][j].rgbtGreen=green;
            if(blue > 255) image[i][j].rgbtBlue=255;
            else image[i][j].rgbtBlue=blue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE buffer;
       for(int i =0;i < height;i++)
    {
        for(int j=0; j< (int)(width/2);j++)
        {
            buffer=image[i][j];
            image[i][j]=image[i][width-j];
            image[i][width-j]=buffer;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int avg=0;
    int red=0;
    int green=0;
    int blue=0;

       for(int i=0;i<height;i++)
    {

        for(int j=0; j < width ;j++)
        {
            for(int x=i-1; x < i+2 ;x++)
            {
                for(int y=j-1; y < j+2; y++)
                {
                    if(x>=0 && x<=height && y>=0 && y<=width)
                    {
                    red+=image[x][y].rgbtRed;
                    green+=image[x][y].rgbtGreen;
                    blue+=image[x][y].rgbtBlue;
                    avg+=1;
                    }
                }
            }
            image[i][j].rgbtRed=red/avg;
            image[i][j].rgbtGreen=green/avg;
            image[i][j].rgbtBlue=blue/avg;
            avg=0;
            red=0;
            green=0;
            blue=0;
        }
    }
    return;
}

void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int redX;
    int greenX;
    int blueX;
    int redY;
    int greenY;
    int blueY;

    for(int i =0; i < height;i++)
    {
        for(int j=0;j<width;j++)
        {
           redX=0;
           greenX=0;
           blueX=0;
           redY=0;
           greenY=0;
           blueY=0;

            for(int x=i-1;x<i+2;x++)
           {
              for(int y=j-1;y<j+2;y++)
            {

                if(x>=0 && x <= height && y >= 0 && y <= width)
                {

                if(x==i)
                {
                    redX+=((y-j)*2)*(image[x][y].rgbtRed);
                 // printf("%i\n",((y-j)*2)*(image[x][y].rgbtRed));
                   // printf("%i\n",image[0][0].rgbtRed);
                    greenX+=((y-j)*2)*(image[x][y].rgbtGreen);
                    blueX+=((y-j)*2)*(image[x][y].rgbtBlue);
                     redY+=((y-j)*2)*(image[y][i].rgbtRed);
                    greenY+=((y-j)*2)*(image[y][i].rgbtGreen);
                    blueY+=((y-j)*2)*(image[y][i].rgbtBlue);
                }

                 else if(x==i-1 && y==j-1)
                    {
                    redY+=(y-j)*(image[i][i].rgbtRed);
                    greenY+=(y-j)*(image[i][i].rgbtGreen);
                    blueY+=(y-j)*(image[i][i].rgbtBlue);
                    }
                    else if(x==i-1 && !(y=j-1))
                    {
                    redY+=(y-j)*(image[y-i+1][i+1].rgbtRed);
                    greenY+=(y-j)*(image[y-i+1][i+1].rgbtGreen);
                    blueY+=(y-j)*(image[y-i+1][i+1].rgbtBlue);
                    }
                   else
                   {
                    redX+=(y-j)*(image[x][y].rgbtRed);
                    greenX+=(y-j)*(image[x][y].rgbtGreen);
                    blueX+=(y-j)*(image[x][y].rgbtBlue);
                    redY+=(y-j)*(image[j][i-1].rgbtRed);
                    greenY+=(y-j)*(image[j][i-1].rgbtGreen);
                    blueY+=(y-j)*(image[j][i-1].rgbtBlue);
                    }
                   }

              }


            }

                image[i][j].rgbtRed   = (int)(sqrt(redX * redX + redY * redY));
                if(image[i][j].rgbtRed > 255) image[i][j].rgbtRed = 255;

                image[i][j].rgbtGreen =(int)(sqrt(greenX * greenX + greenY * greenY));
                if(image[i][j].rgbtGreen > 255) image[i][j].rgbtGreen = 255;

               // printf("%i\n",image[i][j].rgbtGreen);
                image[i][j].rgbtBlue  = (int)(blueX * blueX + blueY * blueY);
                if(image[i][j].rgbtBlue > 255)image[i][j].rgbtBlue = 255;
        }

    }
    return;
}
