#include "football.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    int score;
    printf("Enter 0 or 1 to STOP\n");
    while(1)
    {
        printf("Enter the NFL score: ");
        if(scanf("%d", &score) != 1)
        {
            printf("Please enter a valid integer score.\n");
        }
        else
        {
            if (score == 1 || score == 0)
            {
                printf("Exiting program.\n");
                break;
            }
            printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);
            print_combinations(score);
        }
    }

    return 0;
}