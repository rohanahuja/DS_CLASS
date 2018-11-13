#include<iostream>
using namespace std;
int main()
{
	int i,j,n;
	cout<<"Enter the number of elements : ";
	cin>>n;
	int a[n],temp;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	//bubble sorting 
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	//printing
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	
}
