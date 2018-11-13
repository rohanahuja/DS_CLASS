//circular queue using arrays

#include<iostream>
using namespace std;
# define size1 5   // priority
#define size2 10    // queue size

int q[size1][size2];
int rear[size1]={-1,-1,-1,-1,-1};
int frnt[size1]={-1,-1,-1,-1,-1};


int main()
{
    void insertqueue(int,int);
    void removequeue();
    void traversequeue();

    int ch;
    int item;
    int prior;

    cout<<"1.insert\n";
    cout<<"2.delete\n";
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
                    cout<<"Enter priority\n";
                    cin>>prior;
                    insertqueue(item,prior);
                    break;

            case 2:
                    removequeue();
                    break;

            case 3:
                    traversequeue();
                    break;
        }
    }
}

void insertqueue(int item, int p)
{
    if((rear[p]+1==frnt[p])||(frnt[p]==0&&rear[p]+1==size2)  )     //frst condition for circular and second for normal
    {
        cout<<"Circular Queue Overflow\n";
    }

    else
    {
        if(frnt[p]==-1)
        frnt[p]=rear[p]=0;

        else
        rear[p]=(rear[p]+1)%size2;

    q[p][rear[p]]=item;
    cout<<item<<" is inserted\n";
    }
}

void removequeue()
{
    int num;
    int p;
    for(p=size1-1;p>=0;p--)
    {
        if(frnt[p]!=-1)
        {
            break;

        }
    }


        num=q[p][frnt[p]];

        if(frnt[p]==rear[p])         //queue has only one element here
            frnt[p]=rear[p]=-1;      // queue is empty now

        else
            frnt[p]=(frnt[p]+1)%size2;

        cout<<num<<" is deleted\n";

}

void traversequeue()
{
    for(int p=0;p<size1;p++)
    {
        cout<<"\nElements of priority"<< p<<"\n";

        for(int i=frnt[p];1;i =(i+1)%size2)
        {

            if(i==-1)
                break;
            else
                cout<<q[p][i]<<"   ";
            if(i==rear[p])
                break;
        }
    }

}
