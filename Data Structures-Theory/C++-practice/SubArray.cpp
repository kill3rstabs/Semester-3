#include <iostream>
using namespace std;
int subArray(){
	int max =0,curr_sum =0,j=0,n;
	int store=999999;
	cin>>n;
	int arr[n],sub_arr[n];
	//taking array input
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	//traversing array for checking the max sum
	//discarding the array if it encounters negative numbers
	//retaining prev max
	for(int i=0;i<n;i++){
		curr_sum +=arr[i];
		sub_arr[j]=arr[i];
		j++;
		if(max<curr_sum && store<i){
			j=0;
		}
		
		if(curr_sum>max){
			max = curr_sum;
			
		}
		else{
			store = false;
		}
		if(curr_sum<0){	
			curr_sum=0;
		}
	}
	for(int i=0;i<j;i++){
		cout<<sub_arr[i]<<" ";
		
	}
	cout<<endl<<max;
}
int main(){
	subArray();
	return 0;
}
