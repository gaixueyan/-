//求约数的个数，最好想的是从1到n一个一个%
//最好的办法是利用好sqrt(n)，从1到根号n除，其中i的平方是n的只算一个约数，其他有两个约数
#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int N;
    int n,r;
    int i,j;
    int result;
    while(scanf("%d",&N)!=EOF)
    {
        for(i=0;i<N;i++)
        {
            scanf("%d",&n);
            result=0;
            r=(int)(sqrt(n)+1);
            for(j=1;j<r;j++)
            {
                if(j*j==n)
                {
                    result++;
                }
                else if(n%j==0)
                {
                    result=result+2;
                }
            }
            printf("%d\n",result);
        }
    }
    return 0;
}
