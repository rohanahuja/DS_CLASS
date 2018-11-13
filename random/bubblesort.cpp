//bubble sort

#include<iostream>
using namespace std;

int main()
{
    int a[20];
    int s;
    int temp;
    int i,j;

    cout<<"Enter size of array :";
    cin>>s;
    cout<<"Enter array ";
    for(i=0;i<s;i++)
    {
        cin>>a[i];
    }

    cout<<"The array before sorting is : ";
    cout<<"\n";
    for(i=0;i<s;i++)
    {
        cout<<a[i]<<"\n";
    }

    for(i=1;i<s;i++)
    {

    for(j=0;j<s-i;j++)
    {
        if(a[j]>a[j+1])
        {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
    }
    }
    cout<<"The array after sorting is : ";
    cout<<"\n";
    for(i=0;i<s;i++)
    {
        cout<<a[i]<<"\n";
    }

    return 0;
    }
