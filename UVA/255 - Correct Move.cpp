#include <stdio.h>

int get_row(int x);
int get_col(int x, int row);
int abs(int x);
void fn();

int king, queen, move;

int main()
{
    while(scanf("%d", &king) != EOF)
    {
        scanf("%d %d", &queen, &move);
        fn();
    }

    return 0;
}

void fn()
{
    if(king == queen)
    {
        printf("Illegal state\n");
        return ;
    }

    int king_row, king_col, queen_row, queen_col;
    int move_row, move_col;
    king_row = get_row(king);
    king_col = get_col(king, king_row);

    queen_row = get_row(queen);
    queen_col = get_col(queen, queen_row);

    move_row = get_row(move);
    move_col = get_col(move, move_row);

    if(move_col != queen_col && move_row != queen_row)
    {
        printf("Illegal move\n");
        return;
    }


    if(move_row == queen_row && king_row == queen_row)
    {
        if(queen_col < king_col && move_col >= king_col)
        {
            printf("Illegal move\n");
            return;
        }

        if(queen_col > king_col && move_col <= king_col)
        {
            printf("Illegal move\n");
            return;
        }

    }


    if(move_col == queen_col && king_col == queen_col)
    {
        if(queen_row < king_row && move_row >= king_row)
        {
            printf("Illegal move\n");
            return;
        }

        if(queen_row > king_row && move_row <= king_row)
        {
            printf("Illegal move\n");
            return;
        }

    }

    if(move_row > 8 || move_row < 1)
    {
        printf("Illegal move\n");
        return;
    }

    if(move_col > 8 || move_col < 1)
    {
        printf("Illegal move\n");
        return;
    }

    if(move == queen)
    {
        printf("Illegal move\n");
        return;
    }


    if(move_col == king_col)
    {
        if(abs(move_row - king_row) == 1)
        {
            printf("Move not allowed\n");
            return;
        }
    }


    if(move_row == king_row)
    {
        if(abs(move_col - king_col) == 1)
        {
            printf("Move not allowed\n");
            return;
        }
    }

    if(king_row == 1 && king_col == 1)
    {
        if(abs(king_col - move_col) == 1 && abs(king_row - move_row) == 1)
        {
            printf("Stop\n");
            return;
        }

    }

    if(king_row == 8 && king_col == 1)
    {
        if(abs(king_col - move_col) == 1 && abs(king_row - move_row) == 1)
        {
            printf("Stop\n");
            return;
        }
    }


    if(king_row == 8 && king_col == 8)
    {
        if(abs(king_col - move_col) == 1 && abs(king_row - move_row) == 1)
        {
            printf("Stop\n");
            return;
        }
    }


    if(king_row == 1 && king_col == 8)
    {
        if(abs(king_col - move_col) == 1 && abs(king_row - move_row) == 1)
        {
            printf("Stop\n");
            return;
        }
    }


    printf("Continue\n");
    return;
}

int get_col(int x, int row)
{
    row--;
    return x - (8 * row) + 1;
}

int get_row(int x)
{
    int row = 7;
    for(int i = 1; i <= 8; i++)
    {
        if(x <= row)
            return i;
        row += 8;
    }
}

int abs(int x)
{
    if(x >= 0)
        return x;
    else
        return -1 * x;
}
