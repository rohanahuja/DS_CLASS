//stack as linklist

#include<iostream>
using namespace std;
struct node
{
    int info;
    node *next;
};

node *top=NULL;
int main()
{
    void push(int);
    void pop();
    void traverse();

    int ch;
    int item;

    cout<<"1.Push\n";
    cout<<"2.Pop\n";
    cout<<"3.Traverse\n";
    cout<<"4.Exit\n";



    while(1)
    {
        cout<<"Enter your choice : ";
        cin>>ch;
        if (ch==4)
            break;

        switch(ch)
        {
            case 1:
                    cout<<"Enter item to be added \n";
                    cin>>item;
                    push(item);
                    break;

            case 2:
                    pop();
                    break;

            case 3:
                    traverse();
                    break;
        }
    }
}

void push(int item)
{
    node *p;
    p=new node;
    p->info=item;
    p->next=top;
    top=p;
    cout<<"\n";
}

void pop()
{
    node *p;
    if(top==NULL)
        cout<<"Underflow";

    else
        p=top;
        top=top->next;
        cout<<p->info<<" Deleted\n";
        delete p;
    cout<<"\n";
}

void traverse()
{
    node *h;
    h=top;

    while(h!=NULL)
    {
        cout<<h->info<<" ";
        h=h->next;
    }
    cout<<"\n";
}
