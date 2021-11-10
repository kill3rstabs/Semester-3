#include <iostream>
#include <stdio.h>
using namespace std;
template <class T>
class DSA{
	private:
		T *data;
		int size;
	public:
		DSA():data(0),size(0){}
		DSA(int s):data(new T[s]),size(s){}
		DSA(const DSA& rhs){
			this->size = rhs.size;
			this->data = new T[this->size];
			memcpy(this->data,rhs.data,size*sizeof(int));
		}
		void resize(T d){
			DSA rhs;
			rhs.data = new T[size];
			memcpy(rhs.data,this->data,size*sizeof(int));
			delete[] data;
			size++;
			data = new T[size];
			for(int i=0;i<size-1;i++){
				*(data+i)=*((rhs.data)+i);
			}
			*(data+size-1)=d;
		}
		void display(){
			for(int i=0;i<size;i++){
				cout<<*(data+i)<<",";
			}
		}
};
int main(){
	DSA<int> d;
	d.resize(4);
	d.resize(3);
	d.resize(1);
	d.display();
	return 0;
}
