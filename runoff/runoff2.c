#include<stdio.h>
#include<cs50.h>
#include<string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

int preferences[MAX_VOTERS][MAX_CANDIDATES];

typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

candidate candidates[MAX_CANDIDATES];

int voters_count;
int candidates_count;


bool vote(int voter, int rank, string name);
int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return  1;
    }
    candidates_count = argc - 1;
    if (candidates_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidates_count; i++)
    {
        candidates[i].name = argv[i+1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }
    voters_count = gent_int("number of voters is: ");
    if (voters_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }
    for (int i = 0; i < voters_count; i++)
    {
        for (int j = 0; j < candidates_count; j++)
        {
            string name = get_string("rank %i is: ", j + 1);
            if(!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }
        printf("\n");

    }



}
bool vote(int voter, int rank, string name)
{
    for( int i = 0; i < candidates_count; i++)
    {
        if(strcmp(candidates[i].name, name)==0)
        {
            preferences[i][j]=i;
            return true;

        }
    }
}