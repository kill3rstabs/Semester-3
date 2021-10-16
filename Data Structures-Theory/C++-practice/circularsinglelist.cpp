#include <iostream>
using namespace std;
template <class T>
class node{
	private:
		T data;
		node<T>* next;
	public:
		node<T>* getNext(){return next;} // Next pointer getters
		T getData(){return data;}
		void setData(T d){data =d;}
		void setNext (node<T>* n){next = n;}
		node():next(0){}
		node(T d):data(d),next(0){}
};
template <class T>
class SinglyCircularLinkedList{
	private:
		node<T>* tail;
	public:
		SinglyCircularLinkedList(){
			tail = NULL;
			tail->setData(-999999);
		}
		void add_node(int d){
			if(tail->getData()==-999999){
				tail->setData(d);
			}
			else{
				node<T> * temp = new node<T>(d);
				tail->setNext(temp);
			}
			
		}
};
int main(){
	SinglyCircularLinkedList<int> CL;
	
	
	return 0;
}
