//delete from array
#include<iostream>
using namespace std;
main()
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
    cout<<"Enter the position where u want to delete number : ";
    cin>>pos;
    for(j=pos-1;j<s-1;j++)
    {
        a[j]=a[j+1];
    }
    s=s-1;
    cout<<"Array after deletion is :";
    for(j=0;j<s;j++)
    {
        cout<<a[j];
    }
}
