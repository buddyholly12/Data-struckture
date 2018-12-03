#include<iostream>
#include<cstdlib>
using namespace std;

class binsearchtree
{
private :
	struct node
	{
		node*left;
		node*right;
		int data;
	};
	node*root;
public :
	binsearchtree()
	{
		root =NULL;
	}
	bool isEmpty()
	{
		return root==NULL;
	}
	void print_inorder()
	{
		inorder(root);
	}
	void inorder(node*dumm)
	{
		if(dumm!=NULL)
		{
			if(dumm->left)
			{
				if(dumm->left)
				{
				inorder(dumm->left);
				cout<<""<<dumm->data<<"";
				}
				if(dumm->right)
				{
				inorder(dumm->right);
				cout<<""<<dumm->data<<"";
				}
			}
		}
	}
	void print_preorder()
	{
		preorder(root);
	}
	void preorder(node*dumm1)
	{
		if(dumm1!=NULL)
		{
				cout<<""<<dumm1->data<<"";
				if(dumm1->left)
				{
				preorder(dumm1->left);
				}
				if(dumm1->right)
				{
				preorder(dumm1->right);
				}
				else 
					return;
		}
	}
	void print_postorder()
	{
		postorder(root);
	}
	void postorder(node*dumm2)
	{
		if(dumm2!=NULL)
		{
				
				if(dumm2->left)
				{
				postorder(dumm2->left);
				}
				if(dumm2->right)
				{
				postorder(dumm2->right);
				}
			cout<<""<<dumm2->data<<"";
		}
		else 
			return;


	}
	void insert (int isi)
	{
		node*x= new node;
		node* parent ;
		x->data=isi;
		x->left=NULL;
		x->right=NULL;
		parent=NULL;
		if(isEmpty())
			root=x;
		else 
		{
			node*curr;
			curr=root;
			while(curr)
			{
				parent=curr;
				if(x->data > curr->data)
					curr->right;
				else 
					curr= curr->left;
			}
			if(x->data<parent->data)
				parent->left=x;
			else 
				parent->right=x;
		}
	}
	void remove (int isi)
	{
		bool found= false;
		if(isEmpty())
		{
			cout<<"NoNe"<<endl;
			return;
		}
		node*curr;
		node*parent;
		curr=root;
		while(curr!=NULL)
		{
			if(curr->data==isi)
			{
				found=true;
				break;
			}
			else 
			{
				parent= curr;
				if(isi>curr->data)
					curr->right;
				else 
					curr->left;
			}
		}
		if(!found)
		{
		cout<<"Data not found"<<endl;
		return;
		}
		if((curr->left==NULL && curr->right!=NULL)||(curr->left!=NULL && curr->right==NULL))
		{
			if (curr->left==NULL&&curr->right!=NULL)
			{
				if (parent->left==curr)
				{
					parent->left=curr->right;
					delete curr;
				}
				else
				{
					parent->right=curr->right;
					delete curr ;
				}
			}
			else 
			{
				if (parent->left==curr)
				{
					parent->left=curr->left;
					delete curr;
				}
				else
				{
					parent->right=curr->left;
					delete curr ;
				}
			
			}
			return;
		}
		if(curr->left==NULL && curr->right!=NULL)
		{
			node*chck;
			chck->right=NULL;

		}
		else 
		{
			if((curr->right)->left!=NULL)
			{
				node*curr1;
				node*curr2;
				curr1=curr->right;
				curr2=(curr->right)->left;
				while(curr2->left!=NULL)
				{
					curr1=curr2;
					curr2=curr1->left;
				}
				curr->data=curr2->data;
				delete curr1;
				curr1->left=NULL;
			}
			else
			{
				node*tmp;
				tmp=curr->right;
				curr->data=tmp->data;
				curr->right=tmp->right;
				delete tmp;
			}
		}
		return;
	
	}	
};
void main()
{
	binsearchtree b;
	int chc=0,tmp,tmp1;
	while(1){
	cout<<endl<<endl;
       cout<<" Binary Search Tree Operations "<<endl;
       cout<<" ----------------------------- "<<endl;
       cout<<" 1. Insertion "<<endl;
       cout<<" 2. In-Order "<<endl;
       cout<<" 3. Pre-Order  "<<endl;
       cout<<" 4. Post-Order  "<<endl;
       cout<<" 5. Removal "<<endl;
       cout<<" 6. Exit "<<endl;
       cout<<" Enter your choice : ";
       cin>>chc;
	  switch(chc)
       {
           case 1 : cout<<" Enter Number to be inserted : ";
                    cin>>tmp;
                    b.insert(tmp);
                    break;
           case 2 : cout<<endl;
                    cout<<" In-Order Traversal "<<endl;
                    cout<<" -------------------"<<endl;
                    b.print_inorder();
                    break;
           case 3 : cout<<endl;
                    cout<<" Pre-Order Traversal "<<endl;
                    cout<<" -------------------"<<endl;
                    b.print_preorder();
                    break;
           case 4 : cout<<endl;
                    cout<<" Post-Order Traversal "<<endl;
                    cout<<" --------------------"<<endl;
                    b.print_postorder();
                    break;
           case 5 : cout<<" Enter data to be deleted : ";
                    cin>>tmp1;
                    b.remove(tmp1);
                    break;
           case 6 : system("pause");
                    break;
       }
	}
}
