#include <iostream>
using namespace std;

int main(){
	float total = 0;
	float row0[] = {3.66,3.33,4.0,3.0,2.66};
	float row1[] = {3.33,3.0,3.66,3.0};
	float row2[] = {4.0,3.66,2.66};
	float row3[] = {2.66,2.33,4.0};
	float row4[] = {3.33,3.66,4.0,3.0,3.33};
	
	float *jagged[5] = {row0,row1,row2,row3,row4};
	int size[5] = {5,4,3,3,5},k=0;
	
	for(int i=0;i<5;i++){
		float *ptr = jagged[i];
		for(int j=0;j<size[k];j++){
			total += *(ptr+j);
			cout<<*(ptr+j)<<",";
		}
		
		cout<<endl;
		cout<<endl<<"GPA : "<<total/size[k]<<endl;
		total = 0;
		k++;
		jagged[i]++;
	}

	return 0;
}