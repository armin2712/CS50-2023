#include <cs50.h>
#include <string.h>
#include <stdio.h>

typedef struct
{
    string name;
    int votes;
}
candidate;
candidate get_candidate(string prompt);

int main(void)
{
    candidate candidates_array[3];
    for(int i=0; i < 3; i++)
    {
    candidates_array[i] = get_candidate("Enter a candidate: ");
    printf("%s : %i \n", candidates_array[i].name,candidates_array[i].votes);

    }


}

candidate get_candidate(string prompt)
{
    printf("%s\n",prompt);


candidate c;
c.name=get_string("Enter name of candidate: ");
c.votes=get_int("Enter the votes of the candidate: ");
return c;


}