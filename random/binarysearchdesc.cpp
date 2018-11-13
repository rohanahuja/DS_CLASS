//binary search descending order

#include<iostream>
using namespace std;

int main()
{
    int a[20];
    int s;
    int beg,end,mid,num;
    int i;

    cout<<"Enter size of array :";
    cin>>s;
    cout<<"Enter array in descending order : ";
    for(i=0;i<s;i++)
    {
        cin>>a[i];
    }

    cout<<"The array is : ";
    cout<<"\n";
    for(i=0;i<s;i++)
    {
        cout<<a[i]<<"\n";
    }

    cout<<"Enter number to be searched : ";
    cin>>num;

    beg=0;
    end=s-1;
    mid=(beg+end)/2;

    while(beg<=end)
    {
        if(a[mid]==num)
        {
            cout<<"search successful";
            cout<<" element found at "<<mid+1<<" position";
            break;
        }

        if(num>a[mid])
        {
            end=mid-1;
        }
        else
            beg=mid+1;

        mid=(beg+end)/2;
    }

    if(beg>end)
    {
        cout<<"search not completed\n";
    }

    return 0;
    }

