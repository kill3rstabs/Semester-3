#include <iostream>
using namespace std;
template <class U>
class DNode{
	private:
		U data;
		DNode<U>* next;
		DNode<U>* prev;
	public:
		DNode():data(0),prev(0),next(0){}
		DNode(U d):data(d),prev(0),next(0){}
		template <class T> friend class DLL;
};
template <class T>
class DLL{
	private:
		DNode<T>* head;
	public:
		DLL():head(0){}
		void addNode(T d){
			DNode<T>* n = new DNode<T>(d);
			DNode<T>* temp = head;
			if(head==NULL){
				head = n;
				return;
			}
			while(temp->next!=NULL){
				temp = temp->next;
			}
			n->prev = temp;
			temp->next = n;
			
		}
		void deleteLast(){
			DNode<T>* temp = head;
			DNode<T>* temp2;
			if(head==NULL){
				return;
			}
			while(temp->next->next!=NULL){
				temp = temp->next;
			}
			temp2 = temp;
			temp2 = temp->next; // pointing last node;
			temp->next = NULL;
			delete temp2;
		}
		DLL(const DLL &A) {
		DNode<T> *temp = A.head ;
		while (temp != NULL) {
			addNode(temp->data) ;
			temp = temp->next ;
		}
	}
	void DeleteAtFront(){
		DNode<T>* temp = head;
		DNode<T>* temp2 = head->next;
		delete temp;
		head= temp2;
	}
		void deleteDLL(){
			DNode<T>* temp = head;
			DNode<T>* temp2;
			if(head==NULL){
				return;
			}
			while(temp!=NULL){
				temp2 = temp;
				temp = temp->next;
				delete temp2;
				
			}
			head = NULL;
		}
		void addAtFront(T d){
			DNode<T>* temp = head;
			DNode<T>* n = new DNode<T>(d);
			if(head=NULL){
				head = n;
				return;
			}
			n->next = temp;
			head = n;
			
		}
		void Display(){
			cout<<endl;
			DNode<T>* temp = head;
			while(temp!=NULL){
				cout<<temp->data<<"<->";
				temp = temp->next;
			}
			cout<<"NULL";
		}
};
int main(){
	DLL<int> L1;
	L1.addNode(4);
	L1.addNode(2);
	L1.addNode(2);
	L1.addAtFront(1);
	L1.DeleteAtFront();
	L1.Display();
//	L1.deleteLast();
//	L1.Display();
//	L1.deleteDLL();
//	L1.Display;
	DLL<int> L2(L1);
	L2.Display();
	return 0;
}
