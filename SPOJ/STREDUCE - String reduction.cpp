#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

int fn(int start, int end, int with_me);
int min(int x, int y);
int table();

int dp[309][309][7];
char input[305];
int array[305];

const int inf = 99999999;
int l;

int main()
{
    int ans;
    // freopen("in.txt", "r", stdin);
    scanf("%s", input);
    l = strlen(input);

    for(int i = 0; i < l; i++)
    {
        if(input[i] == 'a' || input[i] == 'A')
            array[i] = 1;
        else
            array[i] = 2;
    }

    //memset(dp, -1, sizeof(dp));
    //ans = fn(0, l + 1, 0);
    // printf("%d\n", ans);
    printf("%d\n", table());

    return 0;
}

int table()
{
    int end;
    for(int start = l; start >= 0; start-- )
        for(int len = 0; len <= l + 1; len++)
        {
            end = start + len;
            if(end > l + 1)
                break;

            for(int with_me = 0; with_me <= 6; with_me++)
            {
                int& ret = dp[start][end][with_me];
                ret = inf;


                ///Base Case
                if(start == l && end == l + 1)
                {
                    if(with_me == 0 || with_me == 1 || with_me == 2)
                        ret = 0;
                    else
                        ret = inf;
                }
                else if(start >= end)
                {
                    if(with_me == 2 || with_me == 1)
                        ret = with_me;
                    else
                        ret = inf;
                }
                else
                {
                    int check;
                    int new_end = end;

                    if(new_end == l + 1)
                        new_end--;

                    ///choices
                    if(start + 1 == end)
                    {
                        if(with_me == 0)
                            ret = min(ret, dp[start + 1] [end] [array[start]] + (end == l + 1));
                        else if(with_me == 1 || with_me == 2)
                        {
                            ret = min(ret, dp[start + 1] [end] [with_me + array[start] + 1 + (with_me == 2)]);
                            if(end == l + 1)
                                ret = min(ret, dp[start + 1] [end] [array[start]] + 1);
                        }
                        else if((with_me == 3 || with_me == 4) && array[start] == 1)
                            ret =  min(ret, dp[start + 1] [end] [with_me - 2]);
                        else if((with_me == 5 || with_me == 6) && array[start] == 2)
                            ret =  min(ret, dp[start + 1] [end] [with_me - 4]);
                    }
                    else
                    {
                        if(with_me == 0)
                        {
                            if(end == l + 1)
                                ret = min(ret, dp[start + 1] [end] [0] + 1);  ///Don't Take anything skip it

                            for(int i = start + 1; i < new_end; i++) ///dedicate
                            {
                                check = dp[start] [i] [0];
                                if(check == 1)
                                    ret = min(ret, dp[i][end][1] + (end == l + 1));
                                else if(check == 2)
                                    ret = min(ret, dp[i][end][2] + (end == l + 1));
                            }
                        }
                        else if(with_me == 1 || with_me == 2)
                        {
                            if(end == l + 1)
                                ret = min(ret, dp[start][end][0]);

                            for(int i = start + 1; i < new_end; i++) ///dedicate
                            {
                                check = dp[start][i][0];
                                if(check == 1)
                                    ret = min(ret, dp[i] [end] [(with_me == 2) + 2 + with_me]);
                                else if(check == 2)
                                    ret = min(ret, dp[i] [end] [(with_me == 2) + 3 + with_me]);
                            }
                        }
                        else if(with_me == 3 || with_me == 4)
                        {
                            if(dp[start][new_end][0] == 1)
                                ret = min(ret, dp[new_end][ end][with_me - 2]);

                            for(int i = start + 1; i < new_end; i++) ///take and proceed
                            {
                                check = dp[start][i][0];
                                if(check == 1)
                                    ret = min(ret, dp[i][end][with_me - 2]);
                            }
                        }
                        else if(with_me == 5 || with_me == 6)
                        {
                            if(dp[start][new_end][0] == 2)
                                ret = min(ret, dp[new_end][end][with_me - 4]);

                            for(int i = start + 1; i < new_end; i++) ///take and proceed
                            {
                                check = dp[start][i][0];
                                if(check == 2)
                                    ret = min(ret, dp[i][end][with_me - 4]);
                            }
                        }
                    }



                }

            }

        }

    return dp[0][l + 1][0];
}


