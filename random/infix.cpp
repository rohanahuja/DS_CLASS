#include<iostream>
#include<string.h>
using namespace std;
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
int main()
{
    char infix[100];
    cout<<"Enter infix expression : ";
    cin.getline(infix,100);

    Tokenize t = Tokenize(infix);
    cout<<"Token 1 : "<<t.nextToken()<<endl;
    cout<<"Token 2 : "<<t.nextToken()<<endl;
    cout<<"Token 3 : "<<t.nextToken()<<endl;
    cout<<"Token 4 : "<<t.nextToken()<<endl;
    cout<<"Token 5 : "<<t.nextToken()<<endl;
    cout<<"Token 6 : "<<t.nextToken()<<endl;
    cout<<"Token 7 : "<<t.nextToken()<<endl;
    return 0;
}
