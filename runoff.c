#include <stdio.h>
#include <cs50.h>
#include <string.h>

//defining max candidates and voters
#define MAX_CANDIDATES 9
#define MAX_VOTERS 100

//creating a 2d array for preference 
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// giving candidates name, vote and emliminated 
typedef struct 
{
    string name;
    int votes;
    bool eliminated; 
}
candidate;

// arrat of candidates 
candidate candidates[MAX_CANDIDATES];

// count of voters and candidates 
int voter_count;
int candidate_count;


// calling function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int lowest);
void eliminate(int lowset);

int main(int argc, string argv[])
{
    // makes sure correct usage 
    if (argc < 2)
    {
        printf("Usage: ./runoff [candidate .... ");
        return 1;
    }
    
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum amount of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }
    // promt user for number of voters
    voter_count = get_int("Number of Voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum amount of voters is %i\n", MAX_VOTERS);
        return 3;
    }
    
    // continue to ask for votes
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);
            
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }
        printf("\n");
    }
    
    // continue to runoff untill winner exists 
    while (true)
    {
        // keeps tab of votes
        tabulate();
        
        // chech for winner
        bool won = print_winner();
        if (won)
        {
            break;
        }
        // eliminate candidate in last place
        int min = find_min();
        bool tie = is_tie(min);
        
        if (tie)
        {
            for(int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }
        
        // eliminate candidate with least votes
         eliminate(min);
         
         for (int i = 0; i < candidate_count; i++)
         {
             candidates[i].votes = 0;
         }
    }
    return 0;
}

bool vote(int voter, int rank, string name)
{
    bool exist = false;
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i;
            exist = true;
            break;
        }
    }
    return exist; 
}

void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (candidates[preferences[i][j]].eliminated == false)
            {
                candidates[preferences[i][j]].votes++;
                break;
            }
        }
    }
    return;
}


bool print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        string highest = candidates[i].name;
        if (candidates[i].votes > voter_count / 2)
        {
            printf("%s\n", highest);
            return true;
        }
    }
    return false;
}

int find_min(void)
{
    int lowest = voter_count;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes < lowest)
        {
            lowest = candidates[i].votes;
        }
    }
    return lowest;
}

bool is_tie(int lowest)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes != lowest)
        {
            return false;
        }
    }
    return true;
}

void eliminate(int lowest)
{
    for(int i = 0; i < voter_count; i++)
    {
        if (candidates[i].votes == lowest)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
