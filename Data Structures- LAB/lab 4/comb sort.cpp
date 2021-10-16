#include <iostream>
using namespace std;
int get_next_gap(int gap){
    gap = (gap*10)/13;
    if(gap<1){
        return 1;
    }
    return gap;
}
void combSort(int arr[],int n){
    int gap = n;
    bool swapped = true;
    while(gap !=1 || swapped == true){
        gap = get_next_gap(gap);

        swapped = false;
 
        // Compare all elements with current gap
        for (int i=0; i<n-gap; i++)
        {
            if (arr[i] > arr[i+gap])
            {
                swap(arr[i], arr[i+gap]);
                swapped = true;
            }
        }
    }
}
int main(){
    int arr[] = {7,2,3,4,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    combSort(arr,n);
    cout<<endl<<"Sorted array:";
    for (int i=0; i<n; i++)
        cout<<endl<<arr[i];
    return 0;
}