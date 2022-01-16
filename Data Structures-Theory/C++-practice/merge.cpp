#include <iostream>
using namespace std;
template <class U>
void merge(U arr[],int l,int mid ,int h){
	int i=l,j=mid+1,k=l;
	U b[l];
	while(i<=mid && j<=h){
		if(arr[i]<arr[j]){
			b[k++]=arr[i++];
		}
		else{
			b[k++]=arr[j++];
		}
	}
	for(;i<=mid;i++){
		b[k++] = arr[i];
	}
	for(;j<=h;j++){
		b[k++]= arr[j];
	}
}
template <class T>
void mergeSort(T arr[],int l,int h){
	if(l<h){
		int mid = (l+h)/2;
		mergeSort(arr,l,mid);
		mergeSort(arr,mid+1,h);
		merge(arr,l,mid,h);
	}
	
}
int main(){
	int arr[]={5,4,3,2,1};
	mergeSort(arr,0,5);
	
	
	
	
	
	return 0;
}
