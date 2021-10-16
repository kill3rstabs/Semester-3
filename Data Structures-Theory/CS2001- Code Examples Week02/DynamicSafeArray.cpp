#include<iostream>
#include<stdio.h>

#include <bits/stdc++.h>
using namespace std;

class dsa{
	int *data;
	int size;
	
	public:
		dsa():data(NULL),size(0)
		{
			
		}
		
		dsa(int s):data(new int[s]),size(s)
		{
			for(int i=0;i<s;i++){
				data[i]=0;
			}
		}
		
		dsa(const dsa& rhs){
			this->size=rhs.size;
			this->data=new int [size];
			
			memcpy(this->data,rhs.data,size*sizeof(int));
		}
		
		
		
		
		dsa& operator = (const dsa & rhs){
			if(this->data!=rhs.data && this->size!=rhs.size){
				this->size=rhs.size;
				
				delete[] this->data;
				this->data= new int [this->size];
				
				memcpy(this->data,rhs.data,sizeof(int));
				
			}
			else{
				return *this;
			}
		}
		
		
		
		
		
		int& operator [] (unsigned int i){
			return *(data+i);
		}
		
		
		
		~dsa(){
			if(this->data!=0){
				delete[] this->data;
				this->data=0;
				this->size=0;
			}
		}
		
		
		void display(){
			
			cout<<"SIZE: "<<this->size<<endl;
			
			for(int i=0;i<this->size;i++){
				cout<<data[i]<<" ";
			}
			
		}
};

int main(){
	
	dsa arr(3);
	
	arr[1]=5;
	
	dsa arr1(arr);
	
	arr1[0]=2;
	arr1[5]=5;
	arr1.display();
	
}
