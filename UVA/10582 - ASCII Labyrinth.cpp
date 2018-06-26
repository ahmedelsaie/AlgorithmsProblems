#include <stdio.h>
#include <cstring>
int array[10][10];
bool visited[10][10];
int ans;
int m_row, m_col;
char input[50];
void fn_input(int j);
void fn(int row, int col, char before);

int main()
{
    memset(visited, true, sizeof(visited));

    int cases;
    scanf("%d", &cases);
    for(int i = 0; i < cases; i++)
    {
        ans = 0;
        scanf("%d %d", &m_row, &m_col);

        gets(input);
        for(int j = 0; j < m_row; j++)
        {
            gets(input);
            gets(input);
            gets(input);
            fn_input(j);
            gets(input);
        }
        gets(input);

        fn(0, 0, 'r');
        fn(0, 0, 'd');
        printf("Number of solutions: %d\n", ans);
    }

    return 0;
}

void fn(int row, int col, char before)
{

    if(row < 0 || row > m_row - 1 || col < 0 || col > m_col - 1)
        return;

    if(!visited[row][col] || array[row][col] == 0)
        return;

    if(row == m_row - 1 && col == m_col - 1)
    {
        ans++;
        return;
    }

    visited[row][col] = false;

    if(array[row][col] == 1)
    {
        if(before == 'r')
            fn(row, col + 1, before);

        if(before == 'l')
            fn(row, col - 1, before);

        if(before == 'u')
            fn(row - 1, col, before);

        if(before == 'd')
            fn(row + 1, col, before);

        visited[row][col] = true;
        return;
    }

    if(array[row][col] == 2)
    {
        if(col == m_col - 1 || col == 0)
        {
            if(before == 'u' || before == 'd')
            {
                fn(row, col + 1, 'r');
                fn(row, col - 1, 'l');
            }

            if(before == 'l' || before == 'r')
                fn(row + 1, col, 'd');

            visited[row][col] = true;
            return;
        }

        if(row == m_row - 1)
        {
            if(before == 'u' || before == 'd')
                fn(row, col + 1, 'r');

            if(before == 'l' || before == 'r')
            {
                fn(row - 1, col, 'u');
                fn(row + 1, col, 'd');
            }
            visited[row][col] = true;
            return;
        }

        if(before == 'u' || before == 'd')
        {
            fn(row, col + 1, 'r');
            fn(row, col - 1, 'l');
        }

        if(before == 'l' || before == 'r')
        {
            fn(row - 1, col, 'u');
            fn(row + 1, col, 'd');
        }
        visited[row][col] = true;
        return;
    }
}


void fn_input(int j)
{
    int t = 1;
    int n = 0;
    for(int i = 0; i < m_col; i++)
    {
        n = 0;
        while(input[t] != '|')
        {
            if(input[t] == '*')
                n++;
            t++;
        }
        t++;

        if(n == 0)
            array[j][i] = 0;
        else if(n == 2)
            array[j][i] = 2;
        else
            array[j][i] = 1;
    }
    return ;
}
