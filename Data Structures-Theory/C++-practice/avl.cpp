#include <iostream>
using namespace std;
template <class u>
class Node{
	private:
		u data;
		Node<u>* right;
		Node<u>* left;
	public:
		Node(u d):data(d),left(0),right(0){}
		template <class T> friend class AVL;
		
};
template <class T>
class AVL{
	private:
		
		
		//calculating the height of a node
		int height(Node<T>* n){
			int h;
			if(n==NULL){
				return 0;
			}
			int left = height(n->left);
			int right = height(n->right);
			if(left>right){
				int n = 1+left;
			}
			else{
				 h = 1+ right;
			}
			return h;
		}
		
		//helping avl functions
		Node<T>* rightRotate(Node<T>* y){
			Node<T>* x = y->left;
			Node<T>* T2 = x->right;
			x->right = y;
			y->left = T2;
			return x;
		}
		
		
		Node<T>* leftRotate(Node<T>* x){
			Node<T>* y = x->left;
			Node<T>* T2 = y->right;
			x->right = x;
			y->left = T2;
			return y;
		}
		int balanceFactor(Node<T>* n){
			if(n==NULL){
				return -1;
			}
			else{
				return(height(n->left)-height(n->right));
			}
		}
		Node<T>* minimum(Node<T>* r){
			if(r==NULL){
				return (r);
			}
			else{
				minimum(r->left);
			}
		}
	public:
		Node<T>* root;
		
		AVL():root(0){}
		//node insertion in avl
		Node<T>* insertion(Node<T>* r,T d){
			Node<T>* n = new Node<T>(d);
			if(r==NULL){
				r = n;
				return n;
			}
			if(n->data < r->data){
				r->left = insertion(r->left,d);
			}
			else if(n->data>r->data){
				r->right = insertion(r->right,d);
			}
			else{
				return r;
			}
			int bf = balanceFactor(r);
			if(bf>1 && n->data<r->left->data){
				return rightRotate(r);
			}
			if(bf<-1 && n->data > r->right->data){
				return leftRotate(r);
			}
			if(bf>1 && n->data>r->left->data){
				r->left = leftRotate(r);
				return rightRotate(r);
			}
			if(bf<-1 && n->data < r->right->data){
				r->right = rightRotate(r);
				return leftRotate(r);
			}
			return r;
			
		}
		Node<T>* deletion(Node<T>* r,T d){
			Node<T>* temp ;
			if(r==NULL){
				return r;
			}
			else if(d<r->data){
				r->left = deletion(r->left,d);
			}
			else if(d>r->data){
				r->right = deletion(r->right,d);
			}
			else{
				if(r->left == NULL){
					temp = r->right;
					delete r;
					return temp;
				}
				else if(r->right == NULL){
					temp = r->left;
					delete r;
					return temp;
				}
				else{
					temp = minimum(r->right);
					r->data = temp->data;
					r->right = deletion(r->right,temp->data);
				}
			}
			int bf = balanceFactor(r);
			if(bf==2 && balanceFactor(r->left)>=0){
				return rightRotate(r);
			}
			if(bf==2 && balanceFactor(r->left)==-1){
				r->left  = leftRotate(r->left);
				return rightRotate(r);
			}
			else if(bf == -2 && balanceFactor(r->right)<=0){
				return leftRotate(r);
			}
			else if(bf == -2 && balanceFactor(r->right)==1){
				r->right = rightRotate(r->right);
				return leftRotate(r);
			}
			
		}
		void DestroyRecursive(Node<T>* node)
		{
		    if (node)
		    {
		        DestroyRecursive(node->left);
		        DestroyRecursive(node->right);
		        delete node;
		    }
		}
		void preorder(Node<T>* r){
			if(r==NULL){
				return;
			}
			cout<<r->data<<" ";
			preorder(r->left);
			preorder(r->right);
		}
		void postorder(Node<T>* r){
			if(r==NULL){
				return;
			}
			
			postorder(r->left);
			postorder(r->right);
			cout<<r->data<<",";
		}
		void inorder(Node<T>* r){
			if(r==NULL){
				return;
			}
			
			inorder(r->left);
			cout<<r->data<<",";
			inorder(r->right);
		}
		Node<T>* search(Node<T>* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
    
	   return root;
    
    // Key is greater than root's key
    if (root->data < key)
       return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}
		
};
int main(){
	AVL<int> a;
	cout<<endl<<"Nodes after insertion: ";
	a.root = a.insertion(a.root,13);
	a.root=a.insertion(a.root,14);
	a.preorder(a.root);
	cout<<endl<<"Deleting node 13";
	a.root=a.deletion(a.root,13);
	cout<<endl;
	cout<<"perorder: ";
a.preorder(a.root);
cout<<endl<<"Postorder: ";
a.postorder(a.root);
cout<<endl<<"Inorder: ";
	a.inorder(a.root);
	cout<<endl<<"Searching 14 found at mem address: "<<a.search(a.root,14);
//	a.preorder(a.root);
	a.DestroyRecursive(a.root);
	a.postorder(a.root);
	return 0;
}
