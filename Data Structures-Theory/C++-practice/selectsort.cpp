#include <iostream>
using namespace std;
template <class T>
void selectionSort(T arr[],int n){

	for(int i=0;i<n;i++){
		int minidx = i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<=arr[minidx]){
				minidx = j;
			}
		}
		swap(arr[i],arr[minidx]);
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<",";
	}
}
int main(){
	int arr[]={10,2,5,4,1};
	selectionSort(arr,5);
	return 0;
	}
