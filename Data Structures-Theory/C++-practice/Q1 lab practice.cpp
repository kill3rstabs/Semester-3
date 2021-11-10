#include <iostream>
#include <cstring>
using namespace std;
template <class T>
class DSA{
	private:
		T *data;
		int size;
	public:
		DSA():data(0),size(0){
		}
		DSA(int s):data(new T[s]),size(s){
			memset(data,0,size*sizeof(T));
		}
		DSA(const DSA& rhs){
			this->size = rhs.size;
			this->data = new T[this->size];
			memcpy(this->data,rhs.data,size*sizeof(T));
		}
		DSA& operator = (const DSA & rhs){
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
		T& operator[](int i){
			
			return *(data+i);
		}
		
		void display(){
			for(int i=0;i<size;i++){
				cout<<*(data+i)<<",";
			}
		}
};
int main(){
	int k;
	cout<<endl<<"Enter the value of k: ";
	cin>>k;
	DSA<int> arr(4);
	arr[0]=10;
	arr[1]=4;
	arr[2]=2;
	arr[3]=6;
	arr.display();
	
	
	return 0;
}
