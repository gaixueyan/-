#include<stdio.h>
#include<iostream>
using namespace std;

int buff[1002];
int gaoroota;
int gaorootb;

void init(int n)
{
    int i;
    for(i=0;i<=n;i++)
    {
        buff[i]=-1;
    }
}

/*bool tong(int a,int b)
{
    gaoroota=0;
    gaorootb=0;
    int roota,rootb;
    int t;
    t=a;
    while(buff[t]!=-1)
    {
        t=buff[t];
        gaoroota++;
    }
    roota=t;
    t=b;
    while(buff[t]!=-1)
    {
        t=buff[t];
        gaorootb++;
    }
    rootb=t;
    if(roota==rootb)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void he(int a,int b)
{
    int r;
    int t;
    if(gaoroota>gaorootb)
    {
        r=a;
        a=b;
        b=r;
    }
    r=b;
    while(buff[r]!=-1)
    {
        t=buff[r];
        buff[r]=a;
        r=t;
    }
    buff[r]=a;
}*/

int findroot(int a)
{
    if(buff[a]==-1)
    {
        return a;
    }
    else
    {
        int tmp;
        tmp=findroot(buff[a]);
        buff[a]=tmp;
        return tmp;
    }
}

int main()
{
    int roota,rootb;
    int i;
    int sum;
    int n,m;
    int a,b;
    scanf("%d",&n);
    while(n!=0)
    {
        scanf("%d",&m);
        init(n);
        while(m>0)
        {
            scanf("%d %d",&a,&b);
            /*if(!tong(a,b))
            {
                he(a,b);
            }*/
            roota=findroot(a);
            rootb=findroot(b);
            if(roota!=rootb)
            {
                buff[rootb]=roota;
            }
            m--;
        }
        sum=0;
        for(i=1;i<=n;i++)
        {
            if(buff[i]==-1)
            {
                sum++;
            }
        }
        printf("%d\n",sum-1);
        scanf("%d",&n);
    }
    return 0;
}
