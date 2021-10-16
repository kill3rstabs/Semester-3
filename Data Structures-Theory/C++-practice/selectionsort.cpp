#include <iostream>
using namespace std;
int main(){
	int arr[]={5,4,3,7,9};
	int n= sizeof(arr)/sizeof(int);
	for(int i=0;i<n-1;i++){
		int min = i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[min]){
				min = j;
			}
		}
		if(min!=i){
			swap(arr[i],arr[min]);
		}
	}
	
	//printing array
	for(int i=0;i<n;i++){
		cout<<arr[i]<<",";
	}
	
	
	return 0;
}
