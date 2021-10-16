#include <iostream>
#include <cassert>
using namespace std;
template <class T>
class node{
	public:
		T data;
		node<T>* next;
	public:
		node<T>* getNext(){return next;} // Next pointer getters
		T getData(){return data;}
		void setData(T d){data =d;}
		void setNext (node<T>* n){next = n;}
		node():next(0){}
		node(T d):data(d),next(0){}
};
template <class  T>
class SinglyLinkedList{ //SLL class
	private:
		node<T> *head,*tail;
	public:
		node<T> * getHead(){return head;}
		void deleteList(){
		 	node<T>* temp;
		 	node<T> * currentptr = head;
		 	while(currentptr!=NULL){
		 		temp = currentptr;
				cout<<endl<<"Destroying "<<temp->getData();
				currentptr = currentptr->getNext();
				delete temp;
			}
		}
		SinglyLinkedList(const SinglyLinkedList & list)
	{
		if (list.head == NULL)
		{
			head = NULL;
			return;
		}

		node<T>* temp = list.head;
		node<T>* newNode = NULL;
//		node<T>* tail = NULL;
		while (temp != NULL)
		{
			newNode = new node<T>();
			newNode->data = temp->data;
			newNode->next = NULL;

			if (head == NULL)
			{
				head = newNode;
				tail = newNode;
			}
			else
			{
				tail->next = newNode;
				tail = newNode;
			}
			temp = temp->next;
		}
	} 
		SinglyLinkedList(){ // no parameterized constructor 
			head = NULL;
			tail = NULL;
		}
		void add_node(int d){ // add node function 
			node<T> * temp = new node<T>(d);
			temp->setNext(NULL);
			if(head == NULL){
				head= temp;
				tail = temp;
			}
			else{
				tail->setNext(temp);
				tail = tail->getNext();
			}
		}
		void display(){
			node<T> * temp = head;
			while(temp!=NULL){
				cout<<temp->getData()<<"->";
				temp = temp->getNext();
			}
			cout<<"NULL";
		}
		void add_head(T d){ // adding values to head
			node<T> *temp = head;
			node<T> *n = new node<T>(d);
			
			temp = head;
			head = n;
			head->setNext(temp);
			
		}
		SinglyLinkedList& operator =(const SinglyLinkedList<T> &orignal){
			if(this !=&orignal){
					
			}
		}
		void deleteFromtheList(){
			if(head==0){
				cout<<"list is empty";
			}
			else{
				cout<<endl<<"Printing orignal list: "<<endl;
				display();
				node<T>* temp = head;
				cout<<endl<<"New list after deletation of front node: ";
				cout<<endl<<"Deleting "<<temp->getData()<<endl;
				head = head->getNext();
				delete temp;
			}
		}
		void reverseList(){
			node<T>* curr= head,*prev = NULL,*n = NULL;
			while(curr!=NULL){
				n=curr->getNext();
				curr->setNext(prev);
				prev = curr;
				curr = n;
				
			}
			head = prev;
		}
		~SinglyLinkedList(){
			node<T>* temp = head;
			node<T>* temp2 = NULL;
			int count =0;
			int size = 0;
			while(temp->next!=NULL){
				temp=temp->next;
				size++;
			}
			temp =head;
			while(count!=size){
				while(temp->next!=NULL){
					temp2 = temp;
					temp = temp->next;
				}
				delete temp;
				temp2->next= NULL;
				temp = head;
				temp2 = NULL;
				count++;
			}
		}
		node<T>* reverse(node<T>* n){
        if (n == NULL)
            return NULL;
        if (n->getNext()==NULL) {
            head = n;
            return n;
        }
        node<T>* node1 = reverse(n->getNext());
        node1->setNext(n);
        n->setNext(NULL);
        return n;
    }
};
int main(){
	SinglyLinkedList<int> L;
	SinglyLinkedList<int> F(L);
	L.add_node(4);
	L.add_node(3);
	L.add_node(1);
	L.add_head(7);
	L.add_head(5);	
	L.display();
	cout<<endl;
	L.reverseList();
	L.display();
	F.display();
	return 0;
}
