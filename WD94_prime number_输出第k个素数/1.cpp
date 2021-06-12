#include<stdio.h>
#include<iostream>
using namespace std;
#include<math.h>

int num[10005];

int main()
{
    int i,j,t;
    int k;
    int flag;
    int sizeshu=1;
    i=2;
    while(sizeshu<10001)
    {
        //printf("%d ",sizeshu);
        t=(int)(sqrt(i)+1);
        flag=0;
        for(j=2; j<t && flag==0; j++)
        {
            if(i%j==0)
            {
                flag=1;
            }
        }
        if(flag==0)
        {
            num[sizeshu]=i;
            sizeshu++;
        }
        i++;
    }
    while(scanf("%d",&k)!=EOF)
    {
        printf("%d\n",num[k]);
    }
    return 0;
}
