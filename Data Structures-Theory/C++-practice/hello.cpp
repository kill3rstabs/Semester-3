#include <iostream>
using namespace std;
template <class T>
class node{
	private:
		T data;
		node<T> *next;
	public:
		node():next(0){}
		node(T d):data(d),next(0){};
		friend class SimplyLinkedList; 
};
template <class T>
class SimplyLinkedList{
	private:
		node<T> *head, *tail;
	public:
		SimplyLinkedList(){
			head = NULL;
			tail = NULL;
		}
		void addtolist(T d){
			node<T> *temp = new node<T>(d);
			temp->next = NULL;
			if(head == NULL){
				head = temp;
				tail = temp;
			}
			else{
				tail->next = temp;
            	tail = tail->next;
			}
		}
		void display(){
	    	node<T> *temp = new node<T>;
			temp = head;
	    	
	    	while(temp!=NULL){
	    		cout<<temp->data<<"->";
	    		temp = temp->data();
			}
			cout<<"Null";
		}
//		void insertAtHead(){
//			node* temp = new node<T>()
//		}
};
int main(){
	SimplyLinkedList<char> a;
	a.addtolist('a');
	a.addtolist('b');
	a.display();
	
	return 0;
}
