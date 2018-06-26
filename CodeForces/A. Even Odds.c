#include <stdio.h>
#include <stdlib.h>
unsigned long long operator(unsigned long long n,unsigned long long place);
int main()
{
unsigned long long n,place;
    scanf("%lld %lld",&n,&place);
    printf("%lld",operator(n,place));
    return 0;
}




unsigned long long operator(unsigned long long n,unsigned long long place)
{
    unsigned long long even,odd;
    even=n/2;
    odd=n-even;
    if(place<=odd)
    {
        return 2*place-1;
    }
    else
    {
        place=place-odd;
        return place*2;
    }
}
