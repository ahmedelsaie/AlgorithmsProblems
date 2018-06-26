#include <bits/stdc++.h>
using namespace std;
#define MAX 305
#define ll long long

int fn(int val);

int arr[MAX], n, sum = 0;
const int inf = 999999999;
int ans_s, ans_p, tmp_s, tmp_p;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]), sum += abs(arr[i]);

    sort(arr, arr + n);

    int big = sum, small = 0, ret = inf, mid;
    while(big >= small)
    {
        mid = (big + small) / 2;
        int tmp = fn(mid);
        if(tmp && mid < ret)
            ret = mid, ans_p = tmp_p, ans_s = tmp_s;

        if(tmp)
            big = mid - 1;
        else
            small = mid + 1;
    }

    printf("%d\n", ret);
    printf("%d %d\n", ans_s, ans_p);

    return 0;

}

int fn(int val)
{
    int s1, s2, tmp1, tmp2;

    for(int prog = 0; (n - 1)*prog < 40000; prog++)
    {
        s1 = -inf, s2 = inf;
        //   printf("%d\n", prog);
        for(int i = 0; i < n; i++)
        {

            tmp1 = (arr[i] - val) - (i) * prog;
            tmp2 = (arr[i] + val) - (i) * prog;
            s1 = max(s1, tmp1), s2 = min(s2, tmp2);
            //   printf("%d %d %d\n", i, tmp1, s1);

            if(s2 < s1)
                break;
        }

        if(s1 <= s2)
        {
            tmp_p = prog, tmp_s = s1;
            return 1;
        }
    }

    return 0;
}
