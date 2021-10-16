#include <iostream>
using namespace std;
int sum(int num){
	static int total = 0;
	if(num!=0){
		total = num + sum(num-1);
	}
	else{
		return total;
	}
}
int main(){
	int c =sum(3);
	cout<<c;
	
	return 0;
}
