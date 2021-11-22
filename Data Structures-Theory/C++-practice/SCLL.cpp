#include <iostream>
using namespace std;

template <class U> 
class Node{
	private:
		U data;
		Node<U>* next;
	public:
		Node():data(0),next(0){}
		Node(U d):data(d),next(this->next){}
		template <class T> friend class SCLL;
		
};
template <class T>
class SCLL{
	private:
		Node<T>* head;
	public:
		SCLL():head(0){}
		void addNode(T d){
			Node<T>* temp = head;
			Node<T>* n= new Node<T>(d);
			if(head == NULL){
				head = n;
				head->next = n;
				return;
			}
			while(temp->next!=head){
				temp = temp->next;
			}
			temp->next = n;
			n->next = head;
		}
		void display(){
			Node<T>* temp = head;
			cout<<endl;
			do{
				cout<<temp->data<<"->";
				temp = temp->next;
			}while(temp!=head);
			cout<<"Head";
		}
};
int main(){
	SCLL<int> L1;
	L1.addNode(3);
	L1.addNode(6);
	L1.display();
	
	return 0;
}
