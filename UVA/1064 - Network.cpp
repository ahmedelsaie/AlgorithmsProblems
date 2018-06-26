#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define MAX 1005

template <typename type>
void merge_sort(int start, int last, type array, type swap);
void message_buffer(int x);
void pre_process();
int fn(int before, int curr, bool flag, int m);

struct packet
{
    int curr_i, all_i, id, start, end;
};

packet array[MAX], help[MAX], local_msgs[MAX][MAX], ordered[MAX];
int total_buffer[MAX][MAX], visited[MAX][MAX][2], dp[MAX][MAX][2], local_accum[MAX][MAX];
int finished[MAX], indx[MAX], msg_sizes[MAX], accum[MAX], n_packets, n_msgs, cases = 1;

int main()
{
    int tmp;
    memset(visited, -1, sizeof(visited));

    while(true)
    {
        memset(indx, 0, sizeof(indx));

        scanf("%d %d", &n_msgs, &n_packets);
        if(n_msgs + n_packets == 0)
            break;

        for(int i = 1; i <= n_msgs; i++)
            scanf("%d", &msg_sizes[i]);

        for(int i = 1; i <= n_packets; i++)
        {
            scanf("%d %d %d", &array[i].id, &array[i].start, &array[i].end);
            array[i].all_i = i;
            tmp = array[i].id, indx[tmp]++;
            array[i].curr_i = indx[tmp];
            local_msgs[tmp][indx[tmp]] = array[i];
        }
        pre_process();
        printf("Case %d: %d\n\n", cases, fn(0, 1, 0, 0));

        cases++;
    }

    return 0;
}

int fn(int before, int curr, bool flag, int m)
{
    if(curr > n_packets)
    {
        if(before != n_packets)
            return 9999999;
        return 0;
    }

    int& f = visited[before][curr][flag];
    int& ret = dp[before][curr][flag];
    if(f == cases)
        return ret;
    f = cases, ret = 9999999;
    int curr_id = array[curr].id;
    int curr_i = array[curr].curr_i;
    int last = indx[curr_id], tmp, c1;

    ///1 doing job
    if(flag)
    {
        ///finished
        if(curr_i == last)
        {
            tmp = accum[curr] + total_buffer[curr_id][curr_i] - finished[before] - local_accum[curr_id][curr_i];

            m = max(m, tmp);
            c1 = max(m, fn(curr, curr + 1, 0, 0));
            ret = min(ret, c1);
        }
        else
        {
            ///not finished
            tmp = total_buffer[curr_id][curr_i] + accum[curr] - local_accum[curr_id][curr_i] - finished[before];

            m = max(m, tmp);
            ret = min(ret, fn(before, local_msgs[curr_id][curr_i + 1].all_i, 1, m));
        }
    }
    else
    {
        ///0 choices open---still choosing
        ///take it
        if(local_msgs[curr_id][0].all_i == curr || (curr && local_msgs[curr_id][curr_i - 1].all_i <= before))
            ret = min(ret, fn(before, curr, 1, 0));

        ret = min(ret, fn(before, curr + 1, 0, 0));
    }

    return ret;
}

void pre_process()
{
    for(int i = 1; i <= n_msgs; i++)
        message_buffer(i);

    accum[0] = 0;
    for(int i = 1; i <= n_packets; i++)
        accum[i] = accum[i - 1] + array[i].end - array[i].start + 1;

    for(int i = 1; i <= n_msgs; i++)
        for(int j = 1; j <= indx[i]; j++)
            local_accum[i][j] = local_accum[i][j - 1] + (local_msgs[i][j].end - local_msgs[i][j].start + 1);

    finished[0] = 0;
    int sum = 0;
    for(int i = 1; i <= n_packets; i++)
    {
        if(array[i].curr_i == indx[array[i].id])
            sum += msg_sizes[array[i].id];
        finished[i] = sum;
    }

}

void message_buffer(int x)
{
    int i, last, curr_buffer = 0, t = indx[x], j;

    for(int i = 1; i <= t; i++)
        ordered[i] = local_msgs[x][i];

    merge_sort(1, t, ordered, help);
    i = 1, j = 1;

    while(i <= t || j <= t)
    {
        if(ordered[i].start == local_msgs[x][j].start)
            total_buffer[x][j] = curr_buffer, i++, j++;
        else if(ordered[i].curr_i > j)
            curr_buffer += local_msgs[x][j].end - local_msgs[x][j].start + 1, total_buffer[x][j] = curr_buffer, j++;
        else
            curr_buffer -= ordered[i].end - ordered[i].start + 1, i++;
    }
}

///merge_sort
template <typename type>
void merge_sort(int start, int last, type array, type swap)
{
    if(last <= start)
        return;

    int middle = (last - start) / 2;
    middle = start + middle;

    merge_sort(start, middle, array, swap);
    merge_sort(middle + 1, last, array, swap);

///MERGING ///MERGING ///MERGING ///MERGING
    int p1 = start;
    int p2 = middle + 1;
    int main_p = start;

    for(int i = start; i <= middle; i++)
        swap[i] = array[i];

    while(main_p <= last)
    {
        if(p1 > middle)
            array[main_p] = array[p2], p2++;

        else if(p2 > last)
            array[main_p] = swap[p1], p1++;

        else if(swap[p1].start < array[p2].start)
            array[main_p] = swap[p1], p1++;

        else
            array[main_p] = array[p2], p2++;

        main_p++;
    }
    return;
}
