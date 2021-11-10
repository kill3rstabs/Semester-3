#include <iostream>
using namespace std;
template <class T>
void insertionSort(T data[],int n){
	T temp;
	for(int i=1,j;i<n;i++){
		temp= data[i];
		j=i-1;
		while(j>=0 && data[j]>temp){
			data[j+1]=data[j];
			j--;
		}
		data[j+1]=temp;
	}
}
int main(){
	int arr[]={5,4,3,2,1};
	insertionSort(arr,5);
	for(int i=0;i<5;i++){
		cout<<arr[i];
	}
	
	
	
	return 0;
}
