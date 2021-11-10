#include <iostream>
using namespace std;
template <class u>
class DNode{
	public:
		u data;
		DNode<u> * next;
		DNode<u> * prev;
	public:
		DNode():data(0),next(0),prev(0){}
		DNode(u d):data(d),next(this),prev(0){}
		
//		DNode(u d,DNode<u>* n=this,DNode<u>* p=0):data(d),next(n),prev(p){}
		template <class T> friend class DLL;
};
template <class T>
class DLL{
	private:
	 	DNode<T>* head;
	public:
		DLL(){
			head = NULL;
		}
		DNode<T>* getHead(){return head;}
		void insertAtTail(T d){
			DNode<T>* temp = head;
			DNode<T>* n = new DNode<T>(d);
			if (head==NULL){
				head = n;
				return ;
			}
			do{
				temp=temp->next;
			}while(temp!=head);
			temp->next = n;
			n->prev = temp;
			n->next = head;
			
		}
		void display(){
			DNode<T>* temp = head;
		
			do{
				cout<<temp->data<<"->";
				temp = temp->next;
			}while(temp!=head);
			cout<<"NULL";
		}
		
};
template <class x>
void swapNodes(DNode<x>* head,DNode<x>* p,DNode<x>* q){
	bool flagp = false,flagq = false;
	
	DNode<x> *temp = head;
	do{
		if(p==temp){
			flagp==true;
		}
		if(q==temp){
			flagq==true;
		}
		temp=temp->next;
	}while(temp!=head);
	//check  p and q are adjcent nodes; 
	//check wether any of them is head;
	if(!flagp || !flagq){
		cout<<"Not valid nodes";
		return;
	}
	if((flagp&&flagq)){
		DNode<x> *prevp;
		DNode<x> *nextp;
		x d;
		prevp = p->prev;
		nextp = p->next;
		d = p->data;
		p->prev = q->prev;
		p->next = q->next;
		p->data = q->data;
		q->prev = prevp;
		q->next = nextp;
		q->data = d;
		if(p==head){
			head =p;
		}
		if(q== head){
			head = q;
		}
	}
	
//	if(p->next = q){
//		
//	}
//	if(q->next = p){
//		
//	}
	
}
int main(){
	DLL<int> L;
	L.insertAtTail(3);
	L.insertAtTail(2);
	L.insertAtTail(1);
	L.insertAtTail(0);
	L.insertAtTail(23);
	L.display();
	DNode<int>* p = L.getHead();
	p = p->next->next;
	DNode<int>* q = L.getHead();
	
	swapNodes(L.getHead(),p,q);
	
	return 0;
}