int fn(int start, int end, int with_me)
{
    ///Base Case
    if(start == l && end == l + 1)
    {
        if(with_me == 0 || with_me == 1 || with_me == 2)
            return 0;
        return inf;

    }

    if(start >= end)
    {
        /*
           with_me
           0-->nothing     3-->aa       5-->ba
           1-->a           4-->ab       6-->bb
           2-->b       */
        if(with_me == 2 || with_me == 1)
            return with_me;

        return inf;
    }

    int& ret = dp[start][end][with_me];
    if(ret != -1)
        return ret;

    ret = inf;
    int check;
    int new_end = end;

    if(new_end == l + 1)
        new_end--;

    ///choices
    if(start + 1 == end)
    {
        /*
           with_me
           0-->nothing     3-->aa       5-->ba
           1-->a           4-->ab       6-->bb
           2-->b       */
        if(with_me == 0)
            ret = min(ret, fn(start + 1, end, array[start]) + (end == l + 1));

        if(with_me == 1 || with_me == 2)
        {
            ret = min(ret, fn(start + 1, end, with_me + array[start] + 1 + (with_me == 2)));
            if(end == l + 1)
                ret = min(ret, fn(start + 1, end, array[start]) + 1);
        }

        if((with_me == 3 || with_me == 4) && array[start] == 1)
            ret =  min(ret, fn(start + 1, end, with_me - 2));

        if((with_me == 5 || with_me == 6) && array[start] == 2)
            ret =  min(ret, fn(start + 1, end, with_me - 4));
    }
    else
    {
        if(with_me == 0)
        {
            if(end == l + 1)
                ret = min(ret, fn(start + 1,  end, 0) + 1);  ///Don't Take anything skip it

            for(int i = start + 1; i < new_end; i++) ///dedicate
            {
                check = fn(start, i, 0);
                if(check == 1)
                    ret = min(ret, fn(i, end, 1) + (end == l + 1));

                if(check == 2)
                    ret = min(ret, fn(i, end, 2) + (end == l + 1));
            }
        }

        if(with_me == 1 || with_me == 2)
        {
            /*
            with_me
            0-->nothing     3-->aa       5-->ba
            1-->a           4-->ab       6-->bb
            2-->b       */
            if(end == l + 1)
                ret = min(ret, fn(start, end, 0));

            for(int i = start + 1; i < new_end; i++) ///dedicate
            {
                check = fn(start, i, 0);
                if(check == 1)
                    ret = min(ret, fn(i, end, (with_me == 2) + 2 + with_me));

                if(check == 2)
                    ret = min(ret, fn(i, end, (with_me == 2) + 3 + with_me));
            }
        }

        if(with_me == 3 || with_me == 4)
        {
            /*
            with_me
            0-->nothing     3-->aa       5-->ba
            1-->a           4-->ab       6-->bb
            2-->b       */
            if(fn(start, new_end, 0) == 1)
                ret = min(ret, fn(new_end, end, with_me - 2));

            for(int i = start + 1; i < new_end; i++) ///take and proceed
            {
                check = fn(start, i, 0);
                if(check == 1)
                    ret = min(ret, fn(i, end, with_me - 2));
            }

        }

        if(with_me == 5 || with_me == 6)
        {
            /*
            with_me
            0-->nothing     3-->aa       5-->ba
            1-->a           4-->ab       6-->bb
            2-->b       */
            if(fn(start, new_end, 0) == 2)
                ret = min(ret, fn(new_end, end, with_me - 4));

            for(int i = start + 1; i < new_end; i++) ///take and proceed
            {
                check = fn(start, i, 0);
                if(check == 2)
                    ret = min(ret, fn(i, end, with_me - 4));
            }
        }
    }

    return ret;
}

int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}

