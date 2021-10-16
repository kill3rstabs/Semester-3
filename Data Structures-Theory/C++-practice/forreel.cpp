#include <iostream>
using namespace std;

int main(){
    int n,temp;
    cin>>n;
    int arr[]={6,5,1,4};
    for(int i=0;i<n;i++){
        temp = arr[i];
        int j= i+1;
        while ((j>=0)&&(arr[j]>temp))
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]= temp;
        
    }
    for(int i=0;i<n;i++){
		cout<<arr[i]<<",";
	}



    return 0;
}