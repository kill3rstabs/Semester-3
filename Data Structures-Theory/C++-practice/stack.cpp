#include <iostream>
#include <cstring>
#define SIZE 100
using namespace std;
template <class T>
class Node{
	private:
		T data;
		Node<T>* next;
	public:
		Node():data(0),next(0){}
		Node(T d):data(d),next(0){}
		template <class u> friend class Stack;
};
template <class u>
class Stack{
	private:
		Node<u>* top;
	public:
		Stack():top(0){}
		u getTop(){return top->data;}
		void push(u d){
			Node<u>* temp= top;
			Node<u>* newnode = new Node<u>(d);
			if(top==NULL){
				top = newnode;
				return;
			}
			top = newnode;
			newnode->next = temp;
		
		}
		u pop(){
			Node<u>* temp = top;
			temp= temp->next;
			Node<u>* temp2 =top;
			temp2->next = NULL;
			top = temp;
			return temp2->data;
			
		}
		bool isEmpty(){
			if(top==0){
				return true;
			}
			else{
				return false;
			}
		}
		void peek(int n){
			int size = 0;
			int count =0;
			Node<u>* temp= top;
			while(temp->next!=NULL){
				temp=temp->next;
				size++;
			}
			
			temp = top;
			if(n<0 || n>size){
				cout<<"out of bound"<<endl;
				return;
			}
			while(n!=count){
				temp=temp->next;
				count++;
			}
			cout<<temp->data<<endl;
		}
		void display(){
			Node<u>* temp= top;
			do{
				cout<<temp->data<<"->";
				temp = temp->next;
			}while(temp!=NULL);
		cout<<"NULL";
		}
};
int prec(char c){
	if(c =='^'){
		return 3;
	}
	else if(c=='/'|| c=='*'){
		return 2;
	}
	else if(c=='+'||c=='-'){
		return 1;
	}
	else{
		return -1;
	}
}

void infixToPostfix(string s){
	Stack<char> st;
	string result;
	
	for(int i=0;i<s.length();i++){
		char c = s[i];
		if((c>='a' && c<='z')||(c>='A' && c<='Z')||(c>='0' && c<='9')){
			result +=c;
		}
		else if(c=='('){
			st.push('(');
		}
		else if(c==')'){
			while(st.getTop()!='('){
				result+=st.getTop();
				st.pop();
			}
			st.pop();
	 	}
	 	else{
	 		while(!st.isEmpty() && (prec(s[i])<=prec(st.getTop()))){
	 			result+=st.getTop();
	 			st.pop();
			 }	
		}
	 
	}
	 while(!st.isEmpty()) {
        result += st.getTop();
        st.pop();
    }
 
    cout << result << endl;
}





int main(){
	string exp = "a+b";
    infixToPostfix(exp);
    
	return 0;
}

