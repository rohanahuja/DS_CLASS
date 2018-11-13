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
    void add(int);
    void deleteitem();
    void traverse();

    int ch;
    int item;

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
                    add(item);
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



void add(int item)
{
    node *p;
    p=new node;
    p->info=item;
    p->next=NULL;          //bcz we need to insert always as last so next of p is always null in any case

    if(frnt==NULL)          //add frst node in queue
    {
        frnt=rear=p;
    }

    else                     //add as last node
    {
        rear->next=p;
        rear=p;             //change address at rear also
    }

    cout<<item <<" inserted \n";
}


void deleteitem()
{
    int num;
    node *p;
    if(frnt==NULL)
        cout<<"Underflow\n";

    else
    {
        if(frnt==rear)         //one node present
    {
        p=frnt;
        num=frnt->info;
        frnt=rear=NULL;
        delete p;
        cout<<num<<" is deleted\n";
    }


    else
    {
        num=frnt->info;
        p=frnt;
        frnt=frnt->next;
        delete p;
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
