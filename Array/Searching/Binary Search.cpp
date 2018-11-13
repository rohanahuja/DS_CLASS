#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter the number of elements";
	cin>>n;
	int item,mid,i,j,beg=0,end,a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	end=n-1;
	mid=(beg+end)/2;
	cout<<"Enter the element to search : ";
	cin>>item;
	while(a[mid]!=item && beg<=end)
	{
		if(item>a[mid])
		{
			beg=mid+1;
			mid=(beg+end)/2;
		}
		else
		{
			end=mid-1;
			mid=(beg+end)/2;
		}
		
		
		}
		if(a[mid]==item)
		{
			cout<<"item found";
		}
		else
		cout<<"not found";	
	
}
