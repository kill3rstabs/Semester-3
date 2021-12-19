#include<iostream>
using namespace std;
#include<iostream>
using namespace std;

class Stack{
	int top;
	
	public:
		char a[99];
		
		Stack(){
			top=-1;
			
		}
		
		bool push(int x){
			if(top>=99-1){
				cout<<"Stack Overflow\n";
				return false;
			}
			else{
				a[++top]=x;
				//cout<<x<<" pushed into stack\n";
				return true;
			}
		}
		
		int pop(){
			if(top<0){
				cout<<"Stack Underflow\n";
				return 0;
			}
			else{
				int x=a[top--];
				return x;
				
			}
		}
		
		int peek(){
			if(top<0){
				cout<<"Stack is Empty";
				return 0;
			}
			else{
				int x=a[top];
				return x;
			}
		}
		
		bool isEmpty(){
			return(top<0);
		}
};

int prec(char c){
	if(c=='^'){
		return 3;
	}
	else if(c=='*' || c=='/'){
		return 2;
	}
	else if(c=='+' || c=='-'){
		return 1;
	}
	else{
		return -1;
	}
}

int main(){
	Stack list;
	
	char val;
	string result, str;
	
	cout<<"Enter formula: ";
	getline(cin,str);
	
	for(int i=0;i<str.length();i++){
		char ch=str[i];
		
		if(isalnum(ch)){
			result=result+ch;
		}
		else if(ch=='('){
			list.push(ch);
		}
		else if(ch=='^'){
			list.push(ch);
		}
		else if(ch==')'){
			while(!list.isEmpty()&&list.peek() != '(' ){
				result+=list.pop();
				list.pop();
			}
			
		}
		else{
			while(!list.isEmpty() && prec(ch) <= prec(list.pop())){
				result+=list.pop();
			}
			list.push(ch);
		}
	}
	
	while(!list.isEmpty()){
		result+=list.pop();
	}
	
	cout<<result;
	
}
