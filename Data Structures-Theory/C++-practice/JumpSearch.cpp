#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <class T>
int JumpSearch(T *data,int n,T element){
	int jump = sqrt(n),low =0;
	for(int i=0;i<n;i+=jump){
		if(data[i]==element){
			return i;
		}
		if(data[i]<element){
			low = i;
		}
		if(data[i]>element){
			break;
		}
	}
	for(int i=0;i<n;i++){
		if(data[i]==element){
			return i;
		}
	}
}
int main(){
	int arr[]={4,3,5,6,7,1,-1};
	cout<<endl<<JumpSearch(arr,sizeof(arr)/sizeof(int),-1);
	
	return 0;
}
