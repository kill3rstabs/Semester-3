#include <iostream>
#include <cstring>
using namespace std;
class Arrayupperoutofbound{
	public:
    virtual const char * what() const throw(){
        return "Array upper out of bound";
    }
};
class Arrayloweroutofbound{
	public:
    virtual const char * what() const throw(){
        return "Array lower out of bound";
    }
};
class DynamicSafeArray{
    private:
        int *data;
        unsigned int size;
    public:
        DynamicSafeArray():data(0),size(0){

        }
        DynamicSafeArray(int s): data(new int[s]),size(s){
            memset(this->data,0,sizeof(s));
        }
        DynamicSafeArray(const DynamicSafeArray &rhs){
            this->size = rhs.size;
            this->data = new int [size];
            memcpy(this->data,rhs.data,sizeof(int)*size); //copying the data array of left hand side to rhs

        }
        DynamicSafeArray& operator=(const DynamicSafeArray &rhs){
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
        int& operator [] ( int i){
            try{
                if(i<0){
                    throw Arrayloweroutofbound();
                }
                if(i>size-1){
                    throw Arrayupperoutofbound();
                }
                return *(data+i);
            }
            catch(Arrayupperoutofbound &u){
                cout<<endl<<u.what();
            }
            catch(Arrayloweroutofbound &l){
                cout<<endl<<l.what();
            }
			
		}
        ~DynamicSafeArray(){
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
    DynamicSafeArray arr(3);
	
	arr[1]=5;
	
	DynamicSafeArray arr1(arr);
	
	arr1[0]=2;
	arr1[2] = 3;
    arr1[0] = 3;
    
	arr1.display();


    return 0;
}