#include<iostream>

using namespace std;



int raju(int n){
if (n<=0)
return 0;
else if(n==1)
return 1;
else if(n==2)
return 2;
else if(n==4)
return 6;
else
return raju(n-1)+raju(n-2)+raju(n-4);

	}

int main(){
	
	
	
	cout<<raju(10);
}
