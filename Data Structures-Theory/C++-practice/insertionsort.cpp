#include <iostream>
using namespace std;
template <class T>
void insertion_sort(T data[],int n){
	T temp,j; 
	for(int i=0;i<n;i++){
		temp = data[i];
		j= i-1;
		while(j>=0 && data[j]>temp){
			data[j+1]=data[j];
			j--;
		}
		data[j+1]=temp;
	}
}
int main(){
	int arr[]={5,4,3,2,1};
	insertion_sort(arr,5);
	
		cout<<*arr+2;
	
	
	
	
	return 0;
}
