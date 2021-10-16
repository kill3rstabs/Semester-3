#include <iostream>
using namespace std;
void stringPalindrome(char arr[],int n){
	static int p1 = -1,p2 = n,count =0;
	if(p1 == p2){
		if(count== n/2+1){
			cout<<endl<<"its a palindrome";
		}
		else{
			cout<<endl<<"its not a palindrome";
		}
		return;
	}
	p1++;
	p2--;
	if(arr[p1]==arr[p2]){
		count++;
		stringPalindrome(arr,n);
	}
	else{
		cout<<endl<<"its not a palindrome";
	}
	
}
int main(){
	char str[]="level";
	stringPalindrome(str,sizeof(str));
	
	
	
	
	return 0;
}
