#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

//涉及高精度数时，结构体真香，在结构体里写初始化，string转化，输出函数也香
//函数返回结构体整体，结构体当参数都不错。此处用结构体数组遍历排序，不知道结构体交换的复杂度大不大？
struct bigint
{
    int data[1002];
    int sizedata;
    void init()
    {
        int i;
        for(i=0;i<1002;i++)
        {
            data[i]=0;
        }
        sizedata=0;
    }
    void strtobigint(char str[])
    {
        int i;
        int sizestr=strlen(str);
        for(i=0;i<sizestr;i++)
        {
            data[sizedata]=str[i]-'0';
            sizedata++;
        }
    }
    void output()
    {
        int i;
        for(i=0;i<sizedata;i++)
        {
            printf("%d",data[i]);
        }
        printf("\n");
    }
};

struct bigint buff[102];
char str[1002];

bool cmp(struct bigint a,struct bigint b)
{
    int i;
    if(a.sizedata<b.sizedata)
    {
        return true;
    }
    else if(a.sizedata>b.sizedata)
    {
        return false;
    }
    else
    {
        for(i=0;i<a.sizedata;i++)
        {
            if(a.data<b.data)
            {
                return true;
            }
            else if(a.data>b.data)
            {
                return false;
            }
        }
        return false;
    }
}

int main()
{
    int n;
    int i,j;
    struct bigint r;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            buff[i].init();
            buff[i].strtobigint(str);
        }
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(cmp(buff[j],buff[i]))//小则 true
                {
                    r=buff[i];
                    buff[i]=buff[j];
                    buff[j]=r;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            buff[i].output();
        }
    }
    return 0;
}
