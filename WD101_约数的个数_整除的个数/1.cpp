//��Լ���ĸ������������Ǵ�1��nһ��һ��%
//��õİ취�����ú�sqrt(n)����1������n��������i��ƽ����n��ֻ��һ��Լ��������������Լ��
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
