#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template <class T>
class MaxHeap{
	private:
		T* data;
		int capacity;
		int heapSize;
	public:
		MaxHeap(int c):data(new T[c]),capacity(c),heapSize(0){}
		void printArray(){
			for(int i=0;i<heapSize;i++){
				cout<<data[i]<<" ";
			}
		}
		int parent(int i){
			return (i-1)/2;
		}
		int left(int i){
			return (2*i+1);
		}
		int right(int i){
			return (2*i+2);
		}
		void insert(T d){
			if(heapSize == capacity){
				cout<<endl<<"FULL!";
				return;
			}
			heapSize++;
			int i = heapSize-1;
			data[i] = d;
			while(i!=0 && data[parent(i)]<data[i]){ //parent should be larger if data is larger than swap should be performed 
				swap(data[i],data[parent(i)]);
				i = parent(i);
			}
		}
		T extractMax(){
			if(heapSize <= 0){return INT_MAX;}
			if(heapSize == 1){
				heapSize--;
				return data[0];
			}
			T root = data[0];
			data[0] == data[heapSize-1];
			heapSize--;
			MaxHeapify(0);
			return root;
		}
		void MaxHeapify(int i){
			int l = left(i);
			int r = right(i);
			int largest = i;
			if(l<heapSize && data[l]>data[i]){
				largest = l;
			}
			if(r<heapSize && data[r]>data[i]){
				largest = r;
			}
			if(largest!=i){
				swap(data[largest],data[i]);
				MaxHeapify(largest);
			}
		}
		void decreaseKey(int i,T d){
			data[i] = d;
			while(i!=0 && data[parent(i)]<data[i]){
				swap(data[i],data[parent(i)]);
				i = parent(i);
			}
		}
		void deleteKey(int i){
			decreaseKey(i,INT_MIN);
			extractMax();
		}
		void HeapSort(){
			T temp[capacity];
			cout<<endl;
			for(int i =0;i<capacity;i++){
				temp[i] = extractMax();
				cout<<temp[i]<<" ";
			}
			
		}
};
int main(){
	MaxHeap<int> h(4);
	h.insert(4);
	h.insert(1);
	h.insert(10);
	h.insert(69);
	h.printArray();
	h.HeapSort();
	
	
	return 0;
}
