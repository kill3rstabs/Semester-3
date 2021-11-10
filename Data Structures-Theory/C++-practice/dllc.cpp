#include <iostream>
using namespace std;
template <class u>
class DNode{
	private:
		u data;
		DNode<u> *next,*prev;
	public:
		DNode():data(0),next(0),prev(0){}
		DNode(u d):data(d),next(0),prev(0){}
		template <class T> friend class DLL;	
};
template <class T>
class DLL{
	private:
		DNode<T>* head;
	public:
		DLL():head(NULL){}
		void addNode(T d){
			DNode<T>* temp = head;
			DNode<T>* n = new DNode<T>(d);
			if(head==NULL){
				head = n;
				n->next = head;
				return;
			}
			while(temp->next!=head){
				temp= temp->next;
			}
			temp->next = n;
			n->prev = temp;
			n->next = head;
			
		}
		void addToHead(T d){
			DNode<T>* temp = head,*tail = head;
			DNode<T>* n = new DNode<T>(d);
			if(head==NULL){
				head = n;
				n->next = head;
				n->prev = head;
				return;
			}
			do{
				tail = tail->next;
			}while(tail->next!=head);
			head = n;
			n->prev = tail;
			n->next = temp;
			temp->prev = n;
		}
		void display(){
			DNode<T>* temp = head;
			cout<<endl;
			do{
				cout<<temp->data<<"->";
				temp= temp->next;
			}while(temp!=head);
			cout<<"head";
		}
		void reverse(){
			DNode<T>* c = head;
			DNode<T>* temp;
			while(c!=NULL){
				temp = c->prev;
				c->prev = c->next;
				c->next = temp;
				c=c->prev;
				 
			}
			head=temp->prev;
		}
		void sort(){
			DNode<T>* temp =head;
			DNode<T>* temp2 = head->next;
			T d;
			while(temp!=NULL){
				while(temp2->next!=NULL){
					if(temp2->data>temp2->next->data){
						d = temp2->data;
						temp2->data = temp2->next->data;
						temp2->next->data=d;
						
					}
					temp2 = temp2->next;
				}
				temp = temp->next;
				
			}
		}
};
int main(){
	DLL<int> L;
	L.addNode(3);
	L.addNode(4);
	L.addToHead(1);
	L.display();
	return 0;
}
