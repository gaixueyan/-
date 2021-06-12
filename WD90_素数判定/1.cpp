#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;

bool sushu(int n)
{
    int i;
    int up=(int)(sqrt(n)+1);
    for(i=2;i<up;i++)//不在for的判断里写sqrt函数，因为这要每次循环都算一遍sqrt，慢
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n<2)
        {
            printf("NO\n");
        }
        else
        {
            if(sushu(n))
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}
