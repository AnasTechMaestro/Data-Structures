#include <iostream>
using namespace std;

class node{
	public:
		int data;
		node* left, node* right;
		int height;
		node(int data){
			this->data=data;
			left=right=NULL;
			height= 0;
		}
};

class AVLtree{
	private:
		node* root;
		node* Insert(node* root, int val);
		node* Delete(node* root, int data);
		node* PreOrderTraversal(node* root);
		node* FindMax(node* root);
		
		//Rotation
		node* singleRightRotate(node* &t);
		node* singleLefttRotate(node* &t);
		node* doubleRightLeftRotate(node* &t);
		node* doubleLeftRightRotate(node* &t);
		int getBalance(node* t);
		
		public:
			AVLTree(){
				root=NULL;
			}
			void Insert(int val){
				root=Insert(this->root,val);
			}
			void Delete(int val){
				root=Delete(this->root, val);
			}
			void PreOrderTraversal(){
				PreOrderTraversal(this->root);
			}
			int height (node*t){
				return (t==NULL? -1:t->height);
			}
			
			int length(node* r){
				int lh=0,rh=0;
				if(r==NULL)
					return -1;
					
				if(r->left!=NULL){
					lh++;
					lh+=length(r->left);
				}
				
				if(r->right!=NULL){
					rh++;
					rh+=length(r->right);
				}
				
				if(rh>lh) return rh;
				else return lh;
			}
			
			int treeHeight(node* t){
				int static l_height=0;
				int static r_height=0;
				
				if(t==NULL)
					return -1;
					
				else
				{	
					l_height= treeHeight(t->left);
					 r_height= treeHeight(t->right);
					  if(l_height>r_height)
					  	return (l_height+1);
					  else
					  	return (r_height+1);
				}
					
				
			}
};

int main()
{
	AVLTree t1,t2;
	t1 Insert(10);
	t1 Insert(8);
	t1 Insert(6);
	t1 Insert(9);
	t1 Insert(15);
	t1 Insert(14);
	t1 Insert(20);
	
	//t1.Delete(10);
	
	cout<<"PreOrder Print(Root--Left--Right"<<endl;
	t1.PreOrderTraversal();
	return 0;
	
}

node* AVLTree:: Insert(node* t, int val){
	if(t==NULL){
		t=new node(val);
	}
	
	else if (t->data==val){
		cout<<"Record exists"<<val;
	}
	
	else if (val<t->data){
		t->left=Insert(t->left,val);
		int bf= height(t->left)- height(t->right);
		if(bf==2)
		{
			if(val<t->left->data)
				t=singleRightRotate(t);
			else
				t= doubleLeftRightRotate(t);
		}
		
	}
	else if (val>t->data)
	{
		t->right=Insert(t->right, val);
		int bf= height(t->right)- height(t->left);
		if(bf==2)
		{
			if(val<t->right->data)
				t=singleLeftRotate(t);
			else
				t= doubleRightLeftRotate(t);
		}
		
	}
	t->height=max(height(t->left),height(t->right))+1;
	return t;
}

node* AVLTree:: doubleRightLeftRotate(node* &t){
	t->right= singleRightRotate(t->right);
	return singleLeftRotate(t);
}

node* AVLTree:: doubleLeftRightRotate(node* &t){
	t->left= singleLeftRotate(t->left);
	return singleRightRotate(t);
}

node* AVLTree:: singleRightRotate(node* &t){
	node* u= t->left;
	t->left=u->right;
	u->right= t;
	t->height= max(height(t->left),height(t->right))+1;
	u->height= max(height(u->left),t->height)+1;
	return u;
}

node* AVLTree:: singleLeftRotate(node* &t){
	node* u= t->right;
	t->right=u->left;
	u->left= t;
	t->height= max(height(t->left),height(t->right))+1;
	u->height= max(height(u->right),t->height)+1;
	return u;
}

