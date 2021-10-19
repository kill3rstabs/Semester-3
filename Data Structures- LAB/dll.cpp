#include <iostream>
using namespace std;

template <class t>
class Node{
	private:
		t data;
		Node<t>* prev;
		Node<t>* next;
	public:
		Node():data(NULL),next(0),prev(0){}
		Node(t d):prev(0),next(0),data(d){}
//		Node<t>* getPrev(){return prev;}
//		Node<t>* getNext(){return next;}
//		void setNext(Node<t>* n){next = n;}
//		void setPrev(Node<t>* p){prev=p;}
//		t getData(){return data;}
//		void setData(t d){data = d;}
		template <class T> friend class DLL;
};
template <class T>
class DLL{
	private:
		Node<T>* head;
	public:
		DLL(){
			head = NULL;
		}
		void insertAddLast(T d){
			Node<T>* newnode = new Node<T>(d);
			Node<T>* temp;
			if(head==NULL){
				head = newnode;
				return;
			}
			temp = head;
			while(temp->next!=NULL){
				temp=temp->next;
				
			}
			temp->next = newnode;
				newnode->prev = temp;
				newnode->next= NULL;
			
		}
		void display(){
			Node<T>* temp = head;
		
			while(temp!=NULL){
				cout<<temp->data<<"->";
				temp = temp->next;
			}
			cout<<"NULL";
		}
		void InsertAtHead(T d){
			Node<T>* temp = head;
			Node<T>* newnode = new Node<T>(d);
			if(head == NULL){
				head = newnode;
				return;
			}
			temp = head;
			head = newnode;
			newnode->next=temp;
			temp->prev=newnode;
		}
};
int main(){
	DLL<int> l;
	l.insertAddLast(3);
	l.insertAddLast(2);
	l.insertAddLast(1);
	l.InsertAtHead(0);
	l.display();
	
	return 0;
}
