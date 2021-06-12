#include<stdio.h>
#include<iostream>
using namespace std;

int chaifenhe(int n)
{
    int sum=0;
    while(n!=0)
    {
        sum=sum+n%10;
        n=n/10;
    }
    return sum;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n>10)
        {
            n=chaifenhe(n);
        }
        printf("%d\n",n);
    }
    return 0;
}
