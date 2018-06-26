#include <stdio.h>
struct sym
{
    int new_flag;
    bool ok;
};

int cnt_digits(int x);
void put_array();
int getbit(int mask, int bit);
int setbit(int mask, int bit, int value);
int fn_special (int flag, int x, int y, int total);
bool check_ans(int x, int y, int z);
sym check(int i, int total, int flag);

bool zero_flag;
void reset();
int dp2[8][12][12][20];
int a[30];
int b[30];
int n[30];
int x, y, z;
int a_length, n_length, b_length;

int main()
{
    int ans;
    while (true)
    {
        scanf("%d %d %d", &x, &y, &z);
        if(x == -1 && y == -1 && z == -1)
            break;
        zero_flag = false;
        reset();
        put_array();
        if(z != 0)
            ans = fn_special (0, 0, 0, 0);
        else
        {
            zero_flag = true;
            if(x == 0)
                ans = fn_special (0, 0, 0, 0) + 1;
            else
                ans = fn_special (0, 0, 0, 0);
        }
        printf("%d\n", ans);

    }


    return 0;
}

int fn_special (int flag, int x, int y, int total)
{
    if(total == b_length)
    {
        if(getbit(flag, 2))
            return 1;
        else
            return 0;
    }


    int &ret = dp2[flag][x][y][total];
    if(ret != -1)
        return ret;
    ret = 0;
    int new_d;


    for(int i = 0; i <= 9; i++)
    {

        sym nw = check(i, total, flag);
        if(getbit(flag, 2) && nw.ok)
        {
            ret += fn_special(nw.new_flag, y, i, total + 1);
            continue;
        }

        if(nw.ok)
        {
            if(check_ans(x, y, i))
            {
                nw.new_flag = setbit(nw.new_flag, 2, 1);
            }
            ret += fn_special(nw.new_flag, y, i, total + 1);
            continue;
        }
    }
    return ret;
}

sym check(int i, int total, int flag)
{
    sym ret;
    ret.new_flag = flag;
    ret.ok = true;
    int check_a = getbit(flag, 0);
    int check_b = getbit(flag, 1);

    if(check_a && check_b)
        return ret;

    if(!check_a && !check_b)
    {
        if(b[total] == a[total] && b[total] == i)
            return ret;

        if(b[total] == i && a[total] < i)
        {
            ret.new_flag = setbit(flag, 0, 1);
            return ret;
        }


        if(a[total] == i && b[total] > i)
        {
            ret.new_flag = setbit(flag, 1, 1);
            return ret;
        }

        if(a[total] < i && b[total] > i)
        {
            //ret.new_flag=setbit(flag,1,1);
            // ret.new_flag=setbit(ret.,0,1);
            ret.new_flag = 3 | flag;
            return ret;
        }

    }

    if(check_a && !check_b)
    {
        if(i < b[total])
        {
            ret.new_flag = setbit(flag, 1, 1);
            return  ret;
        }


        if(i == b[total])
            return ret;
    }

    if(!check_a && check_b)
    {
        if(i > a[total])
        {
            ret.new_flag = setbit(flag, 0, 1);
            return ret;
        }


        if(i == a[total])
            return ret;
    }
    ret.ok = false;
    return ret;

}

bool check_ans(int x, int y, int z)
{
    if(zero_flag)
    {
        if(y != 0 && z == 0)
            return true;
        else
            return false;
    }
    if(n_length == 1)
        if(z == n[0])
            return true;

    if(n_length == 2)
        if(y == n[0] && z == n[1])
            return true;

    if(n_length == 3)
        if(x == n[0] && y == n[1] && z == n[2])
            return true;
    return false;
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

void reset()
{
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 11; j++)
            for(int k = 0; k < 11; k++)
                for(int h = 0; h < 20; h++)
                    dp2[i][j][k][h] = -1;

    for(int i = 0; i < 20; i++)
    {
        a[i] = 0;
        b[i] = 0;
        n[i] = 0;
    }
}

void put_array()
{
    int i, temp;
    a_length = cnt_digits(x);
    b_length = cnt_digits(y);
    n_length = cnt_digits(z);

    i = z;
    for(int j = n_length - 1; j >= 0; j--)
    {
        temp = i % 10;
        n[j] = temp;
        i = i / 10;
    }

    i = y;
    for(int j = b_length - 1; j >= 0; j--)
    {
        temp = i % 10;
        b[j] = temp;
        i = i / 10;
    }


    for(int j = 0; j < b_length - a_length; j++)
        a[j] = 0;

    i = x;

    for(int j = b_length - 1;; j--)
    {
        temp = i % 10;
        a[j] = temp;
        i = i / 10;
        if(!i)
            break;
    }

    return ;
}

int cnt_digits(int x)
{
    if(x == 0)
        return 1;
    int ret = 0;
    while(x)
    {
        x = x / 10;
        ret++;
    }
    return ret;
}





