#include <iostream>
using namespace std;
template <class U>
class Node{
	private:
		U data;
		Node<U>* next;
	public:
		Node(U d):data(d),next(0){}
		template <class T> friend class Stack;
		
};
template <class T>
class Stack{
	private:
		Node<T>* top;
	public:
		Stack():top(0){} //insert at head is push function
		void push(T d){
			Node<T>* temp = top;
			Node<T>* n = new Node<T>(d);
			if(top==NULL){
				top = n;
				return;
			}
			top = n;
			n->next = temp;
		}
		T pop(){ //delete at head
			Node<T>* temp = top;
			Node<T>* temp2 = temp->next;
			if(top==NULL){
				cout<<"Stack is empty";
				return NULL;
			}
			top = temp2;
			return temp->data;
			delete temp;
			
		}
		T peek(){
			Node<T>* temp = top;
			if(temp == NULL){return NULL;}
			return temp->data;
		}
		void display(){
			Node<T>* temp = top;
			while(temp!=NULL){
				cout<<temp->data<<endl;
				temp = temp->next;
			}
		}
};
 
string getInfix(string str){
	Stack<string> s;
	for(int i=0;str[i]!='\0';i++){
		if(isOperand(str[i])){
			string op(1,str[i]);
			s.push(op);
			
		}
		else{
			
			string op1 = s.peek();
			s.pop();
			string op2 = s.peek();
			s.pop();
			s.push("("+ op2 + str[i] + op1 +")");
		}
	}
	return s.peek();
}
int main(){
	string s="ab*c+ab*";
	s = getInfix(s);
	cout<<s;
	return 0;

}
