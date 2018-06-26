#include <bits/stdc++.h>
using namespace std;
#define MAX 3005
#define ll long long

ll inf = 4611686018427387904, max_val = 99999999999;

struct node
{
    ll start, end, val, incr, best;
};

ll fn();
int first_loop(int i, int prev_with);
int sec_loop(int i, int curr_with);

node work[2][MAX * 1000];

ll arr[MAX], n;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);


    printf("%lld\n", fn());
    return 0;
}

void print(int prev_with, int f)
{
    return;
    for(int j = 0; j < prev_with; j++)
        printf("(%d %d)   ", work[!f][j].start, work[!f][j].end);

    printf("\n");

    for(int j = 0; j < prev_with; j++)
        printf("[%d %d]   ", work[!f][j].val, work[!f][j].incr);

    printf("\n\n");
}

ll fn()
{
    ///adjusting boundaries
    work[0][0].start = -max_val, work[0][0].end = arr[0];
    work[0][0].val = (max_val + arr[0]), work[0][0].incr = -1;

    work[0][1].start = arr[0] + 1, work[0][1].end = max_val;
    work[0][1].val = 1, work[0][1].incr = 1;

    int f = 1, prev_with = 2;

    print(prev_with, 1);

    //printf("====================================================================\n");

    for(int i = 1; i < n; i++)
    {
        int curr_with = first_loop(i, prev_with);

        print(curr_with, 0);

        prev_with = sec_loop(i, curr_with);

//printf(" ===== %d\n",i);
        print(prev_with, 1);

        //printf("====================================================================\n");
    }

    ll ret = inf;

    for(int i = 0; i < prev_with; i++)
    {
        if(work[!f][i].incr >= 0)
            ret = min(ret, work[!f][i].val);// printf("jdnjdnjdndjk %d\n", work[!f][i].val);
        else
            ret = min(ret, work[!f][i].val + work[!f][i].incr * (work[!f][i].end - work[!f][i].start));
    }

    return ret;
}


int sec_loop(int i, int curr_with)
{
    int new_curr_with = 0, f = 1;
    ll best = inf;

    for(int j = 0; j < curr_with; j++)
    {
        work[f][j].best = best;
        ll val_incr = (work[f][j].start <= arr[i] ? -1 : 1);
        ll bef_incr = work[f][j].incr - val_incr;
        ll bef_val = work[f][j].val - abs(arr[i] - work[f][j].start);

        if(bef_val >= work[f][j].best && bef_incr >= 0) ///exammple 5 +1 best=3
        {
            work[!f][new_curr_with] = work[f][j];
            work[!f][new_curr_with].val = work[!f][new_curr_with].best + abs(arr[i] - work[f][j].start);
            work[!f][new_curr_with++].incr = val_incr;
        }
        else if(bef_val >= work[f][j].best && bef_incr < 0)  /// example 8  best 6   -2
        {
            if(bef_val + bef_incr * (work[f][j].end - work[f][j].start) >= work[f][j].best)
            {
                work[!f][new_curr_with] = work[f][j];
                work[!f][new_curr_with].val = work[!f][new_curr_with].best + abs(arr[i] - work[f][j].start);
                work[!f][new_curr_with++].incr = val_incr;
            }
            else  /// example 8  6   -2
            {
                ll x = (bef_val - work[f][j].best) / abs(bef_incr);
                x += work[f][j].start;

                ///till x
                work[!f][new_curr_with] = work[f][j];
                work[!f][new_curr_with].val = work[!f][new_curr_with].best + abs(arr[i] - work[f][j].start);
                work[!f][new_curr_with++].incr = val_incr;
                work[!f][new_curr_with++].end = x;

                work[!f][new_curr_with] = work[f][j];
                work[!f][new_curr_with++].start = x + 1;
                work[!f][new_curr_with].val = bef_val + bef_incr * (work[f][j].end - (x + 1)) + abs(arr[i] - (x + 1));
                work[!f][new_curr_with++].incr = val_incr + bef_incr;
            }
        }
        else if(bef_val <= work[f][j].best && bef_incr >= 0)
        {
            if(bef_incr == 0 || (bef_incr > 0 && bef_val + bef_incr * (work[f][j].end - work[f][j].start) <= work[f][j].best))
                work[!f][new_curr_with++] = work[f][j];
            else
            {
                ll x = (work[f][j].best - bef_val) / abs(bef_incr);
                x += work[f][j].start;

                ///till x
                work[!f][new_curr_with] = work[f][j];
                work[!f][new_curr_with].val = bef_val + abs(arr[i] - work[f][j].start);
                work[!f][new_curr_with++].incr = val_incr + bef_incr;
                work[!f][new_curr_with++].end = x;

                ///from x
                work[!f][new_curr_with] = work[f][j];
                work[!f][new_curr_with++].start = x + 1;
                work[!f][new_curr_with].val = work[f][j].best + abs(arr[i] - (x + 1));
                work[!f][new_curr_with++].incr = bef_incr;
            }
        }
        else
            work[!f][new_curr_with++] = work[f][j];

        best = min(best, bef_val + bef_incr * (work[f][j].end - work[f][j].start));
        best = min(best, bef_val);
    }

    return new_curr_with;
}

