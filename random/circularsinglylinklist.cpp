//circular link list singly

#include<iostream>
using namespace std;

struct node
{
    int info;
    node *next;
};



node *start=NULL;
node *last=NULL;

int main()
{
    int ch,item;
    void addbeg(int);// beginning
    void traverse();
    void addlast(int);
    void deletefirst();
    void deletelast();
    void deleteany(int);


    while(1)
    {
        cout<<"1.add element at beginning\n";
        cout<<"2.add element at last\n";
        cout<<"3.traverse\n";
        cout<<"4.delete first node\n";
        cout<<"5.delete last node\n";
        cout<<"6.delete any node\n";
        cout<<"7.exit\n";

        cout<<"enter your choice: ";
        cin>>ch;

       if(ch==7)
            break;

        switch(ch)
        {
            case 1:
                cout<<"enter item to be added : ";
                cin>>item;
                cout<<"\n";
                addbeg(item);
                break;

            case 2:
                cout<<"enter item to be added : ";
                cin>>item;
                cout<<"\n";
                addlast(item);
                break;

            case 3:
                traverse();
                break;

            case 4:
                deletefirst();
                break;

            case 5:
                deletelast();
                break;

            case 6:
                cout<<"enter item to be deleted from the list : ";
                cin>>item;
                cout<<"\n";
                deleteany(item);
                break;
        }
    }
return 0;
}

void addbeg(int item)
{
    node *p;
    p=new node;
    p->info=item;

    if(start==NULL)
    {
        p->next=p;
        start=p;
        last=start;
    }
    else
    {
        p->next=start;
        start=p;
        last->next=start;
    }
}

void addlast(int item)
{
    node *p;
    p=new node;
    p->info=item;
    if(start!=NULL)
    {
        p->next=start;
        last->next=p;
        last=p;
    }

    else
    {
        addbeg(item);
    }
}

void traverse()
{
    node *t;
    t=start;
    if(start==NULL)
    {
        cout<<"empty\n";
    }

    else
    do
    {
        cout<<t->info<<" ";
        t=t->next;
        }while(t!=start);
    cout<<"\n";
}



void deletefirst()
{
    node *p;
    if(start==NULL)
        cout<<"Underflow\n";

    else
    {
        if(start==last)     //one node only
         {
            p=start;
            start=last=NULL;
            cout<<p->info<<" Deleted\n";
            delete p;
        }

        else

            {
                p=start;
                start=start->next;
                last->next=start;
                cout<<p->info<<" Deleted\n";
                delete p;
            }
    }

}


void deletelast()
{
    node *t;
    t=start;
    if(start!=last)
    {
        while(t->next!=last)
        {
            t=t->next;
        }

        t->next=start;
        cout<<last->info<<" Deleted\n";
        delete last;
        last=t;
    }
    else
    deletefirst();
}

void deleteany(int item)
{

    node *prev, *nxxt,*temp;            //used nxxt because next is ptr part of struct node

    if(start==NULL)
    {
        cout<<" The list is empty\n";
    }

    else
    {

    prev=NULL;
    nxxt=start;

    while(nxxt->next!=NULL)
    {
        if(nxxt->info==item)
        {

            break;
        }
        prev=nxxt;
            nxxt=nxxt->next;
    }
    }

    if(nxxt==NULL)
    {
        cout<<"Element not found in the list\n";
    }

    else
    {
        prev->next=nxxt->next;
        delete nxxt;
    }
}
