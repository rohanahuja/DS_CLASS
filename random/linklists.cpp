#include<iostream>
using namespace std;
class link
{
	struct node
	{
		int value;
		struct node*next;
	};
	int num,h=0;
	struct node*start;
	struct node*save;
	struct node*new_node;
	public:
		link()
		{
			start=NULL;
		}
		void create()
		{
			cout<<"Enter elemenet at begining or at end ?\n 1.Begining\n 2.End\n3. Dont enter\n";
			cin>>h;
			while(h!=3)
			{
			if(h==1)
			{
				cout<<"Enter element";
			cin>>num;
			//cin>>num;
			while(num>=0)
			{
			new_node=new node;
			new_node->value=num;
			new_node->next=start;
			start=new_node;
			save=new_node;
			cout<<"Enter Element\n";
			cin>>num;
			}
		}
		else if(h==2)
		{
			cout<<"Enter Element\n";
			cin>>num;
			while(num>=1)
			{
				new_node=new node;
				new_node->value=num;
				new_node->next=NULL;
				save->next=new_node;
				save=new_node;
			cout<<"Enter Element\n";
			cin>>num;
				
			}
			
		}
		cout<<"Enter elemenet at begining or at end ?\n 1.Begining\n 2.End\n3. Dont enter\n";
			cin>>h;
	}
	}
		void display()
		{
			struct node *ptr;
			ptr=start;
			cout<<"Elements in list are:-\n";
			while(ptr!=NULL)
			{
				cout<<ptr->value<<"\n";
				ptr=ptr->next;
			}
		//	cout<<"jhjhkn";
		}
};
int main()
{
	link obj;
	obj.create();
	obj.display();
	return 0;
}
