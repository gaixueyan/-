#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

//�漰�߾�����ʱ���ṹ�����㣬�ڽṹ����д��ʼ����stringת�����������Ҳ��
//�������ؽṹ�����壬�ṹ�嵱�����������˴��ýṹ������������򣬲�֪���ṹ�彻���ĸ��Ӷȴ󲻴�
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
                if(cmp(buff[j],buff[i]))//С�� true
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
