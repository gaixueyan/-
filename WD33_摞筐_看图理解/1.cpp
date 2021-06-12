#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
char buf[85][85];
int main()
{
    int n;
    char c1,c2;
    int diyici=1;
    while(scanf("%d %c %c",&n,&c1,&c2)!=EOF)//输入有空格（如11 B A）时必须在%d间加空格，否则scanf("%d%c%c",&n,&c1,&c2)出错
    {
        cout<<n<<endl;
        cout<<c1<<endl;
        cout<<c2<<endl;
        if(n/2%2==1)
        {
            char r;
            r=c1;
            c1=c2;
            c2=r;
        }
        int lie=0;
        for(int i=0;i<n/2+1;i++)
        {
            if(lie==0)
            {
                for(int j=0;j<n;j++)
                {
                    buf[i][j]=c1;
                }
            }
            else
            {
                for(int j=0;j<lie;j++)
                {
                    buf[i][j]=buf[i-1][j];
                }
                if(i%2==1)
                {
                    for(int j=lie;j<n/2+1;j++)
                    {
                        buf[i][j]=c2;
                    }
                }
                else if(i%2==0)
                {
                    for(int j=lie;j<n/2+1;j++)
                    {
                        buf[i][j]=c1;
                    }
                }
            }
            for(int k=n/2+1;k<n;k++)
            {
                buf[i][k]=buf[i][n-1-k];
            }
            lie++;
        }
        for(int i=n/2+1;i<n;i++)
        {
            for(int k=0;k<n;k++)
            {
                buf[i][k]=buf[n-1-i][k];
            }
        }
        buf[0][0]=' ';
        buf[0][n-1]=' ';
        buf[n-1][0]=' ';
        buf[n-1][n-1]=' ';
        if(diyici==0)
        {
            cout<<endl;
        }
        diyici=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<buf[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
