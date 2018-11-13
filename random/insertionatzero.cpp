//insertion at zero position

#include<iostream>
using namespace std;

int main()
{
    int a[20];
    int num,s;
    int pos;
    int j;
    cout<<"Enter size of array :";
    cin>>s;
    for(int i=0;i<s;i++)
    {
        cin>>a[i];
    }
    pos=0;
    cout<<"Enter the number to be added : ";
    cin>>num;

    for(j=s-1;j>=0;j--)
    {
        a[j+1]=a[j];
    }
    a[0]=num;

    cout<<"Array after shifting and insertion is :";
    for(j=0;j<=s;j++)
    {
        cout<<a[j]<<" " ;
    }
    return 0;
}
