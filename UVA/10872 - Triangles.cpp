#include <stdio.h>
#include <cstring>

long long fn(int i, bool first, bool sec, bool third, bool remind, bool forth, bool even);
long long cnt_equal(int i, bool first, bool third, bool remind, bool even);
int third_cond(bool old_flag, int i, int sum);
int other_cond(bool old_flag, int i, int sum);
int forth_cond(bool old_flag, int x, int y);
int cnt_digit(int x);
int pre_process();

long long dp[12][2][2][2][2][2][2];
long long dp2[12][2][2][2][2];
int visited[12][2][2][2][2][2][2];
int visited_2[12][2][2][2][2];

int p;
int array[30];
int r;
int cases = 1;

int main()
{
    memset(visited, -1, sizeof(visited));
    memset(visited_2, -1, sizeof(visited_2));

    while(true)
    {
        scanf("%d", &p);
        if(p == 0)
            break;

        r = pre_process();

        long long total = fn(0, 0, 0, 0, 0, 0, 0);
        long long del = cnt_equal(0, 0, 0, 0, 0);
        if(p % 3 == 0)
            del--;
        long long f = total - del;
        f = f / 3;
        if(p % 3 == 0)
            del++;
        f = f + del;
        printf("Case %d: %lld\n", cases++, f);
    }

    return 0;
}

long long fn(int i, bool first, bool sec, bool third, bool remind, bool forth, bool even)
{
    if(i == r)
    {
        if(remind == 0 && first && sec &&  third && forth && even)
            return 1;
        return 0;
    }

    long long &ret = dp[i][first][sec][third][remind][forth][even];
    int &flag = visited[i][first][sec][third][remind][forth][even];
    if(flag == cases)
        return ret;
    ret = 0;
    flag = cases;

    int new_x, can_x;
    int new_y, can_y;
    int new_z, can_z;
    int new_f, can_f;
    int new_even;
    int sum;


    for(int x = 0; x < 10; x++)
    {
        new_x = other_cond(first, i, x) % 10;
        can_x = other_cond(first, i, x) / 10;

        if(!can_x)
            continue;

        for(int y = 0; y < 10; y++)
        {
            if (x % 2 == 0 && y % 2 == 0)
                new_even = 1;
            else
                new_even = 0;
            sum = x + y;

            new_y = other_cond(sec, i, y) % 10;
            can_y = other_cond(sec, i, y) / 10;

            new_f = forth_cond(forth, x, y) % 10;
            can_f = forth_cond(forth, x, y) / 10;

            if(!can_y || !can_f)
                continue;

            if(remind == 1)
            {
                if(sum + 1 > 9)
                {
                    sum++;
                    new_z = third_cond(third, i, sum % 10) % 10;
                    can_z = third_cond(third, i, sum % 10) / 10;

                    if(can_z)
                        ret += fn(i + 1, new_x, new_y, new_z, 1, new_f, new_even);
                    sum--;
                }

                if(sum > 9)
                {
                    new_z = third_cond(third, i, sum % 10) % 10;
                    can_z = third_cond(third, i, sum % 10) / 10;

                    if(can_z)
                        ret += fn(i + 1, new_x, new_y, new_z, 0, new_f, new_even);
                }
            }
            else
            {
                if(sum + 1 < 10)
                {
                    sum++;
                    new_z = third_cond(third, i, sum % 10) % 10;
                    can_z = third_cond(third, i, sum % 10) / 10;

                    if(can_z)
                        ret += fn(i + 1, new_x, new_y, new_z, 1, new_f, new_even);
                    sum--;
                }

                if(sum < 10)
                {
                    new_z = third_cond(third, i, sum % 10) % 10;
                    can_z = third_cond(third, i, sum % 10) / 10;

                    if(can_z)
                        ret += fn(i + 1, new_x, new_y, new_z, 0, new_f, new_even);
                }
            }

        }
    }

    return ret;

}

long long cnt_equal(int i, bool first, bool third, bool remind, bool even)
{
    if(i == r)
    {
        if(remind == 0 && first && third  && even)
            return 1;
        return 0;
    }

    long long &ret = dp2[i][first][third][remind][even];
    int &flag = visited_2[i][first][third][remind][even];
    if(flag == cases)
        return ret;
    ret = 0;
    flag = cases;

    int new_x, can_x;
    int new_z, can_z;
    int new_even;
    int sum;


    for(int x = 0; x < 10; x++)
    {
        new_x = other_cond(first, i, x) % 10;
        can_x = other_cond(first, i, x) / 10;

        if(!can_x)
            continue;

        if (x % 2 == 0)
            new_even = 1;
        else
            new_even = 0;
        sum = x + x;

        if(remind == 1)
        {
            if(sum + 1 > 9)
            {
                sum++;
                new_z = third_cond(third, i, sum % 10) % 10;
                can_z = third_cond(third, i, sum % 10) / 10;

                if(can_z)
                    ret += cnt_equal(i + 1, new_x, new_z, 1, new_even);

                sum--;
            }


            if(sum > 9)
            {
                new_z = third_cond(third, i, sum % 10) % 10;
                can_z = third_cond(third, i, sum % 10) / 10;

                if(can_z)
                    ret += cnt_equal(i + 1, new_x, new_z, 0, new_even);
            }
        }
        else
        {
            if(sum + 1 < 10)
            {
                sum++;
                new_z = third_cond(third, i, sum % 10) % 10;
                can_z = third_cond(third, i, sum % 10) / 10;

                if(can_z)
                    ret += cnt_equal(i + 1, new_x, new_z, 1, new_even);

                sum--;
            }

            if(sum < 10)
            {
                new_z = third_cond(third, i, sum % 10) % 10;
                can_z = third_cond(third, i, sum % 10) / 10;

                if(can_z)
                    ret += cnt_equal(i + 1, new_x, new_z, 0, new_even);
            }
        }

    }

    return ret;

}

int third_cond(bool old_flag, int i, int sum)
{
    if(old_flag)
        return 11;

    if(!old_flag && sum == array[i])
        return 10;

    if(!old_flag && sum > array[i])
        return 11;

    return 0;
}

int other_cond(bool old_flag, int i, int sum)
{
    if(old_flag)
        return 11;

    if(!old_flag && sum == array[i])
        return 10;

    if(!old_flag && sum < array[i])
        return 11;

    return 0;
}

int forth_cond(bool old_flag, int x, int y)
{
    if(old_flag)
        return 11;

    if(!old_flag && x == y)
        return 10;

    if(!old_flag && x < y)
        return 11;

    return 0;
}

int cnt_digit(int x)
{
    int ret = 0;
    while(x)
    {
        x = x / 10;
        ret++;
    }
    return ret;
}

int pre_process()
{
    int x = cnt_digit(p);
    int temp = p;

    for(int i = x; i > 0; i--)
    {
        array[i] = temp % 10;
        temp = temp / 10;
    }
    array[0] = 0;

    return x + 1;
}
