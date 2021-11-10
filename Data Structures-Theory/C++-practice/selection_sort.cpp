	#include <iostream>
	using namespace std;
	template <class T>
	void selection_sort(T data[],int n){
		
		for(int i=0;i<n-1;i++){
			int min =i;
			for(int j=i+1;j<n;j++){
				if(data[j]<data[min]){
					min = j;
				}
			}
			swap(data[i],data[min]);
		}
	}
	int main(){
		int data[]={5,4,6,2,1};
		selection_sort(data,5);
		for(int i=0;i<5;i++){
			cout<<data[i];
		}
		return 0;
	}
