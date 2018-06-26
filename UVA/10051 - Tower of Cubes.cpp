#include <stdio.h>
#include <cstring>

struct block
{
    int array[6];
};

int fn(int current, int colour);
void trace(int current, int colour, int i);
int max(int x, int y);
void print_block(int i);

int build[505];
int face[505];
block all[505];
int dp[505][106];
const int inf = 99999999;
int ans, n;
char text[30];

int main()
{
    int cases = 1;
    bool flag = true;

    while(true)
    {
        scanf("%d", &n);

        if(n == 0)
            break;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < 6; j++)
                scanf("%d", &all[i].array[j]);

        memset(dp, -1, sizeof(dp));
        ans = fn(0, 103);
        trace(0, 103, 0);

        if(flag)
            flag = false;
        else
            printf("\n");

        printf("Case #%d\n", cases++);
        printf("%d\n", ans);

        for(int i = 0; i < ans; i++)
        {
            print_block(i);
            printf("\n");
        }

    }
    return 0;
}

void trace(int current, int colour, int i)
{
    if(current == n)
        return;

    int ret = -1 * inf;
    int print_face, send_colour;
    int temp;
    int temp_position;

    if(colour == 103)
    {
        for(int i = 0; i < 6; i += 2)
        {
            temp = dp[current + 1][all[current].array[i + 1]] + 1;
            if(temp > ret)
            {
                ret = temp;
                print_face = i;
                send_colour = all[current].array[i + 1];
                temp_position = 0;
            }

            temp = dp[current + 1][all[current].array[i]] + 1;

            if(temp > ret)
            {
                ret = temp;
                print_face = i + 1;
                send_colour = all[current].array[i];
                temp_position = 1;
            }
        }
    }

    else
    {
        for(int i = 0; i < 6; i += 2)
        {
            if(all[current].array[i] == colour)
            {
                temp = dp[current + 1][all[current].array[i + 1]] + 1;
                if(temp > ret)
                {
                    ret = temp;
                    print_face = i;
                    send_colour = all[current].array[i + 1];
                    temp_position = 2;
                }
            }

            if(all[current].array[i + 1] == colour)
            {
                temp = dp[current + 1][all[current].array[i]] + 1;
                if(temp > ret)
                {
                    ret = temp;
                    print_face = i + 1;
                    send_colour = all[current].array[i];
                    temp_position = 3;
                }
            }
        }
    }

    if(dp[current + 1][colour] > ret)
    {
        send_colour = colour;
        temp_position = 4;
    }

    switch(temp_position)
    {
    case 0:
        build[i] = current;
        face[i] = print_face;
        trace(current + 1, send_colour, i + 1);
        break;

    case 1:
        build[i] = current;
        face[i] = print_face;
        trace(current + 1, send_colour, i + 1);
        break;

    case 2:
        build[i] = current;
        face[i] = print_face;
        trace(current + 1, send_colour, i + 1);
        break;

    case 3:
        build[i] = current;
        face[i] = print_face;
        trace(current + 1, send_colour, i + 1);
        break;

    case 4:
        trace(current + 1, send_colour, i);
        break;
    }
}

int fn(int current, int colour)
{
    if(current == n)
        return 0;

    int &ret = dp[current][colour];
    if(ret != -1)
        return ret;

    ret = -1 * inf;

    if(colour == 103)
    {
        for(int i = 0; i < 6; i += 2)
        {
            ret = max(ret, fn(current + 1, all[current].array[i + 1]) + 1);
            ret = max(ret, fn(current + 1, all[current].array[i]) + 1);
        }
    }
    else
    {
        for(int i = 0; i < 6; i += 2)
        {
            if(all[current].array[i] == colour)
                ret = max(ret, fn(current + 1, all[current].array[i + 1]) + 1);

            if(all[current].array[i + 1] == colour)
                ret = max(ret, fn(current + 1, all[current].array[i]) + 1);
        }
    }

    ret = max(ret, fn(current + 1, colour));

    return ret;
}

int max(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}

void print_block(int i)
{
    printf("%d ", build[i] + 1);
    switch(face[i])
    {
    case 0:
        printf("front");
        return;

    case 1:
        printf("back");

        break;

    case 2:
        printf("left");

        break;

    case 3:
        printf("right");

        break;

    case 4:
        printf("top");
        break;

    case 5:
        printf("bottom");
        break;
    }
}
