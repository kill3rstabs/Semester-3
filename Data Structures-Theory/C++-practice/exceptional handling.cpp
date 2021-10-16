#include <iostream>
using namespace std;
int main(){	
	try{
		char c= 'z';
		if(c != 'c'){
			throw(c);
		}
		
	}
	catch(char x){
		cout<<"Character is not C";
	}
	return 0;
}
