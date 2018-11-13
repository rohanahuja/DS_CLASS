//duplicate

#include<iostream>
using namespace std;

int main()
{
    int a[5];
    for(int i=0;i<5;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<5;i++)
    {
        for(int j=i+1;j<5;j++)
        {
            if(a[i]==a[j])
                a[j]=-1;
        }
    }

    for(int i=0;i<5;i++)
    {
        if(a[i]>0)
        cout<<a[i];
    }
}
