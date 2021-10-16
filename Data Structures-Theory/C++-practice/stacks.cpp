#include <iostream>
using namespace std;
template <typename T,int size>
class Stack{
	private:
		int count;
		T arr[size+1];
	public:
		Stack(){
			for (int i=1;i<=size;i++){
				arr[i]=0;
			}
			count =0;
		}
		void push(T val){
			if(isFull()){
				cout<<endl<<"Stack overflow";
			}
			else{
				count++;
				arr[count] = val;
			}
			
		}
		void pop(){
			cout<<endl<<arr[count]<<endl  ;
			arr[count] = 0;
			count--;
		}
		bool isEmpty(){
			if(count==0){
				return true;
			}
			else{
				return false;
			}
		}
		bool isFull(){
			if(count ==size){
				return true;
			}
			else{
				return false;
			}
		}
		void peek(int index){
			cout<<endl<<"You peeked at: "<<arr[index]<<endl;
		}
		void display(){
			cout<<"Stack: ";
			for (int i =size ;i >= 1; i--){
				cout<<arr[i]<<",";
			}
		}
		
};
int main(){
	Stack<int,5> s;
	
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.push(30);
	s.peek(3);
	s.pop();
	s.pop();
	s.display();
	
	
	return 0;
}
