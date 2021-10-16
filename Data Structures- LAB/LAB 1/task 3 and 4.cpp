#include<iostream>
using namespace std; 


 
int func(int x){
	int sum=0;
	
	if(x>0){
		for(int i=1;i<x;i++){
			if(x%i==0){
				cout<<i<<" ";
				sum=sum+i;
			}
			
		}
		cout<<endl<<"SUM: "<<sum;
			
	}
		
	else{
		cout<<"ENTER POSITIVE!!!!";
	}
	
}



int main(){

	
		int x;
		cout<<endl<<"Enter a number: ";
		cin>>x;
		
		func(x);
	
	
}