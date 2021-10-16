#include <iostream>
#include <climits>
using namespace std;

void MaxSubArray()
{
	int n;
	cin>>n;
    int maxSoFar = INT_MIN,maxend = 0,start = 0,end = 0,j = 0,arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
	}
    if (n <= 0) {
        return;
    }
    for (int i = 0; i < n; i++)
    {
     
        maxend = maxend + arr[i];
 

        if (maxend < arr[i])
        {
            maxend = arr[i];
            j = i;
        }
 

        if (maxSoFar < maxend)
        {
            maxSoFar = maxend;
            start = j;
            end = i;
        }
    }
    for (int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl<<maxSoFar;
}
 
int main()
{
    
 
    MaxSubArray();
 
    return 0;
}
