#include <stdio.h>
#include <cstring>
struct player
{
    int incline, time, seat, serial;
};

int fn(int x, int y, int play);
int abs(int x);
int min(int x, int y);
void merge(int start, int end);
void merge_sort(int start, int last);
void merge2(int start, int end);
void merge_sort2(int start, int last);
void trace(int x, int y, int play);

player array[20009];
player help[20009];
const int inf = 0x3f3f3f3f;
int n;
int dp[6][6][10009];

int main()
{
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d", &n);

        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &array[i].time, &array[i].incline);
            array[i].serial = i;
        }


        merge_sort(0, n - 1);
        // for(int i=0; i<n; i++)
        //     printf("%d\n",array[i].time);

        memset(dp, -1, sizeof(dp));
        printf("%d\n", fn(1, 1, 0));
        trace(1, 1, 0);
        merge_sort2(0, n - 1);

        for(int i = 0; i < n; i++)
        {
            printf("%d", array[i].seat);

            printf("\n");
        }

    }
    return 0;
}

int fn(int x, int y, int play)
{
    int &ret = dp[x][y][play];
    if(ret != -1)
        return ret;

    if(play == n)
    {
        ret = 0;
        int new_x = x * 10;
        int new_y = y * 10;
        return ret = abs(10 - x * 10) + abs(10 - y * 10);
    }


    ret = inf;
    int temp;

    if(play < n - 1 && array[play].time == array[play + 1].time)
    {
        temp = abs(x * 10 - array[play + 1].incline) + abs(y * 10 - array[play].incline) + 30;
        ret = min(ret, fn(array[play + 1].incline / 10, array[play].incline / 10, play + 2) + temp);

        temp = abs(x * 10 - array[play].incline) + abs(y * 10 - array[play + 1].incline) + 30;
        ret = min(ret, fn(array[play].incline / 10, array[play + 1].incline / 10, play + 2) + temp);
    }
    else
    {
        temp = abs(y * 10 - array[play].incline) + 15;
        ret = min(ret, fn(x, array[play].incline / 10, play + 1) + temp);

        temp = abs(x * 10 - array[play].incline) + 15;
        ret = min(ret, fn(array[play].incline / 10, y, play + 1) + temp);

    }
    return ret;

}

void trace(int x, int y, int play)
{
    if(play == n)
        return ;
    //printf("state %d\n",play);
    int temp;
    int choice1, choice2;

    if(play < n - 1 && array[play].time == array[play + 1].time)
    {
        //  printf("i not here %d\n",play);
        temp = abs(x * 10 - array[play].incline) + abs(y * 10 - array[play + 1].incline) + 30;
        choice1 = dp[array[play].incline / 10][array[play + 1].incline / 10][play + 2] + temp;

        temp = abs(x * 10 - array[play + 1].incline) + abs(y * 10 - array[play].incline) + 30;
        choice2 = dp[array[play + 1].incline / 10][array[play].incline / 10][play + 2] + temp;

        if(choice1 <= choice2)
        {
            array[play].seat = 1;
            array[play + 1].seat = 2;
            trace(array[play].incline / 10, array[play + 1].incline / 10, play + 2);

        }
        else
        {


            array[play].seat = 2;
            array[play + 1].seat = 1;
            trace(array[play + 1].incline / 10, array[play].incline / 10, play + 2);
        }
    }
    else
    {
        //  printf("i am here %d\n",play);
        temp = abs(x * 10 - array[play].incline) + 15;
        choice1 = dp[array[play].incline / 10][y][play + 1] + temp;

        temp = abs(y * 10 - array[play].incline) + 15;
        choice2 = dp[x][array[play].incline / 10][play + 1] + temp;

        if(choice1 <= choice2)
        {
            array[play].seat = 1;
            trace(array[play].incline / 10, y, play + 1);
        }
        else
        {
            array[play].seat = 2;
            trace(x, array[play].incline / 10, play + 1);
        }
    }
}

int abs(int x)
{
    if(x >= 0)
        return x;
    else
        return -1 * x;
}

int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}

void merge_sort(int start, int last)
{
    if(last <= start)
        return;

    int middle = (last - start) / 2;
    middle = start + middle;
    merge_sort(start, middle);
    merge_sort(middle + 1, last);
    merge(start, last);
    return;
}

void merge(int start, int end)
{
    int middle = (end - start) / 2;
    middle = middle + start;
    int p1 = start;
    int p2 = middle + 1;
    int main_p = start;

    for(int i = start; i <= middle; i++)
        help[i] = array[i];

    while(main_p <= end)
    {
        if(p1 > middle)
        {
            array[main_p] = array[p2];
            p2++;
            main_p++;
            continue;
        }

        if(p2 > end)
        {
            array[main_p] = help[p1];
            p1++;
            main_p++;
            continue;
        }

        if(help[p1].time < array[p2].time)
        {
            array[main_p] = help[p1];
            p1++;
        }
        else
        {
            array[main_p] = array[p2];
            p2++;
        }
        main_p++;
    }
    return ;
}



void merge_sort2(int start, int last)
{
    if(last <= start)
        return;

    int middle = (last - start) / 2;
    middle = start + middle;
    merge_sort2(start, middle);
    merge_sort2(middle + 1, last);
    merge2(start, last);
    return;
}

void merge2(int start, int end)
{
    int middle = (end - start) / 2;
    middle = middle + start;
    int p1 = start;
    int p2 = middle + 1;
    int main_p = start;

    for(int i = start; i <= middle; i++)
        help[i] = array[i];

    while(main_p <= end)
    {
        if(p1 > middle)
        {
            array[main_p] = array[p2];
            p2++;
            main_p++;
            continue;
        }

        if(p2 > end)
        {
            array[main_p] = help[p1];
            p1++;
            main_p++;
            continue;
        }

        if(help[p1].serial < array[p2].serial)
        {
            array[main_p] = help[p1];
            p1++;
        }
        else
        {
            array[main_p] = array[p2];
            p2++;
        }
        main_p++;
    }
    return ;
}
