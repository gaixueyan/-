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
        /*pow函数返回的是double型的结果，(int)转换是直接截取整数部分，pow(10,2)=99.9999999变成了99，
        结果出错。解决方法：1自己编返回int的pow。2(int)round(pow(10,2))，用四舍五入函数。
        3(int)(pow(10,2)+0.5)，加0.5,简易版四舍五入*/

        if(a1 == b1)//%前后的必须是int型的，不是的话报错，所以没把握就强制转换
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
