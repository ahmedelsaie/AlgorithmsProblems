#include <stdio.h>

struct time
{
    int start;
    int last;
};

bool fn();

time wife, meeting;


int main()
{
    int x1, y1, x2, y2, cases;

    scanf("%d", &cases);

    for(int i = 0; i < cases; i++)
    {
        scanf("%d:%d %d:%d", &x1, &y1, &x2, &y2);
        x1 = x1 * 100;
        x1 = x1 + y1;
        wife.start = x1;
        x2 = x2 * 100;
        x2 = x2 + y2;
        wife.last = x2;

        scanf("%d:%d %d:%d", &x1, &y1, &x2, &y2);
        x1 = x1 * 100;
        x1 = x1 + y1;
        meeting.start = x1;
        x2 = x2 * 100;
        x2 = x2 + y2;
        meeting.last = x2;

        if(fn())
            printf("Case %d: Hits Meeting", i + 1);
        else
            printf("Case %d: Mrs Meeting", i + 1);
        printf("\n");
    }

    return 0;
}

bool fn()
{
    if(meeting.start >= wife.start && meeting.start <= wife.last)
        return false;

    if(wife.start >= meeting.start && wife.start <= meeting.last)
        return false;

    return true;
}


