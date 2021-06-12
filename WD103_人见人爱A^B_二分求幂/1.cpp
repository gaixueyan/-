#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;

int erjinzhi[50];

int main()
{
    int A,B;
    int sizeerjinzhi;
    int i;
    int result;
    int cheng;
    scanf("%d %d",&A,&B);
    while(A!=0 || B!=0)
    {
        result=1;
        cheng=1;
        sizeerjinzhi=0;
        while(B!=0)
        {
            erjinzhi[sizeerjinzhi]=B%2;
            B=B/2;
            sizeerjinzhi++;
        }
        cheng=A;
        if(erjinzhi[0]==1)
        {
            result=(result*cheng)%1000;
        }
        for(i=1;i<sizeerjinzhi;i++)
        {
            cheng=(cheng*cheng)%1000;
            if(erjinzhi[i]==1)
            {
                result=(result*cheng)%1000;
            }
        }
        printf("%d\n",result);
        scanf("%d %d",&A,&B);
    }
    return 0;
}
