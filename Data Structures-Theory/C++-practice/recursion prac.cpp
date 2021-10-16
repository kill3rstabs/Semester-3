#include <iostream>
using namespace std;
void decimalToBinary(int n){	
	if(n==1){
		if(n%2==0){
			
		}
	}
	else{
		cout<<n%2;
		decimalToBinary(n/2);
		 
	}
}
int main(){
			
	decimalToBinary(66);
	
	
	
	return 0;
}
