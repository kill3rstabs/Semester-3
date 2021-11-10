#include <iostream>
using namespace std;
template <class u>
void printArray(u arr[],int n){
	for(int i=0;i<n-1;i++){
		cout<<arr[i]<<",";
	}
	cout<<arr[n-1];
}
template <class T>
void insertionSort(T arr[],int n){
	for(int i=1;i<n;i++){ // 5,4,3,2,1
		int next = arr[i],j; // next = 5
		for(j=i-1;j>=0 && arr[j]>next;j--){ //j=0 5 > 4 == true
			arr[j+1] = arr[j];	// arr[1] = 5 // hole,5,3,2,1
			
		}
		arr[j+1] = next ; //a[1
	}
	printArray(arr,n);
}

int main(){
	int arr[]={5,4,3,2,1};
	insertionSort(arr,5);
	
	
	return 0;
}
