//stacks using arrays

#include<iostream>
using namespace std;
# define size1 5

int s[size1];
int top=-1;


int main()
{
    void push(int);
    void pop();
    void traverse();

    int ch;
    int item;

    cout<<"1.Push\n";
    cout<<"2.Pop\n";
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
                    push(item);
                    break;

            case 2:
                    pop();
                    break;

            case 3:
                    traverse();
                    break;
        }
    }
}

void push(int item)
{
    if(top+1==size1)
        cout<<"Stack Overflow\n";

    else
    {
        top++;
        s[top]=item;
        cout<<"Item pushed in stack\n";
    }
    cout<<"\n";
}

void pop()
{
    int num;

    if (top==-1)
        cout<<"Stack Underflow\n";
    else
    {
        num=s[top];
        top--;
        cout<<num<<" is popped\n";
    }
    cout<<"\n";
}

void traverse()
{
    if (top==-1)
        cout<<"Stack Underflow\n";

    for(int i=0;i<=top;i++)
    {
        cout<<s[i]<<" ";
    }
    cout<<"\n";

}
