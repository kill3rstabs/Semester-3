#include <iostream>
using namespace std;
template <class T>
class node{
	public:
		T data;
		node<T> * next;
		node():next(0){}
		node(T d):data(d),next(0){}
		node(T d, node<T> *n):data(d),next(n){}
};
template <class T>
class SinglyLinkedList{
	private:
		node<T>* head;
	public:
		SinglyLinkedList():head(NULL){}
		SinglyLinkedList(const SinglyLinkedList<T> &rhs){ //copy constructor  
			// checking wether rhs ll is empty or not if empty then creating empty
			// for this object
			if(rhs.head == NULL){
				head = NULL;
				return;
			}
			//creating nodes;
			//temp which stores the head add of rhs obj
			// tail which later stores the address of last node
			//n which is the nodes need to be created to form lhs ll
			node<T> * temp = rhs.head;
			node<T> *tail =NULL;
			node<T>* n= NULL;
			// creating nodes and copying data until rhs comes to the end
			while(temp!=NULL){
				n = new node<T>(temp->data);
				n->next = NULL;
				
				if(this->head == NULL){
					this->head = n;
					tail = n;
				}
				else{
					tail->next =n;
					tail = n;
				}
				temp = temp->next;
			}
			
		}
		void addNode(T d){
			node<T> * temp = head;
			node<T> * n = new node<T>(d);
			if(head==NULL){
				head = n;
				return;
			}
			while(temp->next !=NULL){
				temp = temp->next;
			}
			temp->next = n;
		}
		void display(){
			node<T>* temp = head;
			cout<<endl;
			while(temp != NULL){
				cout<<temp->data<<"->";
				temp = temp->next;
			}
			
			cout<<"NULL";
		}
		
		
		
};
int main(){
	SinglyLinkedList<int> L;
	L.addNode(4);
	L.addNode(3);
	L.addNode(1);
	L.display();
	SinglyLinkedList<int> F(L);
	F.display();
	
	return 0;
}
