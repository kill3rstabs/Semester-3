#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
class CircularQueue{
	private:
		int front,rear,capacity,itemCount;
		int *arr;
	public:
		CircularQueue(int c):front(-1),rear(-1),itemCount(0),capacity(c),arr(new int[c]){
			memset(arr,0,sizeof(int)*c);
		}
		
		bool isEmpty(){
			if(front==-1 && rear ==-1){return true;}
			return false;
		}
		
		
		bool isFull(){
			if((rear+1)%capacity ==front){
				return true;
			}
			return false;
		}
		
		
		void enqueue(int value){
			if(isFull()){
				cout<<endl<<"Queue is full!";
				return;
			}
			else if(isEmpty()){
				front = 0; rear =0;
				arr[rear] =  value;
			}
			else{
				rear = (rear+1)%capacity;
				arr[rear] = value;
			}
			itemCount++;
		}
		
		
		
		int dequeue(){
			int x =0;
			if(isEmpty()){
				cout<<endl<<"Queue is Empty!";
				return x;
			}
			else if(rear == front){ // last value left to be dequeued
				x= arr[rear]; // the value which has to be dequeued 
				rear = -1; // rear = -1
				front = -1; //front = -1;
				itemCount--; 
				return x;
			}
			else{
				cout<<"front value: "<<front<<endl;
				x = arr[front]; // x mein front ki value daali
				arr[front] = 0; // front ko khaali kiya
				front = (front+1)%capacity; // front ko increment kiya
				itemCount--; // itemcount decrement hua
				return x;
			}
		}
		void display(){
			cout<<endl;
			for(int i=0;i<capacity;i++){
				cout<<arr[i]<<" ";
			}
		}
};
int main(){
	CircularQueue q(5);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.display();
	q.dequeue();
	q.display();
	q.enqueue(1);
	q.display();
	q.enqueue(5);
	
	return 0;
}
