	#include <iostream>
	using namespace std;
	template <class T>
	class node{
		public:
			T data;
			node<T> *next;
			node<T> *prev;
			node():data(0),next(NULL),prev(NULL){}
			node(T d):data(d),next(0),prev(0){}
	};
	template <class T>
	class DoublyLinkedList{
		public:
			node<T>* head;
			DoublyLinkedList(){
				head =NULL;
			}
			void add_to_tail(int d){
				node<T> *n = new node<T>(d);
				n->next = 0;
				n->prev = 0;
				if(head == NULL){
					head = n;
					return;
				}
				node <T>* temp = head;
				while(temp->next!=NULL){
					temp=temp->next;
				}
				n->prev = temp;
				n->next = NULL;
				temp->next = n;
			}
			void display(){
				node<T>* temp = head;
				if(head ==NULL){
					cout<<"Linked List is Empty";
					return;
				}
				while(temp != NULL){
					cout<<temp->data<<"->";
					temp=temp->next;
				}
				cout<<"NULL";
			}
			void deleteAtPos(int pos){
				node<T>* temp = head;
				node<T>* temp2 = head;
				node<T>* temp3 = head;
				int size =0;
				int count =0;
				while(temp->next!=NULL){
					temp = temp->next;
					size++;
					
				}
				cout<<endl<<"size: "<<size;
//				temp = head;
//				if(pos>size){
//					cout<<"Pos out of bound";
//					return;
//				}
//				if(pos == size){
//					while(count!=pos-1){
//						temp = temp->next;
//						count++;
//					}
//					temp3= temp2->next;
//					temp->next = NULL;
//					delete temp3;
//					exit(1);
//				}
				
				while(count!=pos-1){
					temp = temp->next;
					temp2 = temp2->next;
					temp3 = temp3->next;
					count++;
				}
				temp3 = temp3->next;
				temp2= temp2->next->next;
				temp->next = temp2;
				temp2->prev = temp;
				delete temp3;
				
			}
	};
	int main(){
		DoublyLinkedList<int> L;
		L.add_to_tail(4);
		L.add_to_tail(3);
		L.add_to_tail(4);
		L.display();
		L.deleteAtPos(1);
		L.display();
		
		return 0;
	}
