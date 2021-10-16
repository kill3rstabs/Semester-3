#include <iostream>
using namespace std;

void minmax(int &m,int &n){
	cout<<endl<<"Max value is: "<<n;
	cout<<endl<<"Min value is: "<<m;
	
}
int main(){
	int array[]={3,4,5,7,1,-1};
	int *ptr = &array[0];
	int min =999;
	int max =0;
	for(int i=0;i<sizeof(array)/sizeof(array[0]);i++){
		if(*(ptr+i)>max){
			max = *(ptr+i);
		}
		if(*(ptr+i)<min){
			min = *(ptr+i);
		}
	}
	minmax(min,max);
	
	
	return 0;
}