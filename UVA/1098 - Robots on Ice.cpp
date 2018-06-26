#include <stdio.h>

void fn(int row, int col, int value, int mask_c, int mask_r, int help_r, int help_c);
bool check_half(int value, int row, int col);
bool check_b(int value, int row, int col);
int setbit(int mask, int bit, int value);
bool check_rmask(int mask_r, int help_r);
bool check_cmask(int mask_c, int help_c);
int abs(int x);
bool check_time(int value, int row, int col);

bool go_left(int row, int col);
bool go_right(int row, int col);
bool go_up(int row, int col);
bool go_down(int row, int col);

int f;
int m_row, m_col;
int rq, cq;
int rh, ch;
int rb, cb;
int dp[10][10];
int ans;

int main()
{
    int cases = 1;
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            dp[i][j] = true;

    while(true)
    {
        ans = 0;
        scanf("%d %d", &m_row, &m_col);
        if(m_row == 0 && m_col == 0)
            break;

        scanf("%d %d %d %d %d %d", &rq, &cq, &rh, &ch, &rb, &cb);
        rq = (m_row - 1) - rq;
        rh = (m_row - 1) - rh;
        rb = (m_row - 1) - rb;

        f = 0;
        fn(m_row - 1, 0, 1, 0, 0, 0, 0);

        printf("Case %d: %d\n", cases, ans);
        cases++;
    }

    return 0;
}

void fn(int row, int col, int value, int mask_c, int mask_r, int help_r, int help_c)
{
    if(row < 0 || row >= m_row || col < 0 || col >= m_col)
        return;

    if(!dp[m_row - 1][2] && !dp[m_row - 2][1] && value < m_row * m_col - 1)
        return;

    if(!dp[row][col])
        return;

    if(row == m_row - 1 && col == 1)
    {
        f++;
        if(value == m_row * m_col)
            ans++;
        return;
    }

    if(row == rq && col == cq && value != (m_row * m_col) / 4)
        return ;

    if(row == rh && col == ch && !check_half(value, row, col))
        return ;

    if(!check_time(value, row, col))
        return;

    if(row == rb && col == cb && !check_b(value, row, col))
        return ;

    if(!check_rmask(mask_r, help_r) || !check_cmask(mask_c, help_c) )
        return ;

    int new_r = mask_r;
    int new_c = mask_c;
    int new_helpr = help_r;
    int new_helpc = help_c;

    if(col == m_col - 1)
        new_helpr = setbit(new_helpr, row, 1);
    if(row == 0)
        new_helpc = setbit(new_helpc, col, 1);

    if(col > 0)
        new_r = setbit(mask_r, row, 1);
    if(row > 0)
        new_c = setbit(mask_c, col, 1);

    dp[row][col] = false;

    if(go_left(row, col))
    {
        fn(row, col - 1, value + 1, new_c, new_r, new_helpr, new_helpc);
        dp[row][col] = true;
        return;
    }

    if(go_right(row, col))
    {
        fn(row, col + 1, value + 1, new_c, new_r, new_helpr, new_helpc);
        dp[row][col] = true;
        return;
    }

    if(go_up(row, col))
    {
        fn(row - 1, col, value + 1, new_c, new_r, new_helpr, new_helpc);
        dp[row][col] = true;
        return;
    }

    if(go_down(row, col))
    {
        fn(row + 1, col, value + 1, new_c, new_r, new_helpr, new_helpc);
        dp[row][col] = true;
        return;
    }


    fn(row + 1, col, value + 1, new_c, new_r, new_helpr, new_helpc);
    fn(row - 1, col, value + 1, new_c, new_r, new_helpr, new_helpc);
    fn(row, col + 1, value + 1, new_c, new_r, new_helpr, new_helpc);
    fn(row, col - 1, value + 1, new_c, new_r, new_helpr, new_helpc);

    dp[row][col] = true;
    return;
}

bool check_rmask(int mask_r, int help_r)
{
    int t = (1 << m_row) - 1;
    int x = mask_r ^ t;
    int y = help_r ^ t;

    if(x == 0)
        if(y != 0)
            return false;
    return true;
}

bool check_cmask(int mask_c, int help_c)
{
    int t = (1 << m_col) - 1;
    int x = mask_c ^ t;
    int y = help_c ^ t;

    if(x == 0)
        if(y != 0)
            return false;
    return true;
}

bool check_b(int value, int row, int col)
{
    if(dp[rq][cq])
        return false;

    if(dp[rh][ch])
        return false;

    if(value != (m_row * m_col * 3) / 4)
        return false;

    return true;
}

bool check_time(int value, int row, int col)
{
    if(value + abs(row - rq) + abs(col - cq) > (m_row * m_col) / 4 && dp[rq][cq])
        return false;

    if(value + abs(row - rh) + abs(col - ch) > (m_row * m_col) / 2 && dp[rh][ch])
        return false;

    if(value + abs(row - rb) + abs(col - cb) > (m_row * m_col * 3) / 4 && dp[rb][cb])
        return false;

    return true;
}

