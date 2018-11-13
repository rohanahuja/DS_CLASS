//delete from array using number

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
    cout<<"Enter the number to delete : ";
    cin>>num;
    for(int i=0;i<s;i++)
    {
        if(a[i]==num)
        pos=i;

    }
    for(j=pos;j<s-1;j++)
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
