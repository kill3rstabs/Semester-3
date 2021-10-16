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
			DoublyLinkedList(const DoublyLinkedList &rhs){
				int size =0;
				node<T>* temp = rhs.head;
				while(temp->next != NULL){
					temp = temp->next;
					size++;
				}
				temp =head;
				this->head = rhs.head; 
				for(int i=0;i<=size;i++){
					add_to_tail(temp->data);
					
					temp = temp->next;
				}
				
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
				cout<<endl<<"size: "<<size<<endl;
			
				temp = head;
				if(pos>size || pos<0){
					cout<<"Pos out of bound";
					return;
				}
				if(pos ==0){
				    temp=temp->next;
				    delete temp2;
				    temp->prev = NULL;
				    head  = temp;
				    return;
				}
				temp = head;
				temp2 = head;
				if(pos == size){
					while(count!=pos-1){
						temp = temp->next;
						count++;
					}
					temp3= temp->next;
					temp->next = NULL;
					delete temp3;
					return;
				}
				temp =head;
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
			int length(){
				node<T>* temp= head;
				int size=0;
				while(temp->next!=NULL){
					temp = temp->next;
					size++;
				}
				return size;
			}
			void addToPos(int pos,int d){
			    node<T>* temp = head;
			    node<T>* temp2;
			    int count=0;
			    node <T>* n = new node<T>(d);
			    int size = length();
			    if(pos == 0){
			    	temp->prev = n;
			    	n->next = temp;
			    	head = n;
			    	return;
				}
				if(pos==size+1){
					while(temp->next !=NULL){
						temp= temp->next;
					}
					temp->next = n;
					n->prev = temp;
					return ;
				}
			    while(count!=pos-1){
			    	temp = temp->next;
			    	count++;
				}
				temp2 = temp;
				temp2= temp2->next;
				temp->next = n;
				n->next= temp2;
				temp2 = n;
				
				
			}
			
	};
	int main(){
		DoublyLinkedList<int> L;
		L.add_to_tail(4);
		L.add_to_tail(3);
		L.add_to_tail(4);
		L.add_to_tail(100);
		L.add_to_tail(900);
		L.display();
//		L.deleteAtPos(0);
		cout<<endl<<"Size: "<<L.length()<<endl;
	
		L.display();
		L.addToPos(5,10);
		cout<<endl;
		L.display();
		DoublyLinkedList<int> F(L);
		return 0;
	}
