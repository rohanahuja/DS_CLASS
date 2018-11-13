//link list menu driven

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
    void addnode(int);
    void traverse();

    while(1)
    {
        cout<<"1.add\n";
        cout<<"2.traverse\n";
        cout<<"3.exit\n";

        cout<<"enter your choice: ";
        cin>>ch;

        if(ch==3)
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
        }

        if(ch==3)
            break;
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

