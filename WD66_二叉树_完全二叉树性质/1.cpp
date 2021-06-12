#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
/*网上的方法：一开始low=high=m，
一层层遍历，每次low*=2，high=high*2+1，
这之间小于等于n的就是子节点，一直循环到超范围即可。
我的比这个操作起来要麻烦*/
int suanhang(int n)
{
    int i;
    int result=1;
    for(i=1; i<n; i++)
    {
        result=result*2;
        if(result-1>=n)
        {
            break;
        }
    }
    return i;
}

int main()
{
    int n,m;//int能表示10位数的数
    //int占32位的时候，最大可以赋值为：2147483647，是2开头的十位数哦
    int mhang,nhang;
    int result=0;
    int mfirst,mlast;
    int i;
    scanf("%d %d",&m,&n);
    while(n!=0 || m!=0)
    {
        mhang=suanhang(m);
        nhang=suanhang(n);
        if(nhang==mhang)
        {
            printf("1\n");
        }
        else
        {
            mfirst=m;
            mlast=m;
            result=pow(2,(nhang-mhang))-1;
            for(i=0; i<nhang-mhang; i++)
            {
                mfirst=mfirst*2;
            }
            for(i=0; i<nhang-mhang; i++)
            {
                mlast=mlast*2+1;
            }
            if(mfirst<=n && n<=mlast)//if(mfirst<=n<=mlast)的语法错，检查不出来，结果错
            {
                result=result+n-mfirst+1;
            }
            else if(n>mlast)
            {
                result=result+mlast-mfirst+1;
            }
            printf("%d\n",result);
        }
        scanf("%d %d",&m,&n);
    }
    return 0;
}
