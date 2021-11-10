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
				return;
			}
			while(temp->next!=NULL){
				temp= temp->next;
			}
			temp->next = n;
			n->prev = temp;
			
		}
		void addToHead(T d){
			DNode<T>* temp = head;
			DNode<T>* n = new DNode<T>(d);
			if(head==NULL){
				head = n;
				return;
			}
			head = n;
			n->next = temp;
			temp->prev = n;
		}
		void display(){
			DNode<T>* temp = head;
			cout<<endl;
			do{
				cout<<temp->data<<"->";
				temp= temp->next;
			}while(temp!=NULL);
			cout<<"NULL";
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
	L.addNode(4);
	L.addNode(3);
	L.addToHead(1);
	L.addNode(5);
	L.display();
	L.reverse();
//	L.sort();
	L.display();
	L.sort();
	L.display();
	return 0;
}
