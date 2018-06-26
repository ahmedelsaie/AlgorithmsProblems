#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

void run();
void move_onto();
void move_over();
void pile_onto();
void clear_roof(int x, int y);
void print();
void reset();
void find(int i);
void pile_over();

int ground[30][30];
int n = 0;
int a = 0;
int b = 1;

int find_row;
int find_col;

char first_type[10];
char second_type[10];

int main()
{
    while(scanf("%d", &n) != EOF)
    {
        reset();
        scanf("%s", first_type);
        while((strcmp(first_type, "quit")) != 0)
        {
            scanf("%d", &a);
            scanf("%s", second_type);
            scanf("%d", &b);

            run();
            scanf("%s", first_type);
        }

        print();
    }

    return 0;
}

void run()
{
    int c1, c2;
    find(a);
    c1 = find_col;
    find(b);
    c2 = find_col;
    if(a == b)
        return;

    if(c1 == c2)
        return;

    if(strcmp(first_type, "move") == 0 && strcmp(second_type, "over") == 0)
    {
        move_over();
        return;
    }

    if(strcmp(first_type, "move") == 0 && strcmp(second_type, "onto") == 0)
    {
        move_onto();
        return;
    }

    if(strcmp(first_type, "pile") == 0 && strcmp(second_type, "over") == 0)
    {
        pile_over();
        return;
    }

    if(strcmp(first_type, "pile") == 0 && strcmp(second_type, "onto") == 0)
    {
        pile_onto();
        return;
    }
}

void move_onto()
{
    int b_row, b_col;
    find(b);
    clear_roof(find_row, find_col);
    b_row = find_row;
    b_col = find_col;

    find(a);
    clear_roof(find_row, find_col);

    ground[b_row - 1][b_col] = a;
    ground[find_row][find_col] = -1;
}

void move_over()
{
    int a_row, a_col, counter;

    find(a);
    clear_roof(find_row, find_col);
    a_row = find_row;
    a_col = find_col;

    find(b);

    for(counter = find_row + 1; counter >= 0; counter--)
    {
        if(ground[counter][find_col] == -1)
            break;
    }

    ground[counter][find_col] = a;
    ground[a_row][a_col] = -1;
}

void pile_onto()
{
    int b_row, b_col, counter;
    int noof_boxes = 0;
    find(b);
    clear_roof(find_row, find_col);
    b_row = find_row;
    b_col = find_col;

    find(a);
    for(counter = find_row - 1; counter >= 0; counter--)
    {
        if(ground[counter][find_col] == -1)
            break;
        else
            noof_boxes++;
    }

    for(counter = 0; counter < noof_boxes + 1; counter++)
    {
        ground[b_row - counter - 1][b_col] = ground[find_row - counter][find_col];
        ground[find_row - counter][find_col] = -1;
    }
}

void pile_over()
{
    int b_row, b_col, counter;
    int noof_boxes = 0;

    find(b);
    b_row = find_row;
    b_col = find_col;

    for(counter = find_row - 1; counter >= 0; counter--)
    {
        if(ground[counter][find_col] == -1)
            break;
        else
            noof_boxes++;
    }

    b_row = b_row - noof_boxes;

    find(a);
    noof_boxes = 0;
    for(counter = find_row - 1; counter >= 0; counter--)
    {
        if(ground[counter][find_col] == -1)
            break;
        else
            noof_boxes++;
    }

    for(counter = 0; counter < noof_boxes + 1; counter++)
    {
        ground[b_row - counter - 1][b_col] = ground[find_row - counter][find_col];
        ground[find_row - counter][find_col] = -1;
    }
}

void find(int i)
{
    int counter, counter2;
    for(counter = 0; counter < n; counter++)
    {
        for(counter2 = 0; counter2 < n; counter2++)
        {
            if(ground[counter][counter2] == i)
            {
                find_row = counter;
                find_col = counter2;
                return;
            }
        }
    }
}

void clear_roof(int x, int y)
{
    int counter, counter2, z;
    for(counter = x - 1; counter >= 0; counter--)
    {
        if(ground[counter][y] == -1)
        {
            break;
        }
    }

    for(counter2 = counter + 1; counter2 < x; counter2++)
    {
        z = ground[counter2][y];

        ground[counter2][y] = -1;
        ground[n - 1][z] = z;
    }
}

void print()
{
    int counter, counter2;
    for(counter = 0; counter < n; counter++)
    {
        printf("%d:", counter);

        for(counter2 = n - 1; ground[counter2][counter] != -1; counter2--)
            printf(" %d", ground[counter2][counter]);
        printf("\n");
    }
}

void reset()
{
    int counter, counter2;
    for(counter = 0; counter < n; counter++)
    {
        for(counter2 = 0; counter2 < n; counter2++)
            ground[counter][counter2] = -1;
    }

    for(counter = 0; counter < n; counter++)
        ground[n - 1][counter] = counter;
}


