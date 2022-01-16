#include <iostream>
using namespace std;
class BtNode{
	private:
		string data;
		int qty;
		BtNode * right;
		BtNode * left;
	public:
		BtNode(string d,int q):data(d),right(0),left(0),qty(q){}
		friend class BST;
};
class BST{
	public:
		BtNode* root;
		BST():root(0){};
		void insertNode(string d,int q){
			BtNode* n = new BtNode(d,q);
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
		BtNode* OrderItem(BtNode* r,string v){
			//search for the string v if found check for the quantity,if quantity is greater
			// than zero decrement the quantity donot delete the node,else if delete the node if quantity is 0
			BtNode* temp = root;
			
			
			while(temp!=NULL){
				if(v==temp->data){
					if(temp->qty>0){
						(temp->qty)--;
						cout<<temp->qty;
					}
					else{
						goto deletion;
					}
				}
				if(v<temp->data){
					temp = temp->right;
				}
				else{
					temp = temp->left;
				}
				goto endd;
			}
				
			
			
			//base case
			deletion: 
			if(r==NULL){
				return NULL;
			}
			else if(v<r->data){
				r->left = OrderItem(r->left,v);
			}
			else if(v>r->data){
				r->right = OrderItem(r->right,v);
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
					r->right = OrderItem(r->right,temp->data);
				}
			}
			endd:
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
	b.insertNode("Desert",4);
	b.insertNode("Falunda",5);
	b.root =b.OrderItem(b.root,"Falunda");
	b.root =b.OrderItem(b.root,"Falunda");
	
	b.inorder(b.root);
	
	return 0;
}
