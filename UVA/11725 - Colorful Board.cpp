#include <stdio.h>;
#include <cstring>;
#define MOD 1000000007
#define type  long long

type fn(int b1, int b2, int b3, int b4, int b5, int b6, int b7, int row);
bool update(int &s, int upper, int left, int i, int row, int col);

type dp[4][4][4][4][4][4][4][8];
bool visited [4][4][4][4][4][4][4][8];

int n, x;
bool array[10][10];
void correct(type &x);

int main()
{
    type ans;
    int cases, temp_x, temp_y, blocked, p = 1;
    scanf("%d", &cases);
    while(cases--)
    {
        memset(array, false, sizeof(array));
        scanf("%d %d", &n, &x);
        n++;
        x++;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < x; j++)
                array[i][j] = true;
        scanf("%d", &blocked);

        for(int i = 0; i < blocked; i++)
        {
            scanf("%d %d", &temp_x, &temp_y);
            temp_x--;
            temp_y--;
            array[temp_x][temp_y] = false;
        }

        memset(visited, false, sizeof(visited));

        ans = fn(0, 0, 0, 0, 0, 0, 0, 0);
        correct(ans);
        printf("Case %d: %lld", p++, ans);
        printf("\n");
    }

    return 0;
}

type fn(int b1, int b2, int b3, int b4, int b5, int b6, int b7, int row)
{
    if(row == n)
        return 1;

    type &ret = dp[b1][b2][b3][b4][b5][b6][b7][row];
    bool &flag = visited[b1][b2][b3][b4][b5][b6][b7][row];
    if(flag)
    {
        long long ne = ret;
        correct(ne);
        return ne;
    }
    flag = true;

    ret = 0;
    type temp;

    int l1 = 0, u1 = 4;
    int l2 = 0, u2 = 4;
    int l3 = 0, u3 = 4;
    int l4 = 0, u4 = 4;
    int l5 = 0, u5 = 4;
    int l6 = 0, u6 = 4;
    int l7 = 0, u7 = 4;

    if(array[row][0] == false)
    {
        l1 = 4;
        u1 = 5;
    }

    if(array[row][1] == false)
    {
        l2 = 4;
        u2 = 5;
    }
    if(array[row][2] == false)
    {
        l3 = 4;
        u3 = 5;
    }
    if(array[row][3] == false)
    {
        l4 = 4;
        u4 = 5;
    }
    if(array[row][4] == false)
    {
        l5 = 4;
        u5 = 5;
    }
    if(array[row][5] == false)
    {
        l6 = 4;
        u6 = 5;
    }
    if(array[row][6] == false)
    {
        l7 = 4;
        u7 = 5;
    }
    int s1, s2, s3, s4, s5, s6, s7;

    for(int i1 = l1; i1 < u1; i1++)
        if(update(s1, b1, i1, i1, row, 0))

            for(int i2 = l2; i2 < u2; i2++)
                if(update(s2, b2, i1, i2, row, 1))

                    for(int i3 = l3; i3 < u3; i3++)
                        if(update(s3, b3, i2, i3, row, 2))

                            for(int i4 = l4; i4 < u4; i4++)
                                if(update(s4, b4, i3, i4, row, 3))

                                    for(int i5 = l5; i5 < u5; i5++)
                                        if(update(s5, b5, i4, i5, row, 4))

                                            for(int i6 = l6; i6 < u6; i6++)
                                                if(update(s6, b6, i5, i6, row, 5))

                                                    for(int i7 = l7; i7 < u7; i7++)
                                                        if(update(s7, b7, i6, i7, row, 6))


                                                        {
                                                            temp = fn(s1, s2, s3, s4, s5, s6, s7, row + 1);
                                                            correct(temp);
                                                            ret = ret + temp; //;%MOD;
                                                            correct(ret);
                                                        }


    correct(ret);
    return ret;
}

void correct(type &x)
{
    if(x >= 1000000007)
        x -= 1000000007;
}

bool update(int &s, int upper, int left, int i, int row, int col)
{
    if(col == 0)
        left = 8;

    if(col > 0)
        if(array[row][col - 1] == false)
            left = 8;

    if(row == 0)
        upper = 8;

    if(row > 0)
        if(array[row - 1][col] == false)
            upper = 8;

    if(array[row][col] == false)
        s = 0;
    else
        s = i;

    if(upper != i && left != i)
        return true;

    if(array[row][col] == false)
        return true;

    return false;
}



