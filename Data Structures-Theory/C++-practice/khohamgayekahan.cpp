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
		void reverse(){
			node<T>* p= NULL;
			node<T> *c= head;
			node<T> *n = head->next;
			while(c->next!=NULL){
				c->next = p;
				p = c;
				c = n;
				n=n->next;
			}
		}
		void palindromeCheck(){
			SLL res;
			node<T>* temp = head;
			int size =0;
			this->reverse();
			while(temp->next!=NULL){
				temp=temp->next;
				size++;
			}
			temp = head;
			while(temp->next!=NULL){
				res.add_node(temp->data);
				temp=  temp->next;
			}
			this->reverse();
			temp = head;
			node<T>* temp2 = res.head;
			res.display();
			int count =0;
			while(temp->next!=NULL){
				if(temp->data == temp2->data){
					count++;
				}
				else{
					cout<<"Not a palindrome";
					return;
				}
				temp = temp->next;
				temp2 = temp2->next;
			}
			if(count == size){
				cout<<"palindrome";
			}
			else{
				cout<<"not a palindrome";
			}
			
			
		}
		
};
int main(){
	SLL<char> L;
	L.add_node('l');
	L.add_node('e');
	L.add_node('v');
	L.add_node('e');
	L.add_node('e');
	L.display();
	L.palindromeCheck();
	

	
	
	return 0;
}
