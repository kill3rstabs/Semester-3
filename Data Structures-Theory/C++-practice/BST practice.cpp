#include <iostream>
using namespace std;
class BtNode{
	private:
		int data;
		BtNode * right;
		BtNode * left;
	public:
		BtNode(int d):data(d),right(0),left(0){}
		friend class BST;
};
class BST{
	public:
		BtNode* root;
		BST():root(0){};
		void insertNode(int d){
			BtNode* n = new BtNode(d);
			BtNode* temp = root;
			BtNode* parent = NULL;
			if(root == NULL){
				root = n;
				return;
			}
			while(temp!=NULL){
				if(temp->data>n->data){
					parent = temp;
					temp = temp->left;
				}
				else{
					parent = temp;
					temp = temp->right;
				}
			}
			if(parent->data>n->data){
				parent->left = n;
			}
			else{
				parent->right = n;
			}
		}
		BtNode* minValueNode(BtNode* node){
			BtNode* current = node;
			while(current->left!=NULL){
				current = current->left;
			}
			return current;
		}
		BtNode* deleteNode(BtNode* r,int v){
			//base case 
			if(r==NULL){
				return NULL;
			}
			else if(v<r->data){
				r->left = deleteNode(r->left,v);
			}
			else if(v>r->data){
				r->right = deleteNode(r->right,v);
			}
			else{
				if(r->left == NULL){
					BtNode* temp = r->right;
					delete r;
					return temp;
				}
				else if(r->right == NULL){
					BtNode* temp = r->left;
					delete r;
					return temp;
				}
				else{
					BtNode* temp = minValueNode(r->right);
					r->data = temp->data;
					r->right = deleteNode(r->right,temp->data);
				}
			}
			return r;
		}
		void inorder(BtNode* n){
			if(n==NULL){
				return;
			}
			inorder(n->left);
			cout<<n->data<<endl;
			inorder(n->right);
		}
};
int main(){
	BST b;
	b.insertNode(3);
	b.insertNode(4);
	b.insertNode(5);
	b.inorder(b.root);
	
	return 0;
}
