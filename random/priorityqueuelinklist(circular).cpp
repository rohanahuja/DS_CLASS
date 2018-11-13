//priority queue as circular queue as linklist

#include<iostream>
using namespace std;
struct node
{
    int info;
    node *next;
    int priority;
};

node *frnt=NULL;
node *rear=NULL;
int main()
{
    void add(int,int);
    void deleteitem();
    void traverse();

    int ch;
    int item;
    int prior;

    cout<<"1.Add\n";
    cout<<"2.Delete\n";
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
                    cout<<"Enter priority \n";
                    cin>>prior;
                    add(item,prior);
                    break;

            case 2:
                    deleteitem();
                    break;

            case 3:
                    traverse();
                    break;
        }
    }
}

void add(int item,int prior)
{
    node *p,*temp;
    p=new node;
    p->info=item;
    p->priority=prior;

    if(frnt==NULL || prior<(frnt->priority) )         //add as frst node in queue
    {
        p->next=frnt;
        frnt=p;
    }

    else                                                //add as last node
    {
        temp=frnt;

        while(temp->next!=NULL && temp->next->priority<=prior)
        {
            temp=temp->next;
        }
        p->next=temp->next;
        temp->next=p;
    }
    cout<<item <<" inserted \n";
}
void deleteitem()
{
    if(frnt==NULL)
        cout<<"Underflow\n";

    else
    {
        int num;
        node *p;

        if(frnt->next==NULL)         //one node present
    {
        num=frnt->info;
        p=frnt;
        frnt=rear=NULL;
        delete p;
        cout<<num<<" is deleted\n";
    }

    else
    {
        p=frnt;
        while(p->next->next!=NULL)
            p=p->next;

            num=p->next->info;
        p->next=NULL;

        delete rear;
        rear=p;
        cout<<num<<" is deleted\n";
    }
    }
}

 void traverse()
{
    node *h;
    h=frnt;
    while(h!=NULL)
    {
       cout<<h->info<<" ";
       h=h->next;
    }
    cout<<"\n";
}