bool check_half(int value, int row, int col)
{
    if(dp[rq][cq])
        return false;

    if(value != (m_row * m_col) / 2)
        return false;

    return true;
}

bool go_left(int row, int col)
{
    if(col >= 2 && row >= 1)
    {
        if(!dp[row][col - 2] && !dp[row - 1][col - 2] && !dp[row - 1][col - 1]  && !dp[row - 1][col] && dp[row][col - 1])
            return true;
        else
            return false;

    }

    if(col >= 2 && row + 1 < m_row)
    {
        if(!dp[row][col + 2] && !dp[row - 1][col + 2] && !dp[row - 1][col + 1]  && !dp[row - 1][col] && dp[row][col + 1])
            return true;
        else
            return false;

    }


    if(col == 1 && row > 0)
    {
        if(!dp[row - 1][col] && !dp[row - 1][col - 1] && dp[row][col - 1])
            return true;
        else
            return false;

    }


    if(col == 1 && row < m_row - 2)
    {
        if(!dp[row + 1][col] && !dp[row + 1][col - 1] && dp[row][col - 1])
            return true;
        else
            return false;

    }

    if(col == 1 && dp[row][col - 1])
        return true;


    return false;
}

bool go_right(int row, int col)
{
    if(row >= 2 && col <= m_col - 3)
    {
        if(!dp[row - 1][col] && !dp[row - 1][col + 1] && !dp[row - 1][col + 2] && !dp[row][col + 2] && dp[row][col + 1])
            return true;
        else
            return false;
    }

    if(row >= 2)
    {
        if(!dp[row - 1][col] && !dp[row - 1][col - 1] && !dp[row - 1][col - 2] && !dp[row][col - 2] && dp[row][col - 1])
            return true;
        else
            return false;
    }


    if(col + 1 == m_col - 1)
    {
        if(!dp[row - 1][col] && !dp[row - 1][col + 1] && dp[row][col + 1])
            return true;
        else
            return false;
    }

    if(col + 1 == m_col - 1)
    {
        if(!dp[row + 1][col] && !dp[row + 1][col + 1] && dp[row][col + 1])
            return true;
        else
            return false;
    }

    if(row == 0 && col == m_col - 2 && dp[row][col + 1])
        return true;

    if(row == m_row - 1 && col == m_col - 2 && dp[row][col + 1])
        return true;


    return false;
}

bool go_up(int row, int col)
{
    if(row >= 2 && col <= m_col - 3)
    {
        if(!dp[row][col + 1] && !dp[row - 1][col + 1] && !dp[row - 2][col + 1] && !dp[row - 2][col] && dp[row - 1][col])
            return true;
        else
            return false;
    }


    if(row >= 2 && col > 0)
    {
        if(!dp[row][col - 1] && !dp[row - 1][col - 1] && !dp[row - 2][col - 1] && !dp[row - 2][col] && dp[row - 1][col])
            return true;
        else
            return false;
    }

    if(col == 0 && row == 1 && dp[row - 1][col])
        return true;


    if(col == m_col - 1 && row == 1 && dp[row - 1][col])
        return true;

    if(row == 1 && col > 0)
    {
        if(!dp[row][col - 1] && !dp[row - 1][col - 1] && dp[row - 1][col])
            return true;
        else
            return false;
    }


    if(row == 1 && col + 1 <= m_col - 1)
    {
        if(!dp[row][col + 1] && !dp[row - 1][col + 1] && dp[row - 1][col])
            return true;
        else
            return false;
    }

    return false;
}

bool go_down(int row, int col)
{

    if(row == m_row - 2 )
    {
        if(!dp[row][col + 1] && !dp[row + 1][col + 1] && dp[row + 1][col])
            return true;
        else
            return false;
    }


    if(row == m_row - 2 && col > 1)
    {
        if(!dp[row][col - 1] && !dp[row + 1][col - 1] && dp[row + 1][col])
            return true;
        else
            return false;
    }

    if(col == m_col - 1 && row == m_row - 2 && dp[row + 1][col])
        return true;

    if(row + 2 < m_row && col + 1 < m_col)
    {
        if(!dp[row][col + 1] && !dp[row + 1][col + 1] && !dp[row + 2][col + 1] && !dp[row + 2][col] && dp[row + 1][col])
            return true;
        else
            return false;
    }

    if(row + 2 < m_row && col > 0)
    {
        if(!dp[row][col - 1] && !dp[row + 1][col - 1] && !dp[row + 2][col - 1] && !dp[row + 2][col] && dp[row + 1][col])
            return true;
        else
            return false;
    }


    return false;
}

int setbit(int mask, int bit, int value)
{
    if(value == 1)
        return(mask | (1 << bit));
    else
        return (mask&~(1 << bit));
}

int abs(int x)
{
    if(x >= 0)
        return x;
    else
        return -1 * x;
}
