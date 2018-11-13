// element at last

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

    while(1)
    {
        cout<<"1.add element at beginning\n";
        cout<<"2.traverse\n";
        cout<<"3.add element at last\n";
        cout<<"4.exit\n";
        cout<<"enter your choice: ";
        cin>>ch;

       if(ch==4)
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

