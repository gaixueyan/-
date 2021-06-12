#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node * left;
    Node * right;
};

Node * create(int n)
{
    Node * root = (Node *)malloc(sizeof(Node *));
    root->left = NULL;
    root->right = NULL;
    root->data = n;
    return root;
}

void zhongxu(Node * root)
{
    if(root->left != NULL)
    {
        zhongxu(root->left);
    }
    printf("%d ",root->data);
    if(root->right != NULL)
    {

        zhongxu(root->right);
    }
}

int main()
{
    int n;
    int num[105];
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    Node * root = create(num[0]);
    i=1;
    Node * p;
    while(i<n)
    {
        p=root;
        while(1)
        {
            if(num[i] < p->data && p->left!=NULL)
            {
                p=p->left;
            }
            else if(num[i] < p->data && p->left==NULL)
            {
                p->left = create(num[i]);
                break;
            }
            else if(num[i] > p->data && p->right!=NULL)
            {
                p=p->right;
            }
            else if(num[i] > p->data && p->right==NULL)
            {
                p->right = create(num[i]);
                break;
            }
        }
        i++;
    }
    zhongxu(root);
    return 0;
}
