#include <Bits/stdc++.h>
using namespace std;
int* CountSort(int *data,int n,int k){
	int * count = new int[k+1];
	for(int i=0;i<n;i++){
		count[i]=0;
	}
	for(int i=0;i<n;i++){
		count[data[i]]++;
	}
	int i=0,j=0;
	while(i<k+1){
		if(count[i]>0){
			data[j++]=i;
			count[i]--;
		}
		else{
			i++;
		}
	}
	return data;
}
int main(){
	int arr[]={4,5,6,1,2};

	int * data = CountSort(arr,5,6);
	for(int i=0;i<4;i++){
		cout<<data[i]<<",";
	}
	cout<<data[4];
	return 0;
}
