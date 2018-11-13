//doubly link list insertion beg end middle traverse beg traverse end
//deletion

#include<iostream>
using namespace std;
struct Dnode
{
    Dnode *b;
    int info;
    Dnode *f;
};
Dnode *head, *tail;
int main()
{
    int ch,item;
    void insertbeg(int);// beginning
    void insertend(int);
    void insertmiddle(int);
    void traversebeg();
    void traverseend();
    void deletefirst();
    void deletelast();


    while(1)
    {
        cout<<"1.add element at beginning\n";
        cout<<"2.insert at end\n";
        cout<<"3.insert in middle of sorted list\n";
        cout<<"4.traverse from beginning\n";
        cout<<"5.traverse from last\n";
        cout<<"6.delete first node\n";
        cout<<"7.delete last node\n";

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
                insertbeg(item);
                break;

            case 2:
                cout<<"enter item to be added : ";
                cin>>item;
                cout<<"\n";
                insertend(item);
                break;

            case 3:
                cout<<"enter item to be added in sorted list: ";
                cin>>item;
                cout<<"\n";
                insertmiddle(item);
                break;

            case 4:
                traversebeg();
                break;

            case 5:
                traverseend();
                break;

            case 6:
                deletefirst();
                break;

            case 7:
                deletelast();
                break;


        }
    }
return 0;
}

void insertbeg(int item)
{
    Dnode *t;
    t=new Dnode;
    t->info=item;

    if(head==NULL)
    {
        t->f=NULL;
        t->b=NULL;
        head=t;
        tail=t;
    }

    else
    {
        t->b=NULL;
        t->f=head;
        head->b=t;
        head=t;
    }
}

void insertend(int item)
{
    Dnode *t;
    t=new Dnode;
    t->info=item;

    if(head==NULL)
    {
        t->f=NULL;
        t->b=NULL;
        head=t;
        tail=t;
    }
    else
    {
            t->f=NULL;
            tail->f=t;
            t->b=tail;
            tail=t;
    }
}

void insertmiddle(int item)
{
    Dnode *t,*next;
    t=new Dnode;
    t->info=item;

    next=head;

   while(next!=NULL)
    {
        if(item>next->info) //another method for if in notes..
        {
            next=next->f;
        }
        else
            break;
    }

    if(next==NULL)
        insertend(item);

    else if(next==head)
        insertbeg(item);

    else
    {
        t->f=next;
        t->b=next->b;
        (next->b)->f=t;
        next->b=t;
    }
}

void traversebeg()
{
    Dnode *h;
    h=head;
    while(h!=NULL)
    {
        cout<<h->info<<" ";
        h=h->f;
    }
    cout<<"\n";
}

void traverseend()
{
    Dnode *t;
    t=tail;
    while(t!=NULL)
    {
        cout<<t->info<<" ";
        t=t->b;
    }
    cout<<"\n";
}

void deletefirst()
{
    Dnode *next;
    int num;

    //num=head->info;  //cant be written here because if list is empty it will not execute

    if(head==NULL&&tail==NULL)
    {
        cout<<"Underflow\n";
    }

    else if(head==tail)
    {
        num=head->info;

        next=head;
        head=tail=NULL;
        delete next;
        cout<<num<<" is deleted\n";
    }

    else
    {

        num=head->info;

        next=head;
        head=head->f;
        head->b=NULL;
        delete next;
        cout<<num<<" is deleted\n";
    }
}

void deletelast()
{
    Dnode *next;
    int num;


    if(tail==NULL)
    {
        cout<<"The list is empty\n";
    }

    else
        {
            if(head==tail)      // if  only one element is present
            {
                num=tail->info;

                next=tail;
                head=tail=NULL;
                delete next;
                cout<<num<<" is deleted\n";
            }

            else
            {
                num=tail->info;

                next=tail;      //address of last node in next
                tail=tail->b;
                tail->f=NULL;
                delete next;
                cout<<num<<" is deleted\n";
            }


        }
}

