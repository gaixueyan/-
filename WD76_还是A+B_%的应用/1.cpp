#include<stdio.h>
#include<iostream>
using namespace std;
#include<math.h>

int main()
{
    int a,b,k;
    int a1,b1;
    int sum;
    scanf("%d %d %d",&a,&b,&k);
    while(a!=0 && b!=0)
    {
        sum=0;
        a1=a% (int)(pow(10,k)+0.5);
        b1=b% (int)(pow(10,k)+0.5);
        //printf("pow= %d",(int)pow(10,k));
        /*pow�������ص���double�͵Ľ����(int)ת����ֱ�ӽ�ȡ�������֣�pow(10,2)=99.9999999�����99��
        ����������������1�Լ��෵��int��pow��2(int)round(pow(10,2))�����������뺯����
        3(int)(pow(10,2)+0.5)����0.5,���װ���������*/

        if(a1 == b1)//%ǰ��ı�����int�͵ģ����ǵĻ���������û���վ�ǿ��ת��
        {
            printf("-1\n");
        }
        else
        {
            sum=a+b;
            printf("%d\n",sum);
        }
        scanf("%d %d %d",&a,&b,&k);
    }
    return 0;
}
