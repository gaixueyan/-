#include<stdio.h>
#include<iostream>
using namespace std;
#include<string.h>

struct bigint
{
    int data[3002];
    int sizedata;
    void init()
    {
        for(int i=0;i<3002;i++)
        {
            data[i]=0;
        }
        sizedata=0;
    }
};

char stra[3002];
int sizestra;
char strb[3002];
int sizestrb;

int xiaoshu;
struct bigint a;
struct bigint b;
struct bigint sum;

struct bigint add(struct bigint a,struct bigint b)
{
    struct bigint sum;
    sum.init();
    int i;
    int r;
    for(i=0;i<a.sizedata || i<b.sizedata;i++)
    {
        r=sum.data[i]+a.data[i]+b.data[i];
        sum.data[i]=r%10;
        sum.data[i+1]=r/10;
        sum.sizedata++;
    }
    if(sum.data[sum.sizedata]!=0)
    {
        sum.sizedata++;
    }
    return sum;
}

int main()
{
    int n;
    int i,j;
    int ax,bx;
    int ling;
    while(scanf("%s ",stra)!=EOF)//两个连续%s就%s %s就可以，不用在前中后加getchar
    {
        scanf("%s",strb);
        sizestra=strlen(stra);
        sizestrb=strlen(strb);
        for(i=0;i<sizestra;i++)
        {
            if(stra[i]=='.')
            {
                ax=i;
                break;
            }
        }
        for(i=0;i<sizestrb;i++)
        {
            if(strb[i]=='.')
            {
                bx=i;
                break;
            }
        }
        xiaoshu=max(sizestra-ax-1,sizestrb-bx-1);
        a.init();
        b.init();
        sum.init();
        for(i=0;i<xiaoshu-(sizestra-ax-1);i++)
        {
            a.data[i]=0;
            a.sizedata++;
        }
        for(i=sizestra-1;i>=0;i--)
        {
            if(stra[i]!='.')
            {
                a.data[a.sizedata]=stra[i]-'0';
                a.sizedata++;
            }
        }
        for(i=0;i<xiaoshu-(sizestrb-bx-1);i++)
        {
            b.data[i]=0;
            b.sizedata++;
        }
        for(i=sizestrb-1;i>=0;i--)
        {
            if(strb[i]!='.')
            {
                b.data[b.sizedata]=strb[i]-'0';
                b.sizedata++;
            }
        }

        sum=add(a,b);
        ling=0;
        for(i=0;i<sum.sizedata;i++)
        {
            if(sum.data[i]!=0)
            {
                break;
            }
            ling++;
        }
        for(i=sum.sizedata-1;i>=ling;i--)
        {
            if(i==xiaoshu-1)
            {
                printf(".");
            }
            printf("%d",sum.data[i]);
        }
        printf("\n");
        n--;
    }
    return 0;
}
