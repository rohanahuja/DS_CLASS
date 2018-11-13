//queue as linklist

#include<iostream>
using namespace std;
struct node
{
    int info;
    node *next;
};

node *frnt=NULL;
node *rear=NULL;
int main()
{
    void insertf(int);
    void inserte(int);
    void deletef();
    void deletee();
    void traverse();

    int ch;
    int item;

    cout<<"1.insert element at front\n";
    cout<<"2.insert element at last\n";
    cout<<"3.delete first element\n";
    cout<<"4.delete last element\n";
    cout<<"5.traverse \n";
    cout<<"6.exit\n";


    while(1)
    {
        cout<<"Enter your choice : ";
        cin>>ch;
        if (ch==6)
            break;

        switch(ch)
        {
            case 1:
                    cout<<"Enter item to be added \n";
                    cin>>item;
                    insertf(item);
                    break;

            case 2:
                    cout<<"Enter item to be added \n";
                    cin>>item;
                    inserte(item);
                    break;

            case 3:
                    deletef();
                    break;

            case 4:
                    deletee();
                    break;

            case 5:
                    traverse();
                    break;
        }
    }
}



void insertf(int item)
{
    node *p;
    p=new node;
    p->info=item;

    if(frnt==NULL)          //add frst node in queue
    {
        frnt=rear=p;
        p->next=NULL;
    }

    else
    {
        p->next=frnt;
        frnt=p;
    }
    cout<<item <<" inserted \n";
}

void inserte(int item)
{
    node *p;
    p=new node;
    p->info=item;


    if(frnt==NULL)          //add frst node in queue
    {
        frnt=rear=p;
        p->next=NULL;
    }

    else                     //add as last node
    {
        p->next=NULL;
        rear->next=p;
        rear=p;             //change address of rear also
    }
    cout<<item <<" inserted \n";
}

void deletef()
{

    if(frnt==NULL)
        cout<<"Underflow\n";

    else
    {
        int num;
        node *p;
        num=frnt->info;
        p=frnt;

        if(frnt==rear)         //one node present
    {
        frnt=rear=NULL;
        delete p;
        cout<<num<<" is deleted\n";
    }

    else
    {
        frnt=frnt->next;
        delete p;
        cout<<num<<" is deleted\n";
    }
    }
}


void deletee()
{

    if(frnt==NULL)
        cout<<"Underflow\n";

    else
    {
        int num;
        node *p;


        if(frnt==rear)         //one node present
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
        while(p->next!=rear)
            p=p->next;

        p->next=NULL;

        num=rear->info;
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
