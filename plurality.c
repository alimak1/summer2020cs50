#include <cs50.h>
#include <stdio.h>
#include <string.h>

// MAX represents the maximum number of candidates an election can have
#define MAX 9 

// defining the name and vote count of the candidates
typedef struct
{
    string name;
    int votes;
}
candidate;

candidate candidates[MAX]; // creating an array of candidates

int candidate_count; //count of candidates

// calling the functions 
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    //Chcecking proper usage a
    if (argc < 2)
    {
        printf("Usage: pluality [candidate 1, candidate 2, ... ]\n");
        return 1;
    }
    
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }
    
    int voter_count = get_int("Number of Voters: ");
    
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");
        
        if (!vote(name))
        {
            printf("invlid vote.\n");
        }
    }
    print_winner();
}

bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if(strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

void print_winner(void)
{
    int maxvotes = 0;
    
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > maxvotes)
        {
            maxvotes = candidates[i].votes;
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == maxvotes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}
