#include <iostream>
using namespace std;

int main(){
	int n=0;
	int temp;
	
	//asking user for the columns of an array
	cout<<endl<<"Enter the COLUMNS of the array: ";
	cin>>n;
	
	//constructing an array and of n elements and taking elements input
	int arr[n];
	for(int i=0;i<n;i++){
		cout<<endl<<"Enter the element array["<<i+1<<"]: ";
		cin>>arr[i];
	}
	//printing arrays
	cout<<endl<<endl;
	for(int i=0;i<n;i++){
		
			cout<<arr[i]<<",";
	
	}
	
	//sorting arrays in ascending order
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if (arr[j] > arr[j+1]){
				temp = arr[j];
           		arr[j] = arr[j+1];
           		arr[j+1] = temp; 
			}
		}
	}
	
	//printing arrays in ascending order
	cout<<endl<<"Sorted arrays in ascending order";
	for(int i=0;i<n;i++){
		
			cout<<arr[i]<<",";
	
	}
	
	//sorting arrays in descending order
	for (int i = 0; i < ( n - 1 ); i++) {
      for (int j = 0; j < n - i - 1; j++) {
        if (arr[j] < arr[j+1]) 
        {
          temp = arr[j];
          arr[j] = arr[j+1];
          arr[j+1] = temp;
        }
      }
    }
    
    //printing arrays in descending order
	cout<<endl<<"Sorted array in descending order";
	for(int i=0;i<n;i++){
		
			cout<<arr[i]<<",";
	
	}
    
	
	
	return 0;
}