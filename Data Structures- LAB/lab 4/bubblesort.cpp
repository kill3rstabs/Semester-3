#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int arr[],int n){
    int temp;
    if(n==1){
        for (int i=0; i < n; i++){
            printf("%d ", arr[i]);
        }
        
        return;
        
    }
    else{
        for(int i=0;i<n;i++){
            if(arr[i]>arr[i+1]){
                temp = arr[i];
                arr[i] = arr[i+1] ;
                arr[i+1] = temp;
            }
        }
        bubbleSort(arr,n-1);
    }
}
int main(){
    int arr[] = {1,2,3,4};
    bubbleSort(arr,4);
    return 0;
}