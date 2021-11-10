#include <iostream>
using namespace std;

int main(){
	int r;
	cout<<endl<<"Enter number of rows: ";
	cin>>r;
	int number =0;
	int * jagged[r],size[r];
	for(int i=0;i<r;i++){
		cout<<"Enter number of columns in row "<<i<<" : ";
		cin>>size[i];
		jagged[i] = new int[size[i]];
	}
	int k=0;
	for(int i=0;i<r;i++){
		int* p = jagged[i];
		for(int j=0;j<(size[k]);j++){
			cout<<endl<<"Enter element ["<<i<<"]"<<"["<<j<<"]:";
			cin>>*p;
			p++;
		}
		k++;
	}
	k = 0;
  
    // Display elements in Jagged array
    for (int i = 0; i < r; i++) {
  
        int* p = jagged[i];
        for (int j = 0; j < size[k]; j++) {
  
            printf("%d ", *p);
            // move the pointer to the next element
            p++;
        }
        printf("\n");
        k++;
        // move the pointer to the next row
        jagged[i]++;
    }
  
    return 0;
}
