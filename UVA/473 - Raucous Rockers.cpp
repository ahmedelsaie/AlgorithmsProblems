#include <stdio.h>

void reset();
int fn(int cd, int start, int last);
int max(int choice1, int choice2, int choice3, int choice4);

int songs[805];
int dp [805][105][105];
int no_songs;
int no_cds;
int cd_duration;

int main()
{
    int cases;
    scanf("%d", &cases);
    for(int j = 0; j < cases; j++)
    {
        scanf("%d %d %d ", &no_songs, &cd_duration, &no_cds);
        for(int i = 0; i < no_songs; i++)
            scanf("%d,", &songs[i]);
        reset();

        printf("%d\n", fn(0, 0, cd_duration));
        if(j < cases - 1)
            printf("\n");
    }

    return 0;
}

int fn(int curr_song, int current_d, int left_d)
{
    int &ret = dp[curr_song][current_d][left_d];
    if(ret != -1)
        return ret;

    if(current_d >= no_cds)
        return 0;

    if(curr_song >= no_songs || left_d < 0)
        return 0;

    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int choice4 = 0;

    choice1 = fn(curr_song + 1, current_d, left_d);

    if(left_d - songs[curr_song] >= 0)
    {
        choice2 = fn(curr_song + 1, current_d, left_d - songs[curr_song]) + 1;
        choice3 = fn(curr_song + 1, current_d + 1, cd_duration) + 1;
    }

    choice4 = fn(curr_song, current_d + 1, cd_duration);
    return ret = max(choice1, choice2, choice3, choice4);
}

int max(int choice1, int choice2, int choice3, int choice4)
{
    int ret = 0;
    if(choice1 > ret)
        ret = choice1;

    if(choice2 > ret)
        ret = choice2;

    if(choice3 > ret)
        ret = choice3;

    if(choice4 > ret)
        ret = choice4;
    return ret;
}

void reset()
{
    for(int i = 0; i < 801; i++)
        for(int j = 0; j < 105; j++)
            for(int k = 0; k < 105; k++)
                dp[i][j][k] = -1;
}
