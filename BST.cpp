#include <iostream>
using namespace std;

class BinarySearchTree{
	private:
		class node{
		public:
		int data;
		node* left, *right;
		node(int data){
			this->data=data;
			left=right=NULL;
		}
			
		};
		
		node* root;
		node *Insert(node* root,int val);
		node *DeleteNodeInBST(node* root,int data);
		node *InorderTraversal(node* root);
		node *PreorderTraversal(node* root);
		node *PostorderTraversal(node* root);
		node *FindMax(node* root);
		
		public:
		BinarySearchTree(){
			root=NULL;
		}
		
		void Insert(int val){
			Insert(this->root, val);
		}
		
		void Delete(int val){
			DeleteNodeInBST(this->root,val);
		}
		
		void InorderTraversal(){
			InorderTraversal(this->root);
		}
		
		void PreorderTraversal(){
			PreorderTraversal(this->root);
		}
		void PostorderTraversal(){
			PostorderTraversal(this->root);
		}
};

int main(){
	BinarySearchTree tree1, tree2;
	tree1.Insert(10);
	tree1.Insert(8);
	tree1.Insert(6);
	tree1.Insert(4);
	tree1.Insert(2);
	tree1.Insert(9);
	
	tree1.delete(9);
	
	cout<<"Inorder Print(left--root--right")<<endl;
	tree1.InorderTraversal();
	cout<<"\n------"<<endl;
	cout<<"PREorder Print(root--left--right")<<endl;
	tree1.PreorderTraversal();
	cout<<"\n-----"<<endl;
	cout<<"Postorder Print(left---right---root")<<endl;
	tree1.PostorderTraversal();
	return 0;
}

node* BinarySearchTree::Insert(node* r, int val){
	if(r==NULL){
		node*t= new node(int val);
		if(r==root)
			root=t;
		else
			r=t;	
	}
	
	else if(r->data==val){
		cout<<"Record already exists"<<val;
	}
	
	else if(val<r->data){
		r->left=Insert(r->left,val);
	}
	else if(val>r->data){
		r->right=Insert(r->right,val);
		return r;
	}
	
node* BinarySearchTree::DeleteNodeInBST(node* root, int data){
	if(root==NULL)
		return root;
		
	else if(data<root->data)
		root->left=DeleteNodeInBST(root->left,data);
		
	else if(data>root->data)
		root->right=DeleteNodeInBST(root->right,data);	
		
	else{
		//NO CHILD
		if(root->right==NULL&&root->left==NULL){
			delete root;
			root==NULL;
			return root;
		}
		else if(root->right==NULL){
			node* temp=root;
			root=root->left;
			delete temp;
		}
		
		else if(root->left==NULL){
			node* temp=root;
			root=root->right;
			delete temp;
		}
		
		else
		{
			node* temp= FindMax(root->left);
			root->data= temp->data;
			root->left= DeleteNodeInBST(root->left,temp->data);
		}
	}
	return root;
}

node* BinarySearchTree::InorderTraversal(node*r){
	if(r==NULL)
		return NULL;
		
		//first recur on left child
	InorderTraversal(r->left);
	//then print data of node
	cout<< ""<<r->data<<"->";
	//NOW RECUR ON RIGHT CHILD
	InorderTraversal(r->right);
}
}
