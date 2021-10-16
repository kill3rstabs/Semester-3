#include <iostream>
using namespace std;
template <class T>
class node{
	public:
		T data;
		node<T> *next;
		
		node<T> *prev;
	public:
		node():data(0),next(NULL),prev(NULL){}
		node(T d):data(d),next(NULL),prev(NULL){}
};
template <class T>
class DoublyCircularLinkedList{
	private:
		node<T>* head;
	public:
		DoublyCircularLinkedList(){
			head = NULL;
				
		}
		void add_to_tail(T d){
			node<T>* temp =head;
			node<T>* temp2= head;
			node<T>* n = new node<T>(d);
			if(head==NULL){
				head = n;
				n->next = head;
				n->prev = head;
				return;
				
			}
			while(temp->next!=head){
				temp= temp->next ;
			}
			temp->next =n;
			n->prev = temp;
			n->next = temp2;
			temp2->prev = n;
		}
		int length(){
			node<T>* temp =head;
			int size =0;
			while(temp->next!=head){
				temp= temp->next;
				size++;
			}
			return size;
		}
		void addToPos(int pos,T d){
			node<T> * temp = head;
			node<T> * temp2;
			int size = length();
			node<T>* n  = new node<T>(d);
			int count =0;
			if(pos<0 || pos >size+2){
				cout<<endl<<"Out of bound!"<<endl;
				return;
			}//done
//			
			if(pos ==0){
				while(temp->next!=head){
					temp=temp->next;
				}
				temp2->prev = n; 
				n->next = temp2;
				n->prev = temp;
				temp->next = n;
				return;
			}
			temp = head;
			temp2 = head;
			if(pos==size+1){
				while(temp->next!=head){
					temp = temp->next;
				}
				temp->next = n;
				n->prev = temp;
				n->next = temp2;
				temp2->prev = n;
				return;
				
			}//done
			temp = head;
			
			while(count!= pos-1){
				temp = temp->next;
			}
			temp2= temp->next;
			temp->next = n; 
			n->prev= temp;
			n->next = temp2;
			temp2->prev = n;
		}
		
		void display(){
			node<T>* temp = head;
			while(temp->next!=head){
				cout<<temp->data<<"->";
				temp = temp->next;
			}
			cout<<temp->data<<"->";
			cout<<"NULL";
		}
		
};
int main(){
	DoublyCircularLinkedList<int> L;
	L.add_to_tail(3);
	L.add_to_tail(4);
	L.add_to_tail(2);
	L.add_to_tail(5);
	L.addToPos(49,100);
	L.display();
	
	
	return 0;
}
