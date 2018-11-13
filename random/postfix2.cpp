#include<iostream>
#include<string.h>
using namespace std;
#define size1 100

int s[size1];
int top=-1;

int main()
{
    void push(int);
    int pop();
    void traverse();

    int i,v,a,b,c;
    char p[200];
    cout<<"Enter postfix expression with spaces\n";
    cin.getline(p,200);
    for(i=0;p[i]!='\0';i++)
    {
        if(p[i]==' ')
        continue;

        else
        {
            if(p[i]=='+'||p[i]=='-'||p[i]=='*'||p[i]=='/'||p[i]=='%')
            {
                a=pop();
                b=pop();
                if(p[i]=='+')
                {
                    c=b+a;
                }
                if(p[i]=='-')
                {
                    c=b-a;
                }
                if(p[i]=='*')
                {
                    c=b*a;
                }
                if(p[i]=='/')
                {
                    c=b/a;
                }
                if(p[i]=='%')
                {
                    c=b%a;
                }
                push(c);
            }
            else
            {
                int num=0;

                while(p[i]!=' ')
                {
                    num=(num*10) + (p[i]-'0');
                    i++;
                }
                push(num);
            }
        }
    }
    v=pop();
    cout<<"Result is : "<<v;
return 0;
}
void push(int item)
{
    if(top+1==size1)
        cout<<"Stack Overflow\n";

    else
    {
        top++;
        s[top]=item;
    }
}

int pop()
{
    int num;

    if (top==-1)
        cout<<"Stack Underflow\n";
    else
    {
        num=s[top];
        top--;
    }
    return num;
}
