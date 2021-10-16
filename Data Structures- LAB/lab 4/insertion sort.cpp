#include <iostream>
using namespace std;
void insertionSort(int arr[],int n){
    int hole,value;
    for(int i=0;i<n-1;i++){
        value = arr[i];
        hole = i;
        while(hole>0 && arr[hole-1]>value){
            arr[hole] =arr[hole -1];
            hole = hole - 1;
        };
        arr[hole] = value;
    }
}
int main(){
    int arr[]={1,5,6,7};
    insertionSort(arr,4);
    for(int i=0;i<4;i++){
        cout<<endl<<arr[i];
    }
    return 0;
}