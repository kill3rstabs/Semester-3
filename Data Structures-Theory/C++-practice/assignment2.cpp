#include <iostream>
using namespace std;
template <class T>
class node{
	public:
		T data;
		node<T>* next;
	public:
		node():next(0){};
		node(T d):data(d),next(0){};
		node(T d,node<T> *n):data(d),next(n){}
		void setNext(node<T> *n){next = n;}
		void setData(T d){data =d;}
		T getData()const {return data;}
		node<T>* getNext()const{return next;}
};
template <class T>
class SLL{
	private:
		node<T>* head;
	public:
		SLL(){head = NULL;}
		void add_node(T d){
			node<T> *temp= head;
			node<T> * n = new node<T>(d);
			if(head == NULL){
				head = n;
				n->setNext(NULL);
				return;
			}
			while(temp->getNext() != NULL){
				temp=temp->getNext();
			}
			temp->setNext(n);
			n->setNext(NULL);
		}
		void display(){
			node<T> * temp = head;
			cout<<endl;
			if(head == NULL){
				cout<<"NULL";
				return;
			}
			while(temp->getNext() != NULL){
				cout<<temp->getData()<<"->";
				temp=temp->getNext();
			}
			cout<<temp->getData()<<"->";
			cout<<"NULL";
			cout<<endl;
		}
		SLL& operator+(const SLL& rhs){
			node<T>* temp = head;
			node<T>* temp2 = rhs.head;
			int count1 = 0;
			int count2 = 0;
			SLL<int> res;
			while(temp->next!= head){
				temp = temp->next;
				count1++;
			}
			while(temp2->next!= rhs.head){
				temp = temp->next;
				count2++;
			}
			cout<<endl<<count1;
			cout<<endl<<count2;
//			if(count1!=count2){
//				cout<<"that function cannot be performed";
//				exit(0);
//			}
//			temp = head;
//			temp2 = rhs.head;
//			while(temp->next!=head && temp2->next!=rhs.head){
//				res.add_node(temp->data + temp2->data);
//				temp= temp->next;
//				temp2 = temp2->next;
//			}
//			return res;
			
		}
		
};
int main(){
	SLL<int> L;
	L.add_node(4);
	L.add_node(3);
	L.add_node(2);
	SLL<int> F;
	SLL<int> R;
	F.add_node(3);
	F.add_node(2);
	F.add_node(1);
	F.display();
	L.display();
L+F;
	R.display();
	
	
	return 0;
}
