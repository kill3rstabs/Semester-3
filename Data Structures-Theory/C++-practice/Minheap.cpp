#include <bits/stdc++.h>
using namespace std;
template <class T>
class MinHeap{
	private:
		T * data;
		int capacity;
		int heap_size;
	public:
		MinHeap(int c):heap_size(0),capacity(c),data(new T[c]){}
		void LinearSearch(T val){
			for(int i=0;i<heap_size;i++){
				if(data[i]==val){
					cout<<endl<<"Value found at index "<<i+1;
					return;
				}
				cout<<endl<<"Value not found!";
			}
		}
		void printHeapArray(){
			cout<<endl;
			for(int i=0;i<heap_size;i++){
				cout<<data[i]<<" ";
			}
		}
		int height(){
			return ceil(log2(heap_size + 1)) -1 ;
		}
		int parent(int i){
			return(i-1)/2;
		}
		int left(int i){
			return(2*i+1);
		}
		int right(int i){
			return (2*i+2);
		}
		void insertKey(T d){
			if(heap_size == capacity){
				cout<<endl<<"Heap is full!";
				return;
			}
			
			heap_size++;
			int i = heap_size-1;
			data[i] = d;
			while(i!=0 && data[parent(i)]>data[i]){
				swap(data[i],data[parent(i)]);
				i = parent(i);
			}
		}
		T extractMin(){
			if(heap_size<=0){
				return INT_MAX;
			}
			if(heap_size ==1){
				heap_size--;
				return data[0];
			}
			T root = data[0];
			data[0] = data[heap_size-1];
			heap_size--;
			MinHeapify(0);
			return root;	
		}
		void MinHeapify(int i){
			int l = left(i);
			int r= right(i);
			int smallest = i;
			if(l<heap_size && data[l]<data[i]){
				smallest = l;
			}
			if(r<heap_size && data[r]<data[i]){
				smallest = r;
			}
			if(smallest!=i){
				swap(data[smallest],data[i]);
				MinHeapify(smallest);
			}
		}
		void decreaseKey(int i,int d){
			data[i] = d;
			while(i!=0 && data[parent(i)]>data[i]){
				swap(data[i],data[parent(i)]);
				i = parent(i);
			}
		}
		void deleteKey(int i){
			decreaseKey(i,INT_MIN);
			extractMin();
		}
		void heapSort(){
			T temp[capacity];
			cout<<endl;
			for(int j=0;j<capacity;j++){
				temp[j] = extractMin();
				cout<<temp[j]<<" ";
			}
		}
};




int main(){
	MinHeap<int> h(5);
	h.insertKey(10);
	h.insertKey(6);
	h.insertKey(5);
	h.insertKey(1);
	h.insertKey(3);
//	cout<<endl<<h.extractMin();
	h.printHeapArray();
	h.heapSort();
	
	
	return 0;
}
