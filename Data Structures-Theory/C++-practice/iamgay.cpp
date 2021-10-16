#include <iostream>
using namespace std;
int recurse(int n){
	
	if(n<=1){
		return 1;
	}
	else{
		return n-2+recurse(n-1);
	}
}
int main(){
	cout<<endl<<recurse(8);
	
	

	return 0;
}