int first_loop(int i, int prev_with)
{
    int curr_with = 0, min_with = inf, f = 1;

    for(int j = 0; j < prev_with; j++)
    {
        if(!(arr[i] > work[!f][j].start && arr[i] <= work[!f][j].end))
        {
            work[f][curr_with].start = work[!f][j].start + 1;
            work[f][curr_with].end = work[!f][j].end + 1;

            ll cof = (work[!f][j].start < arr[i] ? -1 : 1);

            work[f][curr_with].val = work[!f][j].val + abs(arr[i] - (work[!f][j].start + 1));
            work[f][curr_with].incr = cof + work[!f][j].incr;

            work[f][curr_with].best = min((ll)min_with, work[!f][j].val) + abs(arr[i] - (work[!f][j].start + 1));

            curr_with++;
            min_with = min((ll)min_with, work[!f][j].val);// + abs(arr[i] - (work[!f][j].start + 1)));

            min_with = min((ll)min_with, work[!f][j].val + work[!f][j].incr * (abs(work[!f][j].end - work[!f][j].start)));
        }
        else
        {
            ///the start till me

            work[f][curr_with].start = work[!f][j].start + 1;
            work[f][curr_with].end = arr[i];

            work[f][curr_with].val = work[!f][j].val + abs(arr[i] - work[!f][j].start - 1);
            int tmp = abs(arr[i] - work[!f][j].start - 1);
            work[f][curr_with].incr = -1 + work[!f][j].incr;

            work[f][curr_with++].best = min((ll)min_with, work[!f][j].val) + tmp;
            //  printf("jnj %d %d\n", j, work[!f][j].val);
            min_with = min((ll)min_with, work[!f][j].val);

            ///after_me
            //   min_with = min(min_with, work[!f][j].val + work[!f][j].incr * (abs(arr[i] - work[!f][j].start))+1);

            work[f][curr_with].start = arr[i] + 1;
            work[f][curr_with].end = work[!f][j].end + 1;


            work[f][curr_with].val = work[!f][j].val + work[!f][j].incr * (abs(arr[i] - work[!f][j].start)) + 1;
            tmp = work[!f][j].incr * (abs(arr[i] - work[!f][j].start)) + 1;
            work[f][curr_with].incr = 1 + work[!f][j].incr;

            work[f][curr_with++].best = min_with + tmp; // work[!f][j].incr * (abs(arr[i] - work[!f][j].start)) + 1;
            min_with = min((ll)min_with, work[!f][j].val + work[!f][j].incr * (abs(work[!f][j].end - work[!f][j].start)));

        }
    }

    return curr_with;
}



