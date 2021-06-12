#include<stdio.h>
#include<iostream>
using namespace std;

int buf[100];

int main()
{
    int a,b,m;
    int sum;
    int i;
    int j;
    scanf("%d",&m);
    while(m!=0)
    {
        scanf("%d %d",&a,&b);
        i=0;
        sum=a+b;
        if(sum==0)
        {
            printf("0");
        }
        while(sum!=0)
        {
            buf[i]=sum%m;//生成倒序的m进制数
            sum=sum/m;
            i++;
        }
        for(j=i-1;j>=0;j--)
        {
            printf("%d",buf[j]);
        }
        printf("\n");
        scanf("%d",&m);
    }
    return 0;
}
