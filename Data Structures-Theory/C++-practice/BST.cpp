#include <iostream>
#include <queue>
using namespace std;
template <class t>
class Node{
	private:
		Node<t>* right;
		Node<t>* left;
		t data;
	public:
		Node(t d):right(0),left(0),data(d){}
		template <class T> friend class BST;
};
template <class T>
class BST{
	public:
		Node<T>* root;
	public:
		BST():root(0){}
		void insert(T d){
			Node<T>* n = new Node<T>(d);
			if(!root){
				root = n;
				return;
			}
			queue<Node<T>*> q;
			q.push(root);
			while(!q.empty()){
				Node<T>* temp = q.front();
				q.pop();
				if(temp->left!=NULL){
					q.push(temp->left);
				}
				else{
					temp->left = n;
					return;
				}
				if(temp->right!=NULL){
					q.push(temp->right);
				}
				else{
					temp->right = n;
					return;
				}
			}
		}


	void printInorder( Node<T>* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder(node->left);
 
    /* then print the data of node */
    cout << node->data << " ";
 
    /* now recur on right child */
    printInorder(node->right);
}
};
int main(){
	BST<int> b;

	b.insert(3);
	b.insert(4);
	b.insert(5);
	b.insert(6);
	b.printInorder(b.root);
	
	
	return 0;
}
