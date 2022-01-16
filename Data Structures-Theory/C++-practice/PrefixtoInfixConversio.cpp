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
bool isOperand(char x){

	return (x>='a' && x<='z') || (x>='A' && x<= 'Z');
}
string prefixToInfix(string str){
	Stack<string> s;
	for(int i = str.length()-1;i>=0;i--){
		if(isOperand(str[i])){
			string s1(1,str[i]);
			s.push(s1);
			
		}
		else{
			string op1 = s.pop();
			string op2 = s.pop();
			s.push("("+op1+str[i]+op2+")");
		}
	}
	return s.peek();
}
int main(){
	string s="*-A/BC-/AKL";
	cout<<prefixToInfix(s);
	return 0;

}
