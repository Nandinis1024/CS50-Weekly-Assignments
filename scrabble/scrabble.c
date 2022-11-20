#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    if(score1>score2){
        printf("player 1 wins!\n");

    }
    else{
        printf("player 2 wins!\n");
    }
    // TODO: Print the winner
}

int compute_score(string word)
{   int score,t=0;
    int length=strlen(word);
    for(int i=0;i<length;i++){
        char c=word[i];
        if(isupper(c)){
        t=POINTS[c-65];
        }
        else if(islower(c)){
         t=POINTS[c-97];
        }
        else{
            t=0;
        }

        score=score+t;
    }
    return score;
    // TODO: Compute and return score for string
}
