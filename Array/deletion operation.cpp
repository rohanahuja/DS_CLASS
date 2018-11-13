#include<iostream>
using namespace std;
int main()
{
	//declaration
	int n;
	cout<<"Enter the number of elements : ";
	cin>>n;
	int pos,item,i,a[n];
	//element scanning
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	//deletion of a particular element 
	cout<<"Enter the element position You want to delete : ";
	cin>>pos;
	for(i=pos;i<n;i++)
	{
		a[i-1]=a[i];
	}
	//printing
	for(i=0;i<n-1;i++)
	{
		cout<<a[i]<<" ";
	}
}
