//delete node

#include<iostream>
using namespace std;
struct node
{
    int info;
    node *ptr;
};
node *start=NULL;
int main()
{
    int ch,item;
    void addnode(int);// beginning
    void traverse();
    void addlastnode(int);
    void addinsorted(int);
    void deletefirst();
    void deletelast();
    void deleteany(int);

    while(1)
    {
        cout<<"1.add element at beginning\n";
        cout<<"2.traverse\n";
        cout<<"3.add element at last\n";
        cout<<"4.add element in sorted list\n";
        cout<<"5.delete first node\n";
        cout<<"6.delete last node\n";
        cout<<"7.delete any node\n";
        cout<<"8.exit\n";

        cout<<"enter your choice: ";
        cin>>ch;

       if(ch==8)
            break;

        switch(ch)
        {
            case 1:
                cout<<"enter item to be added : ";
                cin>>item;
                cout<<"\n";
                addnode(item);
                break;

            case 2:
                traverse();
                break;

            case 3:
                cout<<"enter item to be added : ";
                cin>>item;
                cout<<"\n";
                addlastnode(item);
                break;

            case 4:
                cout<<"enter item to be added in sorted list : ";
                cin>>item;
                cout<<"\n";
                addinsorted(item);
                break;

            case 5:
                deletefirst();
                break;

            case 6:
                deletelast();
                break;

            case 7:
                cout<<"enter item to be deleted from the list : ";
                cin>>item;
                cout<<"\n";
                deleteany(item);
                break;
        }
    }
return 0;
}

 void addnode(int item)
{
    node *p;
    p=new node;
    p->ptr=start;
    p->info=item;
    start=p;
}
 void traverse()
{
    node *head;
    head=start;
    while(head!=NULL)
    {
       cout<<head->info<<" ";
       head=head->ptr;
    }
    cout<<"\n";
}

void addlastnode(int item)
{
    node *temp, *p;
    temp=start;
    while(temp->ptr!=NULL)
    {
        temp=temp->ptr;
    }

    p=new node;
    p->ptr=NULL;
    p->info=item;
    temp->ptr=p;
}

void addinsorted(int item)
{
    node *prev, *next, *p,*temp;

    p=new node;
    p->info=item;

    prev=NULL;
    next=start;

    while(next!=NULL)
    {
        if(item>next->info)
        {
            prev=next;
            next=next->ptr;
        }

        else
            break;
    }

    if(prev!=NULL && next!=NULL)
        {
            p->ptr=next;
            prev->ptr=p;
        }
    else if(prev==NULL)
    {
        p->ptr=start;
        start=p;
    }

    else if(next==NULL)
    {
        p->ptr=NULL;
        prev->ptr=p;
    }
}

void deletefirst()
{
    node *p;
    if(start==NULL)
    {
        cout<<" The list is empty\n";
    }
    else if(start!=NULL)
    {
        p=start;
        start=start->ptr;
        delete p;
    }
}

void deletelast()
{

    node *last;
    node *secondlast;

    if(start==NULL)
    {
        cout<<" The list is empty\n";
    }

    else
    {
        secondlast=NULL;
        last = start;

    while(last->ptr!=NULL)
    {
        secondlast=last;
        last=last->ptr;
    }
    }

     if(secondlast==NULL)
     {
         start==NULL;
     }
     else
    {
        secondlast->ptr=NULL;
        delete last;
    }
}

void deleteany(int item)
{

    node *prev, *next,*temp;

    if(start==NULL)
    {
        cout<<" The list is empty\n";
    }

    else
    {

    prev=NULL;
    next=start;

    while(next->ptr!=NULL)
    {
        if(next->info==item)
        {

            break;
        }
        prev=next;
            next=next->ptr;
    }
    }

    if(next==NULL)
    {
        cout<<"Element not found in the list\n";
    }

    else
    {
        prev->ptr=next->ptr;
        delete next;
    }
}

