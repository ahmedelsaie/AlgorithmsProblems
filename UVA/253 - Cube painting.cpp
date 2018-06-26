#include <stdio.h>
#include <cstring>

void rotate_forward();
void rotate_right();
void rotate_x();
bool is_equal();
bool fn();
void fill_array();

char first[8];
char second[8];
char input[50];

int main()
{
    while(gets(input))
    {
        bool ans = fn();
        if(ans)
            printf("TRUE\n");
        else
            printf("FALSE\n");
    }
    return 0;
}

bool fn()
{
    fill_array();
    for(int j = 0; j < 4; j++)
    {
        if(is_equal())
            return true;
        rotate_forward();
        if(is_equal())
            return true;

        for(int k = 0; k < 4; k++)
        {
            if(is_equal())
                return true;
            for(int h = 0; h < 4; h++)
            {
                if(is_equal())
                    return true;
                rotate_x();
                if(is_equal())
                    return true;
            }
            rotate_right();
            if(is_equal())
                return true;

        }
    }

    return false;
}

bool is_equal()
{
    for(int i = 0; i < 6; i++)
        if(first[i] != second[i])
            return false;
    return true;
}

void fill_array()
{
    for(int i = 0; i < 6; i++)
        first[i] = input[i];

    int j = 0;
    for(int i = 6; i < 12; i++)
    {
        second[j] = input[i];
        j++;
    }

    char top = second[5];
    char bottom = second[0];
    char front = second[1];
    char left = second[2];
    char back = second[4];
    char right = second[3];

    second[0] = top;
    second[1] = bottom;
    second[2] = front;
    second[3] = left;
    second[4] = back;
    second[5] = right;

    top = first[5];
    bottom = first[0];
    front = first[1];
    left = first[2];
    back = first[4];
    right = first[3];

    first[0] = top;
    first[1] = bottom;
    first[2] = front;
    first[3] = left;
    first[4] = back;
    first[5] = right;

}

void rotate_right()
{
    char top = second[0];
    char bottom = second[1];
    char front = second[2];
    char left = second[3];
    char back = second[4];
    char right = second[5];

    char new_top = left;
    char new_bottom = right;
    char new_right = top;
    char new_left = bottom;
    char new_front = front;
    char new_back = back;

    second[0] = new_top;
    second[1] = new_bottom;
    second[2] = new_front;
    second[3] = new_left;
    second[4] = new_back;
    second[5] = new_right;
}

void rotate_forward()
{
    char top = second[0];
    char bottom = second[1];
    char front = second[2];
    char left = second[3];
    char back = second[4];
    char right = second[5];

    char new_top = back;
    char new_bottom = front;
    char new_right = right;
    char new_left = left;
    char new_front = top;
    char new_back = bottom;

    second[0] = new_top;
    second[1] = new_bottom;
    second[2] = new_front;
    second[3] = new_left;
    second[4] = new_back;
    second[5] = new_right;
}

void rotate_x()
{
    char top = second[0];
    char bottom = second[1];
    char front = second[2];
    char left = second[3];
    char back = second[4];
    char right = second[5];

    char new_top = top;
    char new_bottom = bottom;
    char new_right = front;
    char new_left = back;
    char new_front = left;
    char new_back = right;

    second[0] = new_top;
    second[1] = new_bottom;
    second[2] = new_front;
    second[3] = new_left;
    second[4] = new_back;
    second[5] = new_right;
}

