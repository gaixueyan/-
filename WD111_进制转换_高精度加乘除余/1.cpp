#include<stdio.h>
#include<iostream>
using namespace std;
#include<math.h>
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

char strx[3002];
int sizestrx;
struct bigint xm;
struct bigint xshi;
struct bigint quanzhi;
struct bigint xn;
struct bigint he;
int flag;

struct bigint cheng(struct bigint shu,int n)
{
    int i;
    int r;
    struct bigint result;
    result.init();
    for(i=0;i<shu.sizedata;i++)
    {
        r=shu.data[i]*n+result.data[i];
        result.data[i+1]=r/10;
        result.data[i]=r%10;
        result.sizedata++;
    }
    r=result.data[result.sizedata];
    while(r!=0)
    {
        result.data[result.sizedata]=r%10;
        r=r/10;
        result.sizedata++;
    }
    return result;
}

struct bigint add(struct bigint shu1,struct bigint shu2)
{
    struct bigint result;
    result.init();
    int i,r;
    for(i=0;i<shu1.sizedata || i<shu2.sizedata;i++)
    {
        r=shu1.data[i]+shu2.data[i]+result.data[i];
        result.data[i+1]=r/10;
        result.data[i]=r%10;
        result.sizedata++;
    }
    if(result.data[result.sizedata]!=0)
    {
        result.sizedata++;
    }
    return result;
}

struct bigint chu(struct bigint shu,int n)
{
    struct bigint result;
    result.init();
    int i,j,r;
    r=0;
    for(i=shu.sizedata-1,j=0;i>=0;i--,j++)
    {
        r=r*10;
        result.data[j]=(r+shu.data[i])/n;
        r=(r+shu.data[i])%n;
        result.sizedata++;
    }
    flag=0;
    for(i=0;i<result.sizedata;i++)
    {
        if(result.data[i]!=0)
        {
            flag=1;
            break;
        }
    }
    while(result.data[0]==0 && flag==1)
    {
        for(i=0;i<result.sizedata-1;i++)
        {
            result.data[i]=result.data[i+1];
        }
        result.sizedata--;
    }
    for(i=0;i<result.sizedata/2;i++)
    {
        r=result.data[i];
        result.data[i]=result.data[result.sizedata-i-1];
        result.data[result.sizedata-i-1]=r;
    }
    return result;
}

int yu(struct bigint shu,int n)
{
    int result;
    int i,j;
    int r=0;
    for(i=shu.sizedata-1;i>=0;i--)
    {
        r=r*10;
        r=(r+shu.data[i])%n;
    }
    result=r;
    return result;
}

int main()
{
    int n,m;
    int i,j;
    scanf("%d %d",&m,&n);
    scanf("%s",strx);
    sizestrx=strlen(strx);
    for(i=sizestrx-1,j=0;i>=0;i--,j++)
    {
        if(strx[i]>='0' && strx[i]<='9')
        {
            xm.data[j]=strx[i]-'0';
        }
        else if(strx[i]>='a' && strx[i]<='z')
        {
            xm.data[j]=strx[i]-'a'+10;
        }
        else if(strx[i]>='A' && strx[i]<='Z')
        {
            xm.data[j]=strx[i]-'A'+10;
        }
    }
    xm.sizedata=sizestrx;

    xshi.init();
    quanzhi.init();
    he.init();
    xn.init();
    quanzhi.data[0]=1;
    quanzhi.sizedata=1;

    for(i=0;i<xm.sizedata;i++)
    {
        he=cheng(quanzhi,xm.data[i]);
        xshi=add(xshi,he);
        quanzhi=cheng(quanzhi,m);
    }

    flag=1;
    while(flag==1)
    {
        xn.data[xn.sizedata]=yu(xshi,n);
        xshi=chu(xshi,n);
        xn.sizedata++;
    }

    for(i=xn.sizedata-1;i>=0;i--)
    {
        if(xn.data[i]>9)
        {
            printf("%c",xn.data[i]-10+'a');
        }
        else
        {
            printf("%d",xn.data[i]);
        }
    }
    return 0;
}
