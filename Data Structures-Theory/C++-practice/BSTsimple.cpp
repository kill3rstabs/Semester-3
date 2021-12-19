#include <iostream>
#define SPACE 10
#include <queue>
using namespace std;
template <class t>
class TreeNode{
	private:
		t data;
		TreeNode<t>* left;
		TreeNode<t>* right;
	public:
		TreeNode():data(0),left(0),right(0){}
		TreeNode(t d):data(d),left(0),right(0){}
		template <class T> friend class BST;
};
template <class T>
class BST{		
	public:
		TreeNode<T>* root;
		BST():root(0){}
		bool isEmpty(){
			if(!root){
				return true;
			}
			return false;
		}
		void insertNode(T d){
			TreeNode<T>* n = new TreeNode<T>(d);
			if(!root){
				root = n;
				return ;
			}
			queue<TreeNode<T>*> q;
			q.push(root);
			
			while(!q.empty()){
				TreeNode<T>* temp = q.front();
				q.pop();
				if(temp->left){
					q.push(temp->left);
					
				}
				else{
					temp->left = n;
					return;
				}
				if (temp->right != NULL)
            		q.push(temp->right);
        		else {
            		temp->right = n;
            		return ;
        		}
				
				
			}
		}
		void inorderTraversal(TreeNode<T>* node) {
			if (node == NULL)
		    	return;
		  	inorderTraversal(node->left);
		  	cout << node->data << " ";
		  	inorderTraversal(node->right);
		  	
		}

void breadthFirst() {
	
 queue<TreeNode<T>*> q;
 TreeNode<T> *p = root;
	 if (p != 0) {
	 q.push(p);
		 while (!q.empty()) {
			 p = q.front();
			 
			 if (p->left != 0)
			 q.push(p->left);
			 if (p->right != 0)
			 q.push(p->right);
		 }
	 }
}
		
};
int main(){
	int option;
	BST<int> b;
	int val;
	do{
		cout<<"What operation do you wanna perform ?"
		<<endl<<"Select option number.Enter 0 to exit."<<endl;
		cout<<"1. Insert Node"<<endl;
		cout<<"2. Search Node"<<endl;
		cout<<"3. Breadth first traversal"<<endl;
		cout<<"4. Print BST values"<<endl;
		cout<<"5. Clear Screen"<<endl;
		cout<<"0. Exit Program"<<endl;
		
		cin>>option;
		
		switch(option){
			case 0:
				break;
			case 1:
				cout<<"INSERT"<<endl;
				cout<<"Enter the value of tree node to insert in bst:";
				cin>>val;
				b.insertNode(val);
				break;
			case 2:
				cout<<"SEARCH: "<<endl;
				//search code
				break;
			case 3:
				cout<<"Breadth first traversal: "<<endl;
				b.breadthFirst();
				cout<<endl;
				break;
			case 4:
				cout<<"Print and Traverse: "<<endl;
				b.inorderTraversal(b.root);
				cout<<endl;
				break;
			case 5:
				system("cls");
				//insertion code
				break;
			
		}
	}while(option!=0);
	
	
	
	return 0;
}
