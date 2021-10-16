#include <iostream>
#include <exception>
using namespace std;

class IndexOutOfBoundException: public exception{
	public:
	virtual const char* what() const throw()
  {
    return "Array Index out of bound";
  }
};
template <class T>
class DynamicSafe2DArray{
	private:
		T **data;
		int row;
		int col;
	public:
		DynamicSafe2DArray():row(0),col(0),data(0){
			
		}
		DynamicSafe2DArray(int r,int c):row(c),col(c){
			data= new T*[row];
			for(int i=0;i<row;i++){
				*(data+i)= new T[col];
				for(int j=0;j<col;j++){
					*(*(data+i)+j) = 0;
				}
			}
		}
		DyamicSafe2DArray(const DynamicSafe2DArray &rhs){
			this->row = rhs.row;
			this->col = rhs.col;
			data = new T*[row];
			for(int i=0;i<row;i++){
				*(data+i) = new T[col];
				memcpy(*(data+i),*(rhs.data+i),sizeof(T)*col);
			}
			
		}
		T& operator()(int r,int c){
			try{
				if(r<0 || c<0 || c>col || r>row){
					throw IndexOutOfBoundException();
				}
			}
			catch(IndexOutOfBoundException &e){
				cout<<e.what();
			}
			return *(*(data+r)+c);
		}
		 
		~DynamicSafe2DArray()
      {
      	if (data != 0)
         {
         	for (int i=row-1; i>=0; i--)
            {
            	if (*(data+i) != 0)
               	delete [] *(data+i);
               *(data+i) = 0;
            }
            delete [] data;
         }
         data = 0;
      }
    DynamicSafe2DArray& operator=(const DynamicSafe2DArray &rhs){
      	int lrow =rhs.row;
      	int lcol =rhs.col;
      	
		  if(this!=&rhs){
		  	
      		for(int i=row-1;i<0;i++){
      			if(*(data+i)!=0){
      				delete [] *(data+i);
      				*(data+i)=0;
				  }
			  }
			  delete [] data;
			  data =0;
			  //copying part
			  this->row = lrow;
			  this->col = lcol;
			  data = new T*[row];
			  for(int i=0;i<row;i++){
				*(data+i) = new T[col];
				memcpy(*(data+i),*(rhs.data+i),sizeof(T)*col);
		  }
	  }
	  
	  
	}
	void Display(){
		cout<<endl;
		for(int i=0;i<row;i++){
			for(int j =0;j<col;j++){
				cout<<*(*(data+i)+j);
			}
			cout<<endl;
		}
		cout<<endl;
	}
	  
		
};
int main(){
	DynamicSafe2DArray<int> arr(3,3);
	int a;
	arr(0,0)=3;
	arr(0,1) = 4;
	a= arr(0,1);
	DynamicSafe2DArray<int> arr2(3,3);
	arr2 = arr;
	cout<<endl<<a;
	arr.Display();
	arr2.Display();
	
	
	
	return 0;
}
