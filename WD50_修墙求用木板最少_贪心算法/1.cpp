//intʮλ����long long19λ��
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>//�����#include<iostream> using namespace std;һ��ʹ��
#include<iostream>
using namespace std;
int buf[602];
bool cmp(int x,int y)
{
    if(x>=y)return true;
    else return false;
}
int main()
{
    int l,n;
    int i;
    int sum;
    int changdu;
    int flag;
    while(scanf("%d %d",&l,&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&buf[i]);//scanf����Ҳ�ü�&
        }
        sort(buf,buf+n,cmp);
        sum=0;
        changdu=0;
        i=0;
        flag=0;
        if(l==0)
        {
            flag=1;
        }
        while(flag==0 && i<n)
        {
            changdu=changdu+buf[i];
            sum++;
            if(changdu>=l)
            {
                flag=1;
            }
            i++;
        }
        if(flag)
        {
            printf("%d\n",sum);
        }
        else
        {
            printf("impossible\n");
        }
    }
    return 0;
}
