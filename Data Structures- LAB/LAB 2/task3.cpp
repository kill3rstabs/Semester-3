#include <iostream>
using namespace std;
bool flag = true;
int main(){
	int temp[5];
	int arr[n];
	for(int i=0;i<n;i++){
		cout<<endl<<"Enter array element ["
	}
	int min = 0;
	int max = 5 -1;
	int i=0,j=1;
	while(max+2 != min){
		if(flag){
			temp[i]= arr[max];
			i++;
			max--;
		}
		else{
			temp[i] = arr[min];
			i++;
			min++;
		}
		flag = !flag;
		
		
	}
	for(int i=0;i<5;i++){
		cout<<endl<<temp[i];
	}
	
	
	return 0;
}