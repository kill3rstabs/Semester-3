#include <iostream>
#include <cstring>
using namespace std;
void maxSubArray(){
	int max_sum = 0,curr_sum =0,j=0,n;
	cin>>n;
	int a[n],arr[n],prev_arr[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		curr_sum += a[i];
		if(curr_sum>max_sum){
			max_sum = curr_sum;
			arr[j] = a[i];
			j++;
		}
		if(curr_sum<0){
			j=0;
			memcpy(prev_arr,a,i);
			curr_sum =0;	
		}
	}
	for(int i=0;i<j;i++){
		cout<<prev_arr[i]<<" ";
	}
	cout<<endl<<max_sum;
}
int main(){
	maxSubArray();
}
