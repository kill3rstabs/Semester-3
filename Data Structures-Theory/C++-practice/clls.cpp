#include <iostream>
using namespace std;
template <class T>
class node{
	public:
		T data;
		node<T>* next;
	public:
		node():data(0),next(NULL){}
		node(int d):data(d),next(NULL){}
		node(int d,node<T>* n):data(d),next(n){}
};
template <class T>
class CircularSinglyLinkedList{
	private:
		node<T> *head;
	public:
		CircularSinglyLinkedList(){head = NULL;}
		void add_to_tail(int d){
			node<T> * n = new node<T>(d);
			
			if(head == NULL){
				head = n;
				head->next =n;
				return;
			}
			node<T>* temp =head;
			
			while(temp->next!= head){
				temp = temp->next;
			}
			temp->next = n;
			n->next = head;
			
//				
			
		}
		void add_to_head(int d){
			node<T> * n = new node<T>(d);
			
			if(head == NULL){
				head = n;
				head->next =n;
				return;
			}
			node<T>* temp =head;
			
			while(temp->next!= head){
				temp = temp->next;
			}
			temp->next = n;
			n->next = head;
			head = n;
//				
			
		}
		T operator[](int pos){
			node<T>* temp = head;
			int count = 0;
			if(count>pos){
				cout<<"out of bound";
				return 0;
			}
			while(count!=pos){
				temp = temp->next;
				count++;
			}
			return temp->data;
		}
		void add_at_pos(int pos,T d){
			node<T>* temp = head;
			node<T> *temp2 = head;
			node<T> *t = head;
			int size = 1;
			int count =1;
			node<T>* n = new node<T>(d);
			if(head == NULL){
				head = n;
				return;
			}
			while(t->next!=head){
				t = t->next;
				size++;
			}
			cout<<endl<<endl<<"Size: "<<size<<endl;
			if(pos>size || pos<size){
					cout<<"position out of bound!";
					return;
			}
			while(count!=pos-1){
				
				temp=temp->next;
				temp2 = temp->next;
				count++;
			}
			temp2=temp2->next;
			temp->next = n;
			n->next = temp2;
			
			
		}
		void display(){
			node<T> *temp = head ;
			do{
				cout<<temp->data<<"->";
				temp= temp->next;
			}while(temp->next !=head);
			cout<<temp->data<<"->";
			cout<<"NULL";
		}
		
		void reverse(){
			node<T>* curr= head,*prev = NULL,*n = NULL;
			while(curr!=NULL){
				n=curr->next;
				curr->next = prev;
				prev = curr;
				curr = n;
				
			}
			head = prev;
			node<T>* temp = head;	
			node<T>* t = head;
			while(temp->next != head){
				temp = temp->next;
				t = temp->next;
			}
			t = t->next;
			temp->next = head ;
			head = t;
			
		}
		void deleteParticular(int pos){
			node<T>* temp = head;
			node<T>* temp2 = head;
			int size = 0;
			int count = 0;
			while(temp->next!=head){
				temp = temp->next;
				size++;
			}
			if(count>size){
				cout<<"Position out of bound!";
				return;
			}
			if(pos ==0){
				temp = head;
				node<T> * t=head->next;
				while(temp->next !=head){
					temp= temp->next;
				}
				
				temp->next = t;
				head=t;
				return ;

			}
			temp = head;
			while(count !=pos-1){
				temp = temp->next;
				temp2 = temp2->next;
				count++;
			}
			temp2 = temp2->next->next;
			temp->next = temp2;
			
		}
		void search(T d){
			int count = 0;
			node<T>* temp = head;
			while(temp->next != head){
				if(temp->data == d){
					cout<<endl<<"Found "<<temp->data<<" at index: "<<count;
					return;
				}
				count++;
				temp= temp->next;
			}
		}
		
};

int main(){
	CircularSinglyLinkedList<int> L;
	L.add_to_tail(3);
//
	L.add_to_tail(2);
	L.add_to_tail(4);
	L.add_to_tail(1);
	L.add_to_head(0);
	L.display();
	L.reverse();
	L.display();
	L.add_at_pos(0,10);
	cout<<endl;
	cout<<endl<<L[3]<<endl; 
	L.display();
	L.search(2);
	L.deleteParticular(0);
	cout<<endl<<endl;
	L.display();
	
	return 0;
}
