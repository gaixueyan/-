#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
/*���ϵķ�����һ��ʼlow=high=m��
һ��������ÿ��low*=2��high=high*2+1��
��֮��С�ڵ���n�ľ����ӽڵ㣬һֱѭ��������Χ���ɡ�
�ҵı������������Ҫ�鷳*/
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
    int n,m;//int�ܱ�ʾ10λ������
    //intռ32λ��ʱ�������Ը�ֵΪ��2147483647����2��ͷ��ʮλ��Ŷ
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
            if(mfirst<=n && n<=mlast)//if(mfirst<=n<=mlast)���﷨����鲻�����������
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
