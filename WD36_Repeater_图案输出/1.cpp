#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
using namespace std;
char moban[20][20];
char buf1[3001][3001];
char buf2[3001][3001];
int main()
{
    int N,Q;
    cin>>N;
    int i,j,k,m,n,gaim,gain;
    int r;
    int chang1,chang2;
    while(N!=0)
    {
        getchar();
        for(i=0;i<N;i++)
        {
            cin.getline(buf1[i],N+1);//接收一行字符串，cin.getline中空格不是停止，回车才是（对空格不敏感）
        }
        cout<<"shuruQ"<<endl;
        cin>>Q;
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                moban[i][j]=buf1[i][j];
            }
        }
        r=1;
        while(r<Q)
        {
            chang1=pow(N,r);
            chang2=pow(N,r+1);
            for(i=0;i<N;i++)
            {
                for(j=0;j<N;j++)
                {
                    if(moban[i][j]==' ')
                    {
                        for(m=chang1*i;m<chang1*(i+1);m++)
                        {
                            for(n=chang1*j;n<chang1*(j+1);n++)
                            {
                                buf2[m][n]=' ';
                            }
                        }
                    }
                    else
                    {
                        for(m=chang1*i,gaim=0;m<chang1*(i+1);m++,gaim++)
                        {
                            for(n=chang1*j,gain=0;n<chang1*(j+1);n++,gain++)
                            {
                                buf2[m][n]=buf1[gaim][gain];
                            }
                        }
                    }
                }
            }
            r++;
            for(i=0;i<chang2;i++)
            {
                for(j=0;j<chang2;j++)
                {
                    buf1[i][j]=buf2[i][j];
                }
            }
        }
        for(i=0;i<pow(N,Q);i++)
        {
            for(j=0;j<pow(N,Q);j++)
            {
                cout<<buf1[i][j];
            }
            cout<<endl;
        }
        cin>>N;
    }


    return 0;
}
