#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ostream>
using namespace std;

int treebuf[1005];

int main()
{
    int n;
    int i;
    int d;
    int qinum,zhongnum;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&treebuf[i]);
        }
        scanf("%d",&d);
        qinum=pow(2,(d-1));
        zhongnum=pow(2,d)-1;
        if(qinum>n)
        {
            printf("EMPTY\n");
        }
        else if(n>=zhongnum)
        {
            for(i=qinum;i<zhongnum;i++)
            {
                printf("%d ",treebuf[i]);
            }
            printf("%d\n",treebuf[i]);
        }
        else
        {
            for(i=qinum;i<n;i++)
            {
                printf("%d ",treebuf[i]);
            }
            printf("%d\n",treebuf[i]);
        }
    }
    return 0;
}
