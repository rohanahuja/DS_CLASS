//insertion in an array

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
    cout<<"Enter the position where u want to add number : ";
    cin>>pos;

    cout<<"Enter the number to be added : ";
    cin>>num;

    for(j=s-1;j>=pos-1;j--)
    {
        a[j+1]=a[j];
    }
    a[j+1]=num;

    cout<<"Array after shifting and insertion is :";
    for(j=0;j<=s;j++)
    {
        cout<<a[j];
    }
    return 0;
}
