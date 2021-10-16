#include <iostream>
using namespace std;
template <class T>
class Node{
	public:
		T data;
		Node<T> * next;
	public:
		Node():next(NULL){}
		Node(T d):data(d),next(NULL){}
		Node(T d,Node<T>* n):data(d),next(n){}
};
template <class T>
class SinglyLinkedList{
	private:
		Node<T> *head,*tail;
	public:
		SinglyLinkedList(){
			head = NULL;
			tail = NULL;
		}
		void add_node(T d){
			Node<T> *n = new Node<T>(d);
			
			if(head = NULL){
				head = n;
				tail = n;
			}
			else{
				tail->next = n;
				tail = tail->next;
			}
		}
		void Display(){
			Node<T>* temp = head;
			while(temp!=NULL){
				cout<<temp->data<<"->";
				temp = temp->next;
			}
			cout<<"NULL"<<endl;
		}
};
int main(){
	SinglyLinkedList<int> L;
	L.add_node(4);
	
	
	return 0;
}
