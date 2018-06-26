#include <stdio.h>

int fn();

int x, y;

int main()
{
    int cases;
    scanf("%d", &cases);

    for(int i = 0; i < cases; i++)
    {
        scanf("%d %d", &x, &y);
        printf("%d\n", fn());
    }

    return 0;
}

int fn()
{
    int ans_x, ans_y;
    x = x - 2;
    y = y - 2;

    ans_x = x / 3;
    if(ans_x * 3 != x)
        ans_x++;

    ans_y = y / 3;
    if(ans_y * 3 != y)
        ans_y++;

    return ans_x * ans_y;
}
