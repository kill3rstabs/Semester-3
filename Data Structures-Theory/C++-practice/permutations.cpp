#include <iostream>
#include <string.h>
#include <windows.h>  
using namespace std;

void findPermutations(char str[],int left,int right){
	if(left == right){
		cout<<str;
	}
	else{
		for(int i= left;i<right;i++){
			swap(str[left],str[i]);
			findPermutations(str,left+1,right);
			swap(str[left],str[i]);
		}
	}
	
}
int main(){
	char str[100];
	
	fgets(str,100,stdin);
	system("Color 0A");
	cout<<endl<<endl<<endl<<endl<<endl;
	findPermutations(str,0,strlen(str)-1);
	
}
