#include <stdio.h>
#include <cstring>
char array[105];
char array2[105];
int l;
int fn();

int main()
{
    scanf("%d", &l);
    scanf("%s", array);
    printf("%d\n", fn());
    return 0;
}


int fn()
{
    int rem = 1;
    int ans;
    for(int i = 0; i < l; i++)
    {
        if(rem == 1 && array[i] == '1')
            ans = 0;
        else if(rem == 1 && array[i] == '0')
            ans = 1, rem = 0;
        else if(rem == 0 && array[i] == '0')
            ans = 0, rem = 0;
        else if(rem == 0 && array[i] == '1')
            ans = 1, rem = 0;
        if(ans)
            array2[i] = '1';
        else
            array2[i] = '0';

             //       printf("%d %d\n",rem,ans);

    }

    int ret = 0;

    for(int i = 0; i < l; i++)
        if(array2[i] != array[i])
            ret++;
    return ret;

}
