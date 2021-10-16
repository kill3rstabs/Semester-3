

#include <iostream>
using namespace std;

void sort2(int arr[],int i,int j, int size)
{
	if(j > size-1)
		return;
	if(arr[i] > arr[j])
	{

		swap(arr[i],arr[j]);	
	}
	sort2(arr,i,++j,size);
}


void sort(int arr[],int i,int size)
{
	if(i > size)
		return;
	
	sort2(arr,i,i+1,size);
	sort(arr,++i,size);
}

void display(int arr[],int i,int size)
{
	if(i > size-1)
		return;
	cout << arr[i] << "  ";
	display(arr,++i,size);
}

int main()
{
	int arr[] = {12 ,11, 13, 5, 6, 7,28};
	sort(arr,0,sizeof(arr)/4);
	display(arr,0,sizeof(arr)/4);
}
