#include<iostream>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};
node *root=NULL;

class tree
{
	public:
		void insert(int);
		void preorder(node *);
		void inorder(node *);
		void postorder(node *);
		struct node* Delete(node *, int );
		node* FindMin(node*);
};

void tree::insert(int d)
{
   node *ptr=new node;
   ptr->data=d;
   ptr->left=NULL;
   ptr->right=NULL;
   if(root==NULL)
   {
    root=ptr;
   	return;
   }
   node *temp=root;

   while(1)
   {
    if(ptr->data<temp->data)
    {
        if(temp->left)
        temp=temp->left;
     else
     {
        temp->left=ptr;
        break;
     }
    }
    else{
            if(temp->right)
            {
                temp=temp->right;
            }
		    else
		    {
		        temp->right=ptr;
                break;
            }
         }
    }

}


node* tree::FindMin(node* root)
{
  while(root->left != NULL) root = root->left;
  return root;
}

node* tree::Delete(struct node *root, int data)
{
  if(root == NULL) return root;
  else if(data < root->data) root->left = Delete(root->left,data);
  else if(data > root->data) root->right = Delete(root->right, data);
  else {
    // Case 1: No Child
    if(root->left == NULL && root->right == NULL){
      delete root;
      root = NULL;
    // Case 2: one child
    } else if(root->left == NULL){
      struct node *temp = root;
      root = root->right;
      delete temp;
    } else if(root->right == NULL){
      struct node *temp = root;
      root = root->left;
      delete temp;
    } else{
      struct node *temp = FindMin(root->right);
      root->data = temp->data;
      root->right = Delete(root->right, temp->data);
    }
  }
  return root;
}

void tree::inorder(node *root)
{
    node *temp=root;
    if(root == NULL) return;

    if(temp!=NULL)
	{

		inorder(temp->left);
		cout<<temp->data<<" ";
		inorder(temp->right);
	}
}

void tree::preorder(node* root)
{
	node *temp=root;
	if(temp==NULL)
    {
		return;
	}
	if(temp!=NULL)
	{
		cout<<temp->data<<" ";
		preorder(temp->left);
		preorder(temp->right);
	}
}
void tree::postorder(node* root)
{
	node *temp=root;
	if(temp==NULL)
    {
		return;
	}
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		cout<<temp->data<<" ";
	}
}

main()
{
	tree t;
	int n,d,del;
	cout<<"Enter no.of nodes"<<endl;
	cin>>n;
	cout<<"Enter the data"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>d;
		t.insert(d);
	}
	cout<<"PreOrder of tree is: ";
	t.preorder(root);
	cout<<endl;
	cout<<"InOrder of tree is: ";
	t.inorder(root);
	cout<<endl;
	cout<<"PostOrder of tree is: ";
	t.postorder(root);
	cout<<endl;
	cout<<"Enter the data to be deleted : ";
	cin>>del;
	t.Delete(root,del);
	cout<<"Pre Order of tree after deletion : ";
	t.preorder(root);
}
