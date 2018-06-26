#include <stdio.h>
#include <stdlib.h>

void print();
int get_cycle(int x);
int get_quad(int x);
int get_no(int x);
int get_x(int cycle, int quad, int no);
int special_cases();

int cycle;
int lastincycle;
int quad;
int firstinquad;
int no;
int r0, r1, r2, r3, r4, r5, r6, r7, r8;
int x;
int n;

int main()
{
    while(scanf("%d", &x) != EOF)
    {
        if(special_cases() == 1)
            continue;

        cycle = get_cycle(x);
        quad = get_quad(x);

        no = get_no(x);
        n = cycle * 8;
        n = n / 4;

        print();
    }

    return 0;
}

void print()
{
    if(quad == 1)
    {
        r6 = get_x(cycle + 1, quad, no);
        r7 = r6 + 1;
        r8 = r6 + 2;
        r4 = x;

        if(no == 1)
            r3 = get_x(cycle, 4, n);
        else
            r3 = x - 1;

        if(no == n)
            r5 = get_x(cycle + 1, 2, 1);
        else
            r5 = x + 1;


        if(no == 1 || no == 2)
            r0 = r3 - 1;
        else
            r0 = get_x(cycle - 1, quad, no - 2);



        if(no == 1)
            r1 = x - 1;
        else if(no == 2)
            r1 = get_x(cycle - 1, quad, 1);
        else if(no == n)
            r1 = x + 1;
        else
            r1 = r0 + 1;


        if(no == 1)
            r2 = get_x(cycle - 1, quad, no);
        else if(no == n || no == n - 1)
            r2 = r5 + 1;
        else
            r2 = r1 + 1;

        printf("%d;%d;%d;\n", r0, r3, r6);
        printf("%d;%d;%d;\n", r1, r4, r7);
        printf("%d;%d;%d;\n", r2, r5, r8);

        return;
    }

    if(quad == 2)
    {
        r8 = get_x(cycle + 1, quad, no);
        r5 = r8 + 1;
        r2 = r5 + 1;
        r4 = x;
        r7 = x - 1;

        if(no == n)
            r0 = get_x(cycle + 1, 3, 2);
        else if(no == n - 1)
            r0 = get_x(cycle, 3, 1);
        else
            r0 = get_x(cycle - 1, quad, no);

        if(no == n)
            r3 = x + 1;
        else if(no == n - 1)
            r3 = get_x(cycle - 1, quad, no - 1);
        else
            r3 = r0 - 1;


        if(no == 1)
            r6 = r7 - 1;
        else if(no == n)
            r6 = get_x(cycle - 1, quad, n - 2);
        else
            r6 = r3 - 1;

        if(no == n)
            r1 = get_x(cycle + 1, 3, 1);
        else
            r1 = x + 1;

        printf("%d;%d;%d;\n", r0, r3, r6);
        printf("%d;%d;%d;\n", r1, r4, r7);
        printf("%d;%d;%d;\n", r2, r5, r8);

        return;
    }

    if(quad == 3)
    {
        r2 = get_x(cycle + 1, quad, no);
        r1 = r2 + 1;
        r0 = r1 + 1;
        r4 = x;
        r5 = x - 1;

        if(no == n)
            r3 = get_x(cycle + 1, 4, 1);
        else
            r3 = x + 1;

        if(no == n)
            r6 = get_x(cycle + 1, 4, 2);
        else if(no == n - 1)
            r6 = x + 2;
        else
            r6 = get_x(cycle - 1, quad, no);

        if(no == n)
            r7 = x + 1;
        else if(no == n - 1)
            r7 = get_x(cycle - 1, 3, n - 2);
        else
            r7 = r6 - 1;

        if(no == n)
            r8 = get_x(cycle - 1, 3, n - 2);
        else if(no == 1)
            r8 = x - 2;
        else
            r8 = r7 - 1;

        printf("%d;%d;%d;\n", r0, r3, r6);
        printf("%d;%d;%d;\n", r1, r4, r7);
        printf("%d;%d;%d;\n", r2, r5, r8);

        return;
    }

    if(quad == 4)
    {
        r0 = get_x(cycle + 1, quad, no);
        r3 = r0 + 1;
        r6 = r3 + 1;
        r4 = x;
        r1 = x - 1;
        r7 = x + 1;

        if(no == 1)
            r2 = x - 2;
        else if(no == 2)
            r2 = get_x(cycle - 1, 3, n - 2);
        else
            r2 = get_x(cycle - 1, 4, no - 2);

        if(no == 1)
            r5 = get_x(cycle - 1, 3, n - 2);
        else
            r5 = r2 + 1;

        if(no == n)
            r8 = x + 2;
        else
            r8 = r5 + 1;

        printf("%d;%d;%d;\n", r0, r3, r6);
        printf("%d;%d;%d;\n", r1, r4, r7);
        printf("%d;%d;%d;\n", r2, r5, r8);

        return;
    }

}

int get_cycle(int x)
{
    int cycle2 = 1;
    int n = 9;
    for(cycle2 = 1; cycle2 < 1073741824; cycle2++)
    {
        if(x <= n)
        {
            lastincycle = n;
            return cycle2;
        }

        else
            n = n + 8 * (cycle2 + 1);
    }
}

int get_quad(int x)
{
    int n;
    n = (8 * cycle) / 4;
    int counter;
    int last2 = lastincycle;

    for(counter = 4; counter > 0; counter--)
    {
        last2 = last2 - n;
        if(x > last2)
        {
            firstinquad = last2 + 1;
            return counter;
        }

    }
}

int get_no(int x)
{
    int n;
    n = (8 * cycle) / 4;
    int m;
    m = firstinquad;
    int counter;
    for(counter = 1; counter <= n; counter++)
    {
        if(m == x)
            return counter;
        else
            m++;
    }
}

int get_x(int cycle, int quad, int no)
{
    int counter;
    int m = 2;
    int n;
    n = (8 * cycle) / 4;

    for(counter = 1; counter < cycle; counter++)
    {
        m = m + (8 * counter);
    }

    quad--;

    m = m + n * quad;


    no--;
    m = m + no;

    return m;


}

int special_cases()
{
    if(x == 1)
    {
        printf("7;8;9;\n");
        printf("6;1;2;\n");
        printf("5;4;3;\n");
        return 1;
    }


    if(x == 2)
    {
        printf("8;9;10;\n");
        printf("1;2;11;\n");
        printf("4;3;12;\n");
        return 1;
    }

    if(x == 3)
    {
        printf("1;2;11;\n");
        printf("4;3;12;\n");
        printf("15;14;13;\n");
        return 1;
    }

    if(x == 4)
    {
        printf("6;1;2;\n");
        printf("5;4;3;\n");
        printf("16;15;14;\n");
        return 1;
    }

    if(x == 5)
    {
        printf("19;6;1;\n");
        printf("18;5;4;\n");
        printf("17;16;15;\n");
        return 1;
    }

    if(x == 6)
    {
        printf("20;7;8;\n");
        printf("19;6;1;\n");
        printf("18;5;4;\n");
        return 1;
    }

    if(x == 7)
    {
        printf("21;22;23;\n");
        printf("20;7;8;\n");
        printf("19;6;1;\n");
        return 1;
    }

    if(x == 8)
    {
        printf("22;23;24;\n");
        printf("7;8;9;\n");
        printf("6;1;2;\n");
        return 1;
    }

    if(x == 9)
    {
        printf("23;24;25;\n");
        printf("8;9;10;\n");
        printf("1;2;11;\n");
        return 1;
    }

    return 0;
}

