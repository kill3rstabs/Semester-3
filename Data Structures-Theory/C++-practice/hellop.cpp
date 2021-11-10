#include <iostream>
using namespace std;
template <class T>
void BubbleSortV2(T arr[],int n){
	for(int i=0;i<n;i++){
		bool swapped = true;
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
				swapped = false;
			}
		}
		if(swapped){
			for(int i=0;i<n;i++){
				cout<<arr[i]<<",";	
			}
			return;
		}
	}
}
int main(){
	int arr[]={5,4,3,2,1};
	BubbleSortV2(arr,5);
	
	
	
	
	return 0;
}
