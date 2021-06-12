#include<stdio.h>
#include<iostream>
using namespace std;
int daodan[30];
int num[30];
int main()
{
    int k;
    int i,j;
    int maxi,now;
    while(scanf("%d",&k)!=EOF)
    {
        for(i=0;i<k;i++)
        {
            scanf("%d",&daodan[i]);
        }
        for(i=0;i<k;i++)
        {
            maxi=1;
            for(j=0;j<i;j++)
            {
                if(daodan[j]>=daodan[i])
                {
                    maxi=max(maxi,num[j]+1);
                }
            }
            num[i]=maxi;
        }
        int result=0;
        for(i=0;i<k;i++)
        {
            if(num[i]>result)
            {
                result=num[i];
            }
        }
        printf("%d\n",result);
    }
    return 0;
}
