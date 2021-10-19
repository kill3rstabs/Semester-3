#include <iostream>
using namespace std;
template <class t>
class Node{
	public:
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
		Node<T>* getHead(){return head;}
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
			cout<<endl;
			while(temp!=NULL){
				cout<<temp->data<<"->";
				temp = temp->next;
			}
			cout<<"NULL";
		}
//		void removeDuplicates()
//		{
//			Node<T>* i=head;
//			Node<T>* j=NULL;
//			T x;
//			while(i!=NULL)
//			{
//				x = i->data;
//				while(j!=NULL)
//				{
//					Node<T>* temp;
//					Node<T>* temp2;
//					if(i->data==x)
//					{
//						while(temp->next!=j){
//							temp->next = j->next;
//							
//						}
//						j->next = NULL;
//							temp2 = j;
//							delete temp2;	
//						j= temp->next;					
//					}
//					else{
//						j= j->next;
//					}
//					
//				}
//				i=i->next;
//			}
//		}
	 
};
template <class u>
void swap(Node<u>* head,Node<u>* p,Node<u>* q){
	Node<u>* temp = head;
	bool flagp = false,flagq= false;
	//checking wether the nodes are within linked list or not(valid or not valid)
	while(temp!=NULL){
		if(p==temp){
			flagp = true;
		}
		
		if(q==temp){
			flagq= true;
		}
		
//		if(flagq && flagp){
//			cout<<endl<<"Flagp: "<<flagp<<endl<<"Flagq: "<<flagq;
//			break;
//		}
		
		temp = temp->next;
	}
	if(!flagq && !flagp){
			cout<<"not valid";
			return;

	}
	
	temp = head;
	Node <u>* temp2 = p->next;
//	if(head==p){
//		while(temp->next!=q){
//			temp= temp->next;
//		}
//		temp->next = p;
//		p->next= q->next;
//		head = q;
//		q->next = temp2;
//		
//	}
//	else if(p==q){
//		return;
//	}
//	else if(head==q){
//		temp2= q->next;
//		temp = head;
//		while(temp->next!=p){
//			temp= temp->next;
//		}
//		temp->next = q;
//		q->next= p->next;
//		head = p;
//		p->next = temp2;
//		
//	}
//	else{
//		temp = head;
//		while(temp->next!=q){
//			temp= temp->next;
//		}
//		while(temp2->next!=p){
//			temp2= temp2->next;
//		}
//		Node<u>* temp3 = p->next;
//		temp->next = p;
//		p->next =q->next;
//		temp2->next =q;
//		q->next = temp;
//	  
//	}		
}
int main(){
	SLL<int> l;
	l.addTohead(2);
	l.addTohead(3);
	l.addTohead(1);
	l.addToTail(11);
	l.addToTail(10);
	l.addToTail(12);
	l.addToTail(11);
	l.addToTail(13);
	l.addToTail(14);
	Node<int>* p = l.getHead();

	Node<int>* q = l.getHead();

	
//	cout<<endl<<"P: "<<p;
//	cout<<endl<<"Q: "<<q;
	
	swap(l.getHead(),p,q);
	l.display();
}
