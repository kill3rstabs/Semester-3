#include <iostream>
using namespace std;
template <class t>
class Node{
	private:
		t data;
		Node<t>* next;
	public:
		Node():data(0),next(0){}
		Node(t d):data(d),next(0){}
		template <class T> friend class SLL;
};
template <class T>
class SLL{
	private:
		Node<T>* head;
	public:
		SLL(){
			head = NULL;
		}
		void addTohead(T d){
			Node<T>* newNode= new Node<T>(d);
			Node<T>* temp = head;
			if(head == NULL){
				head = newNode;
				return;
			}
			head = newNode;
			newNode->next = temp;
		}
		void addToTail(T d){
			Node<T>* temp = head;
			Node<T>* newNode = new Node<T>(d);
			if(head == NULL){
				head= newNode;
				return;
			}
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next = newNode;
			
		}
		void display(){
			Node<T>* temp = head;
		
			while(temp!=NULL){
				cout<<temp->data<<"->";
				temp = temp->next;
			}
			cout<<"NULL";
		}
	 
};
template <class u>
void swap(Node<u>* head,Node<u>* p,Node<u>* q){
	Node<u>* temp = head;
	Node<u>* tail;
	while(temp->next!=NULL){
		temp =temp->next;
	}
	tail = temp;
	temp = head;
	//flagp and flagq is 
	bool flagp = false,flagq= false;
	//checking wether the nodes are within linked list or not(valid or not valid)
	while(temp!=head){
		if(p==temp){
			flagp = true;
		}
		if(q==temp){
			flagq== true;
		}
		if(flagq && flagp){
			break;
		}
	}
	temp = p
	//what if p and q are adjacent nodes;
	if(p->next == q && flagp && flagq){
		if(p== head){
			
		}
		temp = p;
		temp->next = q->next;
		q->next = p;
	}
	else if(q->next== p && flagp && flagq){
		temp = q;
		temp->next = p->next;
		p->next = q;
	}
	else if(p==q){ // if p and q are same
		return;
	}
	else if(p==head && q==tail && flagp && flagq){
		q->next = temp;
		p->next = 0;
		head = q;
	}
	else if(q== head && p== tail && flagp && flagq){
		p->next = temp;
		q->next = 0;
		head = p;
	}
	else if(p== head && flagp && flagq){
		
	}
	else if(q==head && flagp && flagq){
		
	}
	else if(p==tail && flagp && flagq){
		
	}
	else if(q==tail && flagp && flagq){
		
	}
	else{
		
	}
	
	
	
	
		
}
int main(){
	SLL<int> l;
	l.addTohead(2);
	l.addTohead(3);
	l.addTohead(1);
	l.addToTail(10);
	
	l.display();
}#include <iostream>
using namespace std;
template <class t>
class Node{
	private:
		t data;
		Node<t>* next;
	public:
		Node():data(0),next(0){}
		Node(t d):data(d),next(0){}
		template <class T> friend class SLL;
};
template <class T>
class SLL{
	private:
		Node<T>* head;
	public:
		SLL(){
			head = NULL;
		}
		void addTohead(T d){
			Node<T>* newNode= new Node<T>(d);
			Node<T>* temp = head;
			if(head == NULL){
				head = newNode;
				return;
			}
			head = newNode;
			newNode->next = temp;
		}
		void addToTail(T d){
			Node<T>* temp = head;
			Node<T>* newNode = new Node<T>(d);
			if(head == NULL){
				head= newNode;
				return;
			}
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next = newNode;
			
		}
		void display(){
			Node<T>* temp = head;
		
			while(temp!=NULL){
				cout<<temp->data<<"->";
				temp = temp->next;
			}
			cout<<"NULL";
		}
	 
};
template <class u>
void swap(Node<u>* head,Node<u>* p,Node<u>* q){
	Node<u>* temp = head;
	bool flagp = false,flagq= false;
	//checking wether the nodes are within linked list or not(valid or not valid)
	while(temp!=head){
		if(p==temp){
			flagp = true;
		}
		if(q==temp){
			flagq== true;
		}
		if(flagq && flagp){
			break;
		}
	}
	temp = head;
	Node <u>* temp2 = p->next;
	if(head==p){
		while(temp->next!=q){
			temp= temp->next;
		}
		temp->next = p;
		p->next= q->next;
		head = q;
		q->next = temp2;
		
	}
	else if(head==q){
		temp2= q->next;
		temp = head;
		while(temp->next!=p){
			temp= temp->next;
		}
		temp->next = q;
		q->next= p->next;
		head = p;
		p->next = temp2;
		
	}
	else{
		temp = head;
		while(temp->next!=q){
			temp= temp->next;
		}
		while(temp2->next!=p){
			temp2= temp2->next;
		}
		Node<u>* temp3 = p->next;
		temp->next = p;
		p->next =q->next;
		temp2->next =q;
		q->next = temp;
	  
	}
	
	
	
	
		
}
int main(){
	SLL<int> l;
	l.addTohead(2);
	l.addTohead(3);
	l.addTohead(1);
	l.addToTail(10);
	
	l.display();
}
