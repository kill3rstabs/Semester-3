#include <iostream>
using namespace std;
template <class T>
void countingsort(T data[], const long n) {
	 long i;
	 long largest = data[0];
	 long *tmp = new long[n];
	 for (i = 1; i < n; i++)		 // find the largest number
	 	 if (largest < data[i])	 // in data and create the array
	 	 	 largest = data[i];	 // of counters accordingly;
	 unsigned long *count = new unsigned long[largest+1];
	 for (i = 0; i <= largest; i++)
	 	 count[i] = 0;
	 for (i = 0; i < n; i++) // count numbers in data[];
	 	 count[data[i]]++;
	 for (i = 1; i <= largest; i++) // count numbers = i;
	 	 count[i] = count[i-1] + count[i];
	 for (i = n-1; i >= 0; i--) {	 // put numbers in order in tmp[];
	 	 tmp[count[data[i]]-1] = data[i];
//	 	 count[data[i]]--;
	 }
	 for (i = 0; i < n; i++)		 // transfer numbers from tmp[]
	 	 data[i] = tmp[i];		 // to the original array;
	 }
int main(){
	int arr[]={5,6,3,2,1};
	countingsort(arr,5);
	for(int i=0;i<4;i++){
		cout<<arr[i]<<",";
	}
	cout<<arr[4];
	return 0;
}
