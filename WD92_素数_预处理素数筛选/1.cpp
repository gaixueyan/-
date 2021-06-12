#include<stdio.h>
#include<iostream>
using namespace std;
#include<math.h>

int num[10005];
void sushuchuli()
{
    int i,j;
    for(i=0; i<10001; i++)
    {
        num[i]=0;
    }
    for(i=2; i<10001; i++)
    {
        if(num[i]==0)
        {
            for(j=i*i; j<10001; j=j+i)
            {
                num[j]=1;
            }
        }
    }
}

int main()
{
    sushuchuli();
    int n;
    int i;
    bool flag;
    while(scanf("%d",&n)!=EOF)
    {
        flag=0;
        for(i=11; i<n; i=i+10)
        {
            if(num[i]==0)
            {
                if(flag==1)
                {
                    printf(" ");
                }
                printf("%d",i);
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("-1");
        }
        printf("\n");
    }
    return 0;
}
