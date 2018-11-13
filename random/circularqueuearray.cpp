//circular queue using arrays

#include<iostream>
using namespace std;
# define size1 5

int q[size1];
int rear=-1;
int frnt=-1;


int main()
{
    void insertqueue(int);
    void removequeue();
    void traversequeue();

    int ch;
    int item;

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
                    insertqueue(item);
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

void insertqueue(int item)
{
    if((rear+1==frnt)||(frnt==0&&rear+1==size1)  )     //frst condition for circular and second for normal
    {
        cout<<"Circular Queue Overflow\n";
    }

    else
    {
        if(frnt==-1)
        frnt=rear=0;

        else
        rear=(rear+1)%size1;

    q[rear]=item;
    cout<<item<<" is inserted\n";
    }
}

void removequeue()
{
    int num;

    if (frnt==-1)
        cout<<"Queue Underflow\n";
    else
    {
        num=q[frnt];

        if(frnt==rear)         //queue has only one element here
            frnt=rear=-1;      // queue is empty now

        else
            frnt=(frnt+1)%size1;

        cout<<num<<" is deleted\n";
    }
}

void traversequeue()
{
    int i;
    if(frnt==rear==-1)
        cout<<"Cicular queue underflow\n";

   i=frnt;
   while(1)
   {
       if(i==rear)
       {
           cout<<q[i]<<" ";
        break;
       }

       else
      {
        cout<<q[i]<<" ";

      }
        i=(i+1)%size1;
   }


    cout<<"\n";
}
