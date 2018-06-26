#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 505

int fn();
void clean();
void rot(int start, int mode, int indx);
int get_nxt(int indx);

int arr[MAX], arr2[MAX], n, tc;

int main()
{
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d", &n) ;
        for(int i = 0; i < n; i++)
            scanf("%d", &arr2[i]);

        printf("%s\n", fn() == 1 ? "possible" : "impossible");
    }

    return 0;
}

int fn()
{
    clean();

    int curr = 2, p, place = 1, tmp2[5];

    while(curr <= n - 2)
    {
        p = get_nxt(place);
        if(p == n - 1)
        {
            ///swap manualy
            ///a b c ---> b c a  0 1  2  1  2  0
            tmp2[0] = arr[n - 3], tmp2[1] = arr[n - 2], tmp2[2] = arr[n - 1];
            arr[n-3] = tmp2[1];
            arr[n-2] = tmp2[2];
            arr[n-1] = tmp2[0];
            p = get_nxt(place);
        }

        rot(p, 0, curr - 1);
        place++;
        curr++;
    }

    int tmp,j;
    while(place < n)
    {
        p = get_nxt(place);
        if(p == place)
        {
            place++;
            continue;
        }
        tmp = arr[p];
        for(j = p; j < n; j++)
            arr[j] = arr[j + 1];
        n--;
        int start = p;
        int j = (start + 4) % n;
        int cnt = 0;
        while(j != start)
        {
            if(j == place)
            {
                for(int i = n + 1; i > place; i--)
                    arr[i] = arr[i - 1];
                arr[place] = tmp;
                break;
            }

            j = (j + 4) % n;
            if(cnt++ > 2000)
                return 0;
        }


        n++;
        place++;
    }

    for(int i = 0; i < n; i++)
        if(arr[i] != i + 1)
            return false;

    return true;
}

void rot(int start, int mode, int indx)
{
    int tmp[MAX], i;
    if(mode == 0)
    {
        tmp[0] = arr[start], tmp[1] = arr[start + 1];
        for(i = start + 1; i > indx; i--)
            arr[i] = arr[i - 2];
        arr[i] = tmp[0], arr[i + 1] = tmp[1];
    }
    else
    {
        tmp[0] = arr[start];
        for(i = start; i > indx; i--)
            arr[i] = arr[i - 1];
        arr[i] = tmp[0];
    }
}

int get_nxt(int indx)
{
    int ret = indx, val = 9999;
    for(int i = indx; i < n; i++)
    {
        if(arr[i] < val)
            val = arr[i], ret = i;
    }

    return ret;
}

void clean()
{
    for(int i = 0; i < n; i++)
        arr[i] = arr2[i];

    int p = get_nxt(0);

    int j = 0;
    for(int i = p; i < n; i++)
        arr[j++] = arr2[i];

    for(int i = 0; i < p; i++)
        arr[j++] = arr2[i];
}

