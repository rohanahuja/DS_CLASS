#include<iostream>
using namespace std;
int main()
{
	//declaration
	int n;
	cout<<"Enter Number of elements in array : ";
	cin>>n;
	int pos,item,i,a[n];
	//scanning of elements
	for(i=0;i<n;i++)
	{
		cin>>a[i];	
	}	
	//insertion
	cout<<"Enter the value to be inserted : ";
	cin>>item;
	cout<<"\nEnter the postion : ";
	cin>>pos;
	pos=pos-1;
	for(i=n;i>pos;i--)
	{
		a[i]=a[i-1];
	}
	a[pos]=item;
	//printing the array
	for(i=0;i<n+1;i++)
	{
		cout<<a[i]<<" ";
	}
	
}
