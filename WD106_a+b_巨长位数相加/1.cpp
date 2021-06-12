#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

char stra[1002];
char strb[1002];
int a[1002];
int b[1002];
int sum[1002];
int sizea,sizeb,sizesum;

int main()
{
    int i,j;
    //int sizestra,sizestrb;
    while(scanf("%s %s",stra,strb)!=EOF)
    {
        for(i=0;i<1002;i++)
        {
            a[i]=b[i]=sum[i]=0;
        }
        sizea=strlen(stra);
        sizeb=strlen(strb);
        for(i=0,j=sizea-1;j>=0;i++,j--)//×Ö·û´®»¯intÊý×é
        {
            a[i]=stra[j]-'0';
        }
        for(i=0,j=sizeb-1;j>=0;i++,j--)
        {
            b[i]=strb[j]-'0';
        }
        for(i=0;i<sizea || i<sizeb;i++)
        {
             sum[i]=(sum[i]+a[i]+b[i])%10;
             sum[i+1]=(a[i]+b[i])/10;
        }
        sizesum=max(sizea,sizeb);
        if(sum[sizesum]!=0)
        {
            printf("%d",sum[sizesum]);
        }
        for(i=sizesum-1;i>=0;i--)
        {
            printf("%d",sum[i]);
        }
        printf("\n");
    }
    return 0;
}
