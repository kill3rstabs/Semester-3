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
		bool isEmpty(){
			return (top==NULL);
		}
};
bool isOperand(char x){

	return (x>='a' && x<='z') || (x>='A' && x<= 'Z');
}
int precedence(char x){
	if(x == '^'){
		return 3;
	}
	else if(x=='/' || x=='*'){
		return 2;
	}
	else if(x=='+' || x=='-'){
		return 1;
	}
	else{
		return -1;
	}
}
void infixToPostfix(string str){
	Stack<char> s;
	string output;
	for(int i=0;str[i]!='\0';i++){
		if(isOperand(str[i])){
			output+=str[i];
		}
		else if(str[i]=='('){
			s.push('(');
		}
		else if(str[i]==')'){
			while(s.peek()!='('){
				output+=s.pop();
			}
			s.pop();
		}
		else{
			while(!s.isEmpty() && precedence(str[i])<= precedence(s.peek())){
				output+=s.pop();
			}
			s.push(str[i]);
		}
		while(!s.isEmpty()) {
        	output += s.pop();
        
    	}	
    	
		
	}
	cout<<endl<<output;
}
int main(){
	string s="a+b*(c^d-e)^(f+g*h)-i";
	infixToPostfix(s);
	return 0;

}
