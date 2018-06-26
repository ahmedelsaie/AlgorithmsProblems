#include <stdio.h>
#include <cstring>

int fn(int mask, int accum, int card);
void pre_process();
bool short_straight(int i);
bool long_straight(int i);
bool full_house(int i);
bool same_type(int i, int target);
int collect(int i);
int first_6(int i, int target);
int setbit(int mask, int bit, int value);
int getbit(int mask, int bit);
int max(int x, int y);
void trace(int mask, int accum, int card);
void bsort(int array[], int m);

int dp[(1 << 13) + 1][65];
int array[14][5];
int yield[13][13];
const int inf = 99999999;

int main()
{
    int ans;
    while(scanf("%d %d %d %d %d", &array[0][0], &array[0][1], &array[0][2], &array[0][3], &array[0][4]) != EOF)
    {
        for(int i = 1; i < 13; i++)
            for(int j = 0; j < 5; j++)
                scanf("%d", &array[i][j]);

        memset(dp, -1, sizeof(dp));
        pre_process();
        ans = fn(0, 0, 0);
        trace(0, 0, 0);
        printf(" %d\n", ans);
    }
    return 0;
}

int fn(int mask, int accum, int card)
{
    int &ret = dp[mask][accum];
    if(ret != -1)
        return ret;

    if(card == 13)
    {
        if(accum >= 63)
            return 35;
        return 0;
    }

    ret = -1 * inf;
    int new_mask;

    for(int round = 0; round < 13; round++)
    {
        if(!getbit(mask, round))
        {
            new_mask = setbit(mask, round, 1);

            if(card < 6)
            {
                int new_value = accum + yield[round][card];

                if(new_value >= 63)
                    new_value = 63;
                ret = max(ret, fn(new_mask, new_value, card + 1) + yield[round][card]);
            }
            else
                ret = max(ret, fn(new_mask, accum, card + 1) + yield[round][card]);
        }
    }

    return ret;
}

void trace(int mask, int accum, int card)
{
    if(card == 13)
    {
        if(accum >= 63)
            printf(" %d", 35);
        else
            printf(" 0");

        return ;
    }

    int new_mask;
    int new_value;
    int sent_value;
    int sent_mask;

    int sent_value2;

    int ret = -1 * inf;

    for(int round = 0; round < 13; round++)
        if(!getbit(mask, round))
        {
            new_mask = setbit(mask, round, 1);

            if(card < 6)
            {
                new_value = accum + yield[round][card];

                if(new_value >= 63)
                    new_value = 63;
                ret = max(ret, dp[new_mask][new_value] + yield[round][card]);

                if(ret == dp[new_mask][new_value] + yield[round][card])
                {
                    sent_value = yield[round][card];
                    sent_mask = new_mask;
                    sent_value2 = new_value;
                }
            }
            else
            {
                new_value = accum;
                ret = max(ret, dp[new_mask][new_value] + yield[round][card]);
                if(ret == dp[new_mask][new_value] + yield[round][card])
                {
                    sent_value = yield[round][card];
                    sent_mask = new_mask;
                    sent_value2 = new_value;
                }
            }
        }

    if(card > 0)
        printf(" ");

    printf("%d", sent_value);
    trace(sent_mask, sent_value2, card + 1);
}


void pre_process()
{
    int x;
    for(int round = 0; round < 13; round++)
    {
        //printf("round %d\n",round);
        for(int card = 0; card < 13; card++) ///////card
        {
            switch(card)
            {
            case 6:
                x = collect(round);
                break;
            case 7:
                if(same_type(round, 3))
                    x = collect(round);
                else
                    x = 0;
                break;
            case 8:
                if(same_type(round, 4))
                    x = collect(round);
                else
                    x = 0;
                break;
            case 9:
                if(same_type(round, 5))
                    x = 50;
                else
                    x = 0;
                break;

            case 10:
                if(short_straight(round))
                    x = 25;
                else
                    x = 0;
                break;

            case 11:
                if(long_straight(round))
                    x = 35;
                else
                    x = 0;
                break;
            case 12:
                if(full_house(round))
                    x = 40;
                else
                    x = 0;
                break;
            default:
                x = first_6(round, card + 1);
                break;
            }

            yield[round][card] = x;

            //printf("%d  ",x);
        }
        // printf("\n");

    }

    return ;
}

bool short_straight(int i)
{
    int flag = 0;
    int last, left;
    int work[7];

    for(int j = 0; j < 5; j++)
        work[j] = array[i][j];
    bsort(work, 5);

    last = 0;
    for(int j = 0; j < 5; j++)
    {
        if(work[j] == last + 1)
        {
            flag++;
            last = work[j];
        }
        else
            continue;;
    }

    if(flag == 4)
        return true;
    else
        flag = 0;



    last = 1;
    for(int j = 0; j < 5; j++)
    {
        if(work[j] == last + 1)
        {
            flag++;
            last = work[j];
        }
        else
            continue;;
    }

    if(flag == 4)
        return true;
    else
        flag = 0;


    last = 2;
    for(int j = 0; j < 5; j++)
    {
        if(work[j] == last + 1)
        {
            flag++;
            last = work[j];
        }
        else
            continue;;
    }

    if(flag == 4)
        return true;
    else
        return false;

}

bool long_straight(int i)
{
    int flag = 0;
    int last, left;
    int work[7];
    for(int j = 0; j < 5; j++)
        work[j] = array[i][j];
    bsort(work, 5);

    if(work[0] == 1 && work[1] == 2 && work[2] == 3 && work[3] == 4 && work[4] == 5)
        return true;

    if(work[0] == 2 && work[1] == 3 && work[2] == 4 && work[3] == 5 && work[4] == 6)
        return true;
    return false;
}

bool full_house(int i)
{
    bool three = false;
    bool two = false;
    int y;
    int ref[8];
    memset(ref, 0, sizeof(ref));
    for(int j = 0; j < 5; j++)
    {
        y = array[i][j];
        ref[y]++;
    }

    for(int j = 1; j <= 6; j++)
    {
        if(ref[j] == 2)
            two = true;

        if(ref[j] == 3) //
            three = true;
    }

    if(three && two)
        return true;
    return false;
}

bool same_type(int i, int target)
{
    int y;
    int ref[8];
    memset(ref, 0, sizeof(ref));

    for(int j = 0; j < 5; j++)
    {
        y = array[i][j];
        ref[y]++;
        if(ref[y] == target)
            return true;
    }
    return false;
}

int collect(int i)
{
    int ret = 0;
    for(int j = 0; j < 5; j++)
        ret += array[i][j];
    return ret;
}

int first_6(int i, int target)
{
    int ret = 0;
    for(int j = 0; j < 5; j++)
        if(array[i][j] == target)
            ret += target;
    return ret;
}

int setbit(int mask, int bit, int value)
{
    if(value == 1)
        return(mask | (1 << bit));
    else
        return (mask&~(1 << bit));
}

int getbit(int mask, int bit)
{
    mask = (mask >> bit) & 1;
    return (mask == 1);
}

int max(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}

void bsort(int array[], int m)
{
    int swap;
    bool flag;
    for(int i = 0; i < m - 1; i++)
    {
        flag = true;
        for(int j = 0; j < m - 1; j++)
            if(array[j] > array[j + 1])
            {
                swap = array[j];
                array[j] = array[j + 1];
                array[j + 1] = swap;
                flag = false;
            }
        if(flag)
            return;
    }
    return ;
}
