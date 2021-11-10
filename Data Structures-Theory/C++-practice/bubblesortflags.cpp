#include <iostream>
using namespace std;
template <class T>
void BubbleSortV2(T arr[],int n){
	int comps=n-1,sorted = 0;
	while(!sorted){
		sorted = 1;
		for(int i=0;i<comps;i++){
			if(arr[i]>arr[i+1]){
				swap(arr[i],arr[i+1]);
				sorted = 0;
			}
		}
		comps--;
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<",";
	}
}
int main(){
	int arr[]={5,4,3,2,1};
	BubbleSortV2(arr,5);
	
	
	return 0;
}
