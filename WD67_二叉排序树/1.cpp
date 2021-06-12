#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct Tree
{
    struct Tree * left;
    struct Tree * right;
    int data;
};

struct Tree * creat(int r)
{
    struct Tree * root=(struct Tree *)malloc(sizeof(struct Tree));
    root->left=NULL;
    root->right=NULL;
    root->data=r;
    return root;
}

void deletetree(struct Tree * root)
{
    if(root->left!=NULL)
    {
        deletetree(root->left);
    }
    if(root->right!=NULL)
    {
        deletetree(root->right);
    }
    free(root);
}

void qianbian(struct Tree * root)
{
    printf("%d ",root->data);
    if(root->left!=NULL)
    {
        qianbian(root->left);
    }
    if(root->right!=NULL)
    {
        qianbian(root->right);
    }
}

void zhongbian(struct Tree * root)
{
    if(root->left!=NULL)
    {
        zhongbian(root->left);
    }
    printf("%d ",root->data);
    if(root->right!=NULL)
    {
        zhongbian(root->right);
    }
}

void houbian(struct Tree * root)
{
    if(root->left!=NULL)
    {
        houbian(root->left);
    }
    if(root->right!=NULL)
    {
        houbian(root->right);
    }
    printf("%d ",root->data);
}

struct Tree * creatpai(struct Tree * root,int r)
{
    if(root==NULL)
    {
        root=creat(r);
    }
    else if(root->data>r)
    {
        root->left=creatpai(root->left,r);//root->left=递归函数(root->left),不知道为啥，不返回就传丢，这个结点还是空
    }
    else if(root->data<r)
    {
        root->right=creatpai(root->right,r);
    }
    return root;//必须返回root，在主函数接收，否则主函数传丢，为空
}

int main()
{
    int n;
    int r;
    int i;
    while(scanf("%d",&n)!=EOF)
    {
        struct Tree * root=NULL;
        for(i=0;i<n;i++)
        {
            scanf("%d",&r);
            root=creatpai(root,r);//递归中传参特别注意
        }
        qianbian(root);
        printf("\n");
        zhongbian(root);
        printf("\n");
        houbian(root);
        printf("\n");
        deletetree(root);
    }
    return 0;
}
