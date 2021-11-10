#include <iostream>
using namespace std;

template <class T>
void merge(T arr[],int lb,int mid,int ub){
	int i = lb,j = mid+1,k = lb,b[ub];
	while(i<= mid && j<=ub){
		if(arr[i]<=arr[j]){
			b[k]=arr[i];
			i++;
		}
		else{
			b[k]=arr[j];
			j++;
		}
		k++;
		
	}
	if(i>mid){
		while(j<=ub){
			b[k]=arr[j];
			j++;
			k++;
		}
	}
	else{
		while(i<=mid){
			b[k]=arr[i];
			i++;
			k++;
		}
	}
}
template <class u>
u* mergeSort(u arr[],int lb,int ub){
	if(lb<ub){
		int mid = (lb+ub)/2;
		mergeSort(arr,lb,mid);
		mergeSort(arr,mid+1,ub);
		merge(arr,lb,mid,ub);
	}
	return *arr;
	
}

int main(){
	int arr[]={5,4,3,2,1};
	mergeSort(arr,0,5);
	
	
	
	cout<<"Sorted Array: ";
	
	for(int i=0;i<4;i++){
		cout<<arr[i]<<",";
	}
	cout<<arr[4];
	return 0;
	
}
