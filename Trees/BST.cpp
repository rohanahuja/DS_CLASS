#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int info;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;

void insertion(int data)
{
    struct node *ptr;
    ptr=new node;
    ptr->info=data;
    ptr->left=NULL;
    ptr->right=NULL;
    if(root==NULL)
    {
        root=ptr;
    }
    else
    {
        struct node *temp,*prev;
        temp=root;
        while(temp!=NULL)
        {
            prev=temp;
            if(ptr->info<temp->info)
            {
                temp=temp->left;
            }
            else
            {
                temp=temp->right;
            }
        }
        if(ptr->info<prev->info)
        {
            prev->left=ptr;
        }
        else
        {
            prev->right=ptr;
        }

    }
}
void printPostorder(struct node* root)
{
    if (root != NULL)
    {
        printPostorder(root->left);
        printPostorder(root->right);
        cout << root->info << " ";
    }
}
void printPreorder(struct node* root)
{
    if (root != NULL)
    {
        cout << root->info << " ";
        printPostorder(root->left);
        printPostorder(root->right);
    }
}
void printInorder(struct node* root)
{
    if (root != NULL)
    {
        printPostorder(root->left);
        cout << root->info << " ";
        printPostorder(root->right);
    }
}
void deletion(int num)
{
    struct node *temp,*prev;
    if(root==NULL)
    {
        cout<<"Underflow";
        return;
    }
    temp=root;
    while(num!=temp->info&&temp!=NULL)
    {
        prev=temp;
        if(num<temp->info)
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }
    }
    if(temp==NULL&&num!=temp->info)
    {
        cout<<"not found";
        return;
    }
    //node with no child
    if(temp->left==NULL&&temp->right==NULL)
    {
        if(temp==root)
        {
            root=NULL;
            delete temp;
            return;
        }
        if(num<prev->info)
        {
            prev->left=NULL;
        }
        else
        {
            prev->right=NULL;
        }
    }
    //node with two children
    else if(temp->left!=NULL&&temp->right!=NULL)
    {
        struct node *base;
        base=temp;
        temp=temp->right;
        while(temp->left!=NULL)
        {
            temp=temp->left;
        }
        int num1;
        num1=temp->info;
        deletion(num1);
        base->info=num1;
    }
    //node with single child
    else
    {
        if(temp==root)
        {
            if(temp->left!=NULL)
            {
                root=temp->left;
            }
            else
            {
                root=temp->right;
            }
        }
        else
        {
            if(num<prev->info)
            {
                if(temp->left!=NULL)
                {
                    prev->left=temp->left;
                    temp->left=NULL;
                    delete temp;
                }
                else
                {
                    prev->left=temp->right;
                    temp->right=NULL;
                    delete temp;
                }
            }
            else
            {
                if(temp->left!=NULL)
                {
                    prev->right=temp->left;
                    temp->left=NULL;
                    delete temp;
                }
                else
                {
                    prev->right=temp->right;
                    temp->right=NULL;
                    delete temp;
                }
            }
        }
    }
}
int main()
{
    int c,item;
    while(1)
    {
        cout<<"\n\nenter your choice:\ncase 1-insertion\ncase 2- deletion\ncase 3-traverse\n";
        cin>>c;
        switch(c)
        {
        case 1:
            cout<<"enter item to insert: ";
            cin>>item;
            insertion(item);
            break;
        case 2:
            cout<<"enter element to delete: ";
            cin>>item;
            deletion(item);
        case 3:
            cout<<"choose traversal type:\n1- pre-order\n2- in-order\n3- post-order\n";
            cin>>c;
            switch(c)
            {
            case 1:
                printPreorder(root);
                break;
            case 2:
                printInorder(root);
                break;
            case 3:
                printPostorder(root);
                break;
            default:
                cout<<"enter correct choice!";
            }
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
