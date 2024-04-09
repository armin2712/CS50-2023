#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);



int main(void)
{

    string message = get_string("Message: ");
    int binary[BITS_IN_BYTE]={} ;

    for(int i = 0, n = strlen(message); i < n; i++)
    {
        // loop over string, pr. "HI" => 'H' kod i=0, 'I' kod i=1

        int sign = message[i]; // primjer => 'H' prelazi u ASCII vrijednost 72

        // int binary[BITS_IN_BYTE]={} ;//Na kraju ce biti nesto tipa 0101010

        int reminder;

        for(int j=BITS_IN_BYTE-1; 0 < j ;j--)
        {
            reminder = sign % 2;
            binary[j]=reminder;
            sign = sign / 2;
        }
        for (int k = 0, x = BITS_IN_BYTE ; k < x; k++)
          {
             print_bulb(binary[k]);
          }
          printf("\n");
        }

}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

