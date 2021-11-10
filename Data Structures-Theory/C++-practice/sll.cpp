#include <iostream>
using namespace std;
template <class u>
class Node{
	private:
		u data;
		Node<u>* next;
	public:
		Node():data(0),next(0){}
		Node(u d):data(d),next(0){}
		template <class T> friend class SLL;
}; 
template <class T>
class SLL{
	private:
		Node<T> * head;
	public:
		SLL():head(NULL){}
		void insertAtTail(T d){
			Node<T>* temp = head;
			Node<T>* n = new Node<T>(d);
			if(head == NULL){
				head = n;
				return;
			}
			while(temp->next!=NULL){
				temp = temp->next;
			}
			temp->next = n;
		}
		void display(){
			Node<T>* temp = head;
			do{
				cout<<temp->data<<"->";
				temp= temp->next;
			}while(temp!=NULL);
			cout<<"NULL";
		}
		void insertAtHead(T d){
			Node<T>* temp = head;
			Node<T>* n = new Node<T>(d);
			if(head == NULL){
				head = n;
				return;
			}
			head = n;
			n->next = temp;
			
		}
		SLL(const SLL &rhs){
			
			Node<T>* temp = rhs.head;
			while(temp!=NULL){
				insertAtTail(temp->data);
				temp = temp->next;
			}
		}
		int getSize(){
			Node<T>* temp = head;
			int size = 0;
			while(temp->next != NULL){
				temp= temp->next; 
				size++;
			}
			return size;
			
		}
		void deleteAthead(){
			Node<T>*temp = head;
			Node<T>* temp2 = head->next;
			head = temp2;
			delete temp;
			
		}
		void deleteAtTail(){
			Node<T>* temp = head,* temp2;
			while(temp->next->next!=NULL){
				temp = temp->next;
			}// pointing second last node
			temp2 = temp->next;
			delete temp2;
			temp->next= NULL;
		}
		T operator[](int i){
			Node<T>* temp = head;
			int count = 0;
			if(i>getSize() || i<0){
				cout<<endl<<"out of bound! exit value: ";
				return 99999;
			}
			while(count!=i){
				temp= temp->next;
				count++; 
			}
			return temp->data;
		}
		SLL& operator=(const SLL &rhs){
			if(this!=&rhs){
				Node<T>* temp = rhs.head;
				while(temp!=NULL){
					insertAtTail(temp->data);
					temp = temp->next;
				}
			}	
		}
	
//~SLL(){
//			Node<T>* temp = head;
//			Node<T>* temp2 = NULL;
//			int count =0;
//			int size = 0;
//			while(temp->next!=NULL){
//				temp=temp->next;
//				size++;
//			}
//			temp =head;
//			while(count!=size){
//				while(temp->next!=NULL){
//					temp2 = temp;
//					temp = temp->next;
//				}
//				delete temp;
//				temp2->next= NULL;
//				temp = head;
//				temp2 = NULL;
//				count++;
//			}
//		}
		void sort(){
			Node<T>* temp =head;
			Node<T>* temp2 = head->next;
			T d;
			while(temp->next!=NULL){
				while(temp2->next!=NULL){
					if(temp2->data>temp2->next->data){
						d = temp2->data;
						temp2->data = temp2->next->data;
						temp2->next->data=d;
						
					}
					temp2 = temp2->next;
				}
				temp = temp->next;
				
			}
		}
		void reverse(){
			Node<T>* n =head;
			Node<T>* p = NULL;
			Node<T>* c = head;
			while(c!=NULL){
				n= n->next;
				c->next = p;
				p = c;
				c=n;
				 
			}
			head=p;
		}
};
int main(){
	SLL<int> s;
	int c;
	s.insertAtTail(5);
	s.insertAtTail(3);
	s.insertAtHead(1);
	s.sort();
	s.display();
	s.reverse();
	s.display();
	return 0;		
}
