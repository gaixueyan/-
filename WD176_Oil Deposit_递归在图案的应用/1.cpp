#include<stdio.h>
#include<iostream>
using namespace std;
char tuxing[102][102];
int m,n;
void xiaochu(int i,int j)
{
    tuxing[i][j]=0;
    if(j-1>=0 && tuxing[i][j-1]=='@')//��
    {
        xiaochu(i,j-1);//Ҫ���debug�Ļ����ڽ���ݹ�ǰ��д�ں��濴���������
    }
    if(i-1>=0 && tuxing[i-1][j]=='@')//��
    {
        xiaochu(i-1,j);
    }
    if(j+1<n && tuxing[i][j+1]=='@')//��
    {
        xiaochu(i,j+1);
    }
    if(i+1<m && tuxing[i+1][j]=='@')//��
    {
        xiaochu(i+1,j);
    }
    if(i-1>=0 && j-1>=0 && tuxing[i-1][j-1]=='@')//����
    {
        xiaochu(i-1,j-1);
    }
    if(i+1<m && j-1>=0 && tuxing[i+1][j-1]=='@')//����
    {
        xiaochu(i+1,j-1);
    }
    if(i-1>=0 && j+1<n && tuxing[i-1][j+1]=='@')//����
    {
        xiaochu(i-1,j+1);
    }
    if(j+1<n && i+1<m && tuxing[i+1][j+1]=='@')//����
    {
        xiaochu(i+1,j+1);
    }
    return;
}

int main()
{
    int i,j;
    int sum;
    while(scanf("%d",&m)!=EOF && m!=0)
    {
        scanf("%d",&n);
        getchar();//scanf("%c")Ҫ�ǳ�ע�����س����ո�
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%c",&tuxing[i][j]);
            }
            getchar();
        }
        sum=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(tuxing[i][j]=='@')
                {
                    sum++;
                    xiaochu(i,j);
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
