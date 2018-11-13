#include<iostream>
#include<string.h>
using namespace std;
# define size1 5
char s[size1];
int top=-1;
char token[30];

class Tokenize
{
    private:
    char e[100];
    int l;

    public:
    Tokenize(char exp[100])
    {
        strcpy(e,exp);
        l=0;
    }

    char *nextToken()
    {


        int i=0;
        if(e[l]=='+'||e[l]=='-'||e[l]=='*'||e[l]=='/'||e[l]=='%'||e[l]=='('||e[l]==')')
        {
            token[i]=e[l];
            token[i+1]='\0';
            l++;
        }

        else
        {
            while(e[l]>='0'&&e[l]<='9')
            {
                token[i]=e[l];
                i++;
                l++;
            }
            token[i]='\0';
        }
        return (token);
    }
};

class operator1
{
    char op[5];
    int priority[5];
    public:
    operator1()
    {
        strcpy(op,"+-*/%");
        priority[0]=0;
        priority[1]=0;
        priority[2]=1;
        priority[3]=1;
        priority[4]=1;
    }

    int getPriority(char s)
    {
        int i=0;
        while(i<=4)
        {
            if(s==op[i])
            {
                return priority[i];

            }
            i++;

        }
        return -1;
    }
};

int main()
{
    operator1 o;
    void push(char );
    int pop();
    char getTopElement();
    void add(char *,char);
    char k[10],d;
    int leni;
    char infix[100];
    char p[100];
    p[0]='\0';
    cout<<"Enter infix expression :";
    cin.getline(infix,100);

    leni=strlen(infix);
    infix[leni]=')';
    infix[leni+1]='\0';
    push('(');


    // cout<<infix<<endl;
    // cout<<s<<endl;

    Tokenize t=Tokenize(infix);
    strcpy(k,t.nextToken());


    // cout<<k<<endl;


    while(k[0]!='\0')
    {
        if(k[0]=='(')
            push(k[0]);
        if(k[0]>='0'&&k[0]<='9')
            {
                if(strlen(p)!=0)        //to add comma separator after first element
                    add(p,',');
                strcat(p,k);
                // cout<<p<<endl;
            }
        if(k[0]==')')
            {
                while((d=pop())!='(')
                {
                    add(p,',');     //add separator
                    add(p,d);
                }
            }
        if(k[0]=='+'||k[0]=='-'||k[0]=='*'||k[0]=='/'||k[0]=='%')
        {
            char ch;
            ch=getTopElement();

            //cout<<ch;

            while(o.getPriority(ch)>=o.getPriority(k[0]))
            {
                ch=pop();
                add(p,',');     //add separator
                add(p,ch);
                ch=getTopElement();
            }
            push(k[0]);
        }
        strcpy(k,t.nextToken());

        //cout<< k << "token"<<endl;
    }
    cout<<"The postfix expression is : "<<p<<endl;


    //evaluation of postfix expression
    int i,v,a,b,c;
    for(i=0;p[i]!='\0';i++)
    {
        if(p[i]==',')
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
                string d="";
                while(p[i]!=',')
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
void push(char item)
{
    if(top+1==size1)
        cout<<"Stack Overflow\n";

    else
    {
        top++;
        s[top]=item;
       // cout<<item<< " pushed\n";
    }
}

int pop()
{
    char num;

    if (top==-1)
        cout<<"Stack Underflow\n";
    else
    {
        num=s[top];
        top--;
    }
    return num;
}

char getTopElement()
{
    return (s[top]);
}

void add(char *a, char c)
{
  int i=strlen(a);
  a[i]=c;
  a[i+1]='\0';
}
