#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

struct player
{
    char name[100];
    int defence;
    int attack;
};

void bsort();
void fn();

struct player argen[10];

int team[5];
int team2[5];
int max_attack;
int max_defence;

int counter1, counter2, counter3, counter4, counter5;
int player1, player2, player3, player4, player5;

int main()
{
    int max_cases;
    int cases, counter, flag, taken;
    scanf("%d", &max_cases);
    char in;
    int n;

    for(cases = 0; cases < max_cases; cases++)
    {
        for(counter = 0; counter < 10; counter++)
        {
            scanf("%s", argen[counter].name);
            scanf("%d %d", &argen[counter].attack, &argen[counter].defence);
        }

        max_attack = 0;
        max_defence = 0;
        bsort();

        for(counter1 = 0; counter1 < 10; counter1++)
        {
            player1 = counter1;
            for(counter2 = 0; counter2 < 10; counter2++)
            {
                if(counter2 != player1)
                {
                    player2 = counter2;
                    for(counter3 = 0; counter3 < 10; counter3++)
                    {
                        if(counter3 != player1 && counter3 != player2)
                        {
                            player3 = counter3;
                            for(counter4 = 0; counter4 < 10; counter4++)
                            {
                                if(counter4 != player1 && counter4 != player2 && counter4 != player3)
                                {
                                    player4 = counter4;
                                    for(counter5 = 0; counter5 < 10; counter5++)
                                    {
                                        if(counter5 != player1 && counter5 != player2 && counter5 != player3  && counter5 != player4)
                                        {
                                            player5 = counter5;
                                            fn();
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        taken = 0;
        for(counter = 0; counter < 10; counter++)
        {
            flag = 0;
            for(counter2 = 0; counter2 < 5; counter2++)
            {
                if(counter == team[counter2])
                    flag++;
            }

            if(flag == 0)
            {
                team2[taken] = counter;
                taken++;
            }
        }

        printf("Case %d:\n", cases + 1);
        printf("(");

        for(counter = 0; counter < 5; counter++)
        {
            printf("%s", argen[team[counter]].name);
            if(counter < 4)
                printf(", ");

        }
        printf(")\n");

        printf("(");

        for(counter = 0; counter < 5; counter++)
        {
            printf("%s", argen[team2[counter]].name);
            if(counter < 4)
                printf(", ");
        }

        printf(")\n");
    }

    return 0;
}

void bsort()
{
    struct player swap;
    int counter, counterx;
    for(counter = 0; counter < 9; counter++)
        for(counterx = 0; counterx < 9; counterx++)
            if(strcmp(argen[counterx].name, argen[counterx + 1].name) > 0)
            {
                swap = argen[counterx];
                argen[counterx] = argen[counterx + 1];
                argen[counterx + 1] = swap;
            }
}

void fn()
{
    int att = 0;
    int def = 0;

    att = argen[counter1].attack + argen[counter2].attack + argen[counter3].attack + argen[counter4].attack + argen[counter5].attack;
    def = argen[counter1].defence + argen[counter2].defence + argen[counter3].defence + argen[counter4].defence + argen[counter5].defence;

    if(att > max_attack)
    {
        team[0] = counter1;
        team[1] = counter2;
        team[2] = counter3;
        team[3] = counter4;
        team[4] = counter5;
        max_defence = def;
        max_attack = att;
        return;
    }

    if(att == max_attack)
    {
        if(def < max_defence)
        {
            team[0] = counter1;
            team[1] = counter2;
            team[2] = counter3;
            team[3] = counter4;
            team[4] = counter5;
            max_defence = def;
            return;
        }
    }

}


