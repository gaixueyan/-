#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int n;
int tree[30];
void init()
{
    for(int i=0;i<30;i++)
    {
        tree[i]=-1;
    }
}
struct Bian
{
    int qi;
    int zhi;
    int chang;
}bian[500];
int sizebian;
bool cmp(struct Bian a,struct Bian b)
{
    if(a.chang<=b.chang)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool liantong()
{
    int sum=0;
    int i;
    for(i=0;i<n;i++)
    {
        if(tree[i]==-1)
        {
            sum++;
        }
    }
    if(sum==1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int findroot(int a)
{
    if(tree[a]==-1)
    {
        return a;
    }
    else
    {
        int root;
        root=findroot(tree[a]);
        tree[a]=root;
        return root;
    }
}

int main()
{
    int i,j;
    char qi,zhi;
    int lianjie;
    while(scanf("%d",&n)!=EOF && n!=0)
    {
        init();
        sizebian=0;
        for(i=0;i<n-1;i++)
        {
            getchar();
            //scanf("%c",&qi);
            //scanf("%d",&lianjie);
            cin>>qi>>lianjie;//cin适用于输入单个字符
            for(j=0;j<lianjie;j++)
            {
                //scanf("%c",&zhi);
                //scanf("%d",bian[sizebian].chang);
                cin>>zhi>>bian[sizebian].chang;
                bian[sizebian].qi=qi-'A';
                bian[sizebian].zhi=zhi-'A';
                sizebian++;
            }
        }
        sort(bian,bian+sizebian,cmp);
        int roota,rootb;
        i=0;
        int result=0;
        while(!liantong())
        {
            roota=findroot(bian[i].qi);
            rootb=findroot(bian[i].zhi);
            if(roota!=rootb)
            {
                tree[rootb]=roota;
                result=result+bian[i].chang;
            }
            i++;
        }
        printf("%d\n",result);
    }
    return 0;
}
