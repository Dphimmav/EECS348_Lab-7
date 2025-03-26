#include "football.h"
#include <stdio.h>
int count_combinations(int points)
{
    int count = 0;
    for (int td2pt = 0;points>=(td2pt * 8); td2pt++)
    {
        for (int tdfg = 0; points>= (tdfg * 7); tdfg++)
        {
            for (int td = 0;points>= (td * 6); td++)
            {
                for (int fg = 0;points>= (fg * 3); fg++)
                {
                    int safety_points = points - (td2pt * 8 + tdfg * 7 + td * 6 + fg * 3);
                    if (safety_points >= 0)
                    {
                        if(safety_points % 2 == 0)
                        {
                            int safety = safety_points / 2;
                            if (safety >= 0)
                            {
                                count++;
                            }
                        }
                    }
                }
            }
        }
    }
    return count;
}

void print_combinations(int points)
{
    for (int td2pt = 0; points>= (td2pt * 8); td2pt++)
    {
        for (int tdfg = 0;points>= (tdfg * 7); tdfg++)
        {
            for (int td = 0;points>= (td * 6); td++)
            {
                for (int fg = 0;points>=( fg * 3 ); fg++)
                {
                    int safety_points = points - (td2pt * 8 + tdfg * 7 + td * 6 + fg * 3);
                    if (safety_points >= 0)
                    {
                        if(safety_points % 2 == 0)
                        {
                            int safety = safety_points / 2;
                            if (safety >= 0)
                            {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2pt, tdfg, td, fg, safety);
                            }
                        }
                    }
                }
            }
        }
    }
}
