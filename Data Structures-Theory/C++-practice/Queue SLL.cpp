#include <bits/stdc++.h>
#include<windows.h>
using namespace std;
template <class U>
class Node{
	private:
		U data;
		Node<U>* next;
		int index;
	public:
		Node(U d):data(d),next(0),index(-1){}
		template <class T> friend class Queue;
};
template <class T>
class Queue{
	private:
		Node<T>* front;
		Node<T>* rear;
	public:
		Queue():front(0),rear(0){}
		void Enqueue(T d){ //add at last;
			Node<T>* temp = front;
			Node<T>* n = new Node<T>(d);
			if(front == NULL){
				front = n;
				index++;
				return;
			}
			while(temp->next!=NULL){
				temp = temp->next;
			}
			index++;
			rear = temp;
			temp->next = n;
		}
		void Dequeue(){ //delete from head
			Node<T>* temp = front;
			if(front==NULL){
				return;
			}
			index--;
			front = temp->next;
			delete temp;
			
		}
		void display(){
			Node<T>* temp = front;
			while(temp!=NULL){
				Sleep(999);
				cout<<temp->data<<" ";
				
				temp = temp->next;
			}
		}
		
};
int main(){
	Queue<int> q;
	q.Enqueue(4);
	q.Enqueue(3);
	q.Enqueue(1);
	q.display();
	cout<<endl;
	q.Dequeue();
	q.display();
	return 0;
}
