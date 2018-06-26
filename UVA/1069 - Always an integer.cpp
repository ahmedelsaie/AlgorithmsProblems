#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct term
{
    long long coff, power;
};

///input functions
void process(char tmp[]);
int nxt_block(int i, char tmp[]);
long long power(int b, int p);
int calc_upper(int x);
bool check();
long long pow_mod(long long x, long long k);

term array[10000];
char str[10000];

const int inf = 9999;
int n;
long long num;

long long limit, MAX;
int length;

int main()
{
    int cases = 1;

    while (~scanf("%s", str) && str[0] != '.')
    {
        process(str);
        bool ans = check();

        if(ans)
            printf("Case %d: Always an integer", cases++);
        else
            printf("Case %d: Not always an integer", cases++);
        printf("\n");

        // printf("%d\n",limit);

        // printf("Done %d\n",n);

        /// for(int i=0; i<n; i++)
        //  printf("%lld %lld\n",array[i].coff,array[i].power);
        // printf("%lld\n",num);
    }

    return 0;
}

bool check()
{
    for (long long i = 0; i <= MAX + 1; i++)
    {
        long long x = 0;
        for (int j = 0; j < n; j++)
            x = (x + array[j].coff * pow_mod(i, array[j].power)) % num;
        if (x)
            return false;
    }

    return true;
}

long long pow_mod(long long x, long long k)
{
    long long ans = 1;
    while (k)
    {
        if (k & 1) ans = ans * x % num;
        x = (x * x) % num;
        k >>= 1;
    }
    return ans;
}

long long power(int b, int p)
{
    if(p == 1)
        return b;

    if(p == 0)
        return 1;

    if(p % 2 != 0)
        return b * power(b, p - 1);
    else
    {
        long long x;
        x = power(b, p / 2);
        return x * x;
    }
}

void process(char tmp[])
{
    int i = 0;
    length = strlen(tmp);

    ///(-n^14-11n+1)/3
    n = 0;
    limit = 0;
    while (i < length && tmp[i] != ')')
    {
        i = i + nxt_block(i, tmp);
    }
    i += 2;
    // printf("%c",tmp[i]);
    ///(-n^14-11n+1)/3
    char work[50];
    int j = 0;
    while(tmp[i] >= '0' && tmp[i] <= '9' && i < length)
    {
        work[j] = tmp[i];
        i++, j++;
    }
    work[j] = '\0';
    num = atoi(work);

    return ;
}

int nxt_block(int i, char tmp[])
{
    int main_i = i;
    if(i >= length)
        return 0;


    long long sign = 1, pow = 0, coff = 0;

    ///open bracket
    if(tmp[i] == '(')
        i++;


    ///getting sign
    if(tmp[i] == '+')
    {
        sign = 1, i++;

        if(i >= length)
            return 0;

    }
    else if (tmp[i] == 'n')
        sign = 1;
    else if(tmp[i] == '-')
        sign = -1, i++;
//printf("%d\n",sign);
///(-n^14-11n+1)/3
    if(i >= length)
        return 0;
    ///getting number
    if(tmp[i] == 'n')
        coff = 1 * sign;
    else
    {
        //printf("%c\n",tmp[i]);
        char work[50];
        int j = 0;
        while(tmp[i] >= '0' && tmp[i] <= '9' && i < length)
        {
            work[j] = tmp[i];
            i++, j++;
        }
        work[j] = '\0';
        coff = sign * atoi(work);
    }

    if(i >= length)
        return 0;
    ///getting power
    if(tmp[i] == ')')
        pow = 0;
    else
    {
        i++;
        if(i >= length)
            return 0;
        if(tmp[i] == '^')
        {
            i++;
            char work[50];
            int j = 0;
            while(tmp[i] >= '0' && tmp[i] <= '9' && i < length)
            {
                work[j] = tmp[i];
                i++, j++;
            }
            work[j] = '\0';
            pow = atoi(work);
        }
        else
            pow = 1;
    }

    //printf("%d\n",pow);
    array[n].coff = coff;
    array[n].power = pow;
    MAX = max(MAX, pow);
    n++;

    return i - main_i;
}

