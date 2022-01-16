#include <bits/stdc++.h>
using namespace std;
void selectionSort(int arr[],int n){
	int i,j,k;
	for(int i=0;i<n;i++){
		for(int j=k=i;j<n;j++){
			if(arr[j]<arr[i]){
				k=j;
			}
		}
		swap(arr[i],arr[k]);
	}
}
int main(){
	int arr[]={5,4,3,2,1};
	selectionSort(arr,5);
	for(int i=0;i<4;i++){
		cout<<arr[i]<<",";
	}cout<<arr[4];
	
	
	
	return 0;
}
