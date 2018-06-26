#include <stdio.h>
#include <cstring>
int array[105];
int n;

int fn();

int main()
{
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    printf("%d\n", fn());

    return 0;
}

int fn()
{
    int i = 0, prev = -10;
    int ret = 0;
    bool flag = true;
    while(i < n)
    {
        if(flag)
        {
            if(array[i] == 1)
                ret++, flag = false, prev = i;
        }
        else if(array[i] == 1)
        {
            if(prev == i - 1)
                ret++;
            else
                ret += 2;
            prev = i;
        }

        i++;
    }

    return ret;

}
