#include <stdio.h>

void rotate_forward();
void rotate_right();
void rotate_x();
bool is_equal();
void fill_array();

int first[6];
int second[6];
int x, y;

int main()
{
    bool ans;
    int cases;
    scanf("%d", &cases);
    for(int i = 0; i < cases; i++)
    {
        ans = false;
        scanf("%d %d", &x, &y);
        fill_array();

        for(int j = 0; j < 4; j++)
        {
            if(is_equal())
                ans = true;
            rotate_forward();
            if(is_equal())
                ans = true;

            for(int k = 0; k < 4; k++)
            {
                if(is_equal())
                    ans = true;
                for(int h = 0; h < 4; h++)
                {
                    if(is_equal())
                        ans = true;
                    rotate_x();
                    if(is_equal())
                        ans = true;
                }
                rotate_right();
                if(is_equal())
                    ans = true;

            }
        }
        if(ans)
            printf("Equal");
        else
            printf("Not Equal");
        if(i < cases)
            printf("\n");
    }
    return 0;
}


void fill_array()
{
    for(int i = 5; i >= 0; i--)
    {
        first[i] = x % 10;
        second[i] = y % 10;
        x = x / 10;
        y = y / 10;
    }
}

bool is_equal()
{
    for(int i = 0; i < 6; i++)
        if(first[i] != second[i])
            return false;
    return true;
}

void rotate_right()
{
    //  top, bottom, front, left, back, right.

    int top = second[0];
    int bottom = second[1];
    int front = second[2];
    int left = second[3];
    int back = second[4];
    int right = second[5];

    int new_top = left;
    int new_bottom = right;
    int new_right = top;
    int new_left = bottom;
    int new_front = front;
    int new_back = back;

    second[0] = new_top;
    second[1] = new_bottom;
    second[2] = new_front;
    second[3] = new_left;
    second[4] = new_back;
    second[5] = new_right;
}

void rotate_forward()
{
    int top = second[0];
    int bottom = second[1];
    int front = second[2];
    int left = second[3];
    int back = second[4];
    int right = second[5];

    int new_top = back;
    int new_bottom = front;
    int new_right = right;
    int new_left = left;
    int new_front = top;
    int new_back = bottom;

    second[0] = new_top;
    second[1] = new_bottom;
    second[2] = new_front;
    second[3] = new_left;
    second[4] = new_back;
    second[5] = new_right;
}

void rotate_x()
{
    int top = second[0];
    int bottom = second[1];
    int front = second[2];
    int left = second[3];
    int back = second[4];
    int right = second[5];

    int new_top = top;
    int new_bottom = bottom;
    int new_right = front;
    int new_left = back;
    int new_front = left;
    int new_back = right;

    second[0] = new_top;
    second[1] = new_bottom;
    second[2] = new_front;
    second[3] = new_left;
    second[4] = new_back;
    second[5] = new_right;
}

