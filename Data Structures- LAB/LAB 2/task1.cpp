#include <iostream>
using namespace std;

int main(){
	int m=0,n=0;
	int count1 =0;
	int count0 = 0;
	cout<<endl<<"Enter the rows of the matrix: ";
	cin>>m;
	cout<<endl<<"Enter the column of the matrix: ";
	cin>>n;
	if(m==n){
		cout<<endl<<"Its a square matrix!";
	}
	
	
	
	
	
	
	int arr[m][n];
	for(int i=0;i<m;i++){
		for(int j= 0; j<n ;j++){
			cout<<endl<<"Enter the value of row "<<i+1<<" column"<<j+1;
			cin>>arr[i][j];
		}
	}
	
	
	
	
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i==j && arr[i][j] ==1){
				count1++;	
			}
			if(i!=j && arr[i][j] ==0 ){
				count0++;
			}
		}
	}
	
		for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<"  ";
		}
		cout<<endl;
	}
//	cout<<count0;
//	cout<<endl<<count1;
	if(count0 == (count1)*(m-1) && count1 == m){
		cout<<endl<<"your matrix is identity ";
	}
	else{
		cout<<endl<<"hello";
	}
	
	
}