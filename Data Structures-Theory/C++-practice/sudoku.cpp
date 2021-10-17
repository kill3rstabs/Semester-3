#include <iostream>

using namespace std;
class IndexOutOfBoundsException: public exception
{
public:
  virtual const char* what() const throw()
  {
    return "My exception happened";
  }
};
template <class T>
class DynamicSafe2DArray
{
	private:
   	  T** data;
      int row, col;

   public:
	  
	  DynamicSafe2DArray(): data(0), row(0), col(0) {}
     
	  DynamicSafe2DArray(int row, int col)
      {
      	this->row = row;
         this->col = col;
         data = new T*[row];
         for (int i=0; i<row; i++)
         {
         	*(data+i) = new T[col];
            for (int j=0; j<col; j++)
            	*(*(data+i)+j) = 0;
         }
      }

      DynamicSafe2DArray(const DynamicSafe2DArray& rhs)
      {
         row = rhs.row;
         col = rhs.col;

         data = new T*[row];
         for (int i=0; i<row; i++)
         {
         	*(data+i) = new T[col];
            memcpy(*(data+i),*(rhs.data+i), sizeof(T)*col);
         }
      }

      DynamicSafe2DArray& operator=(const DynamicSafe2DArray& rhs)
      {
      if( this != &rhs)
      {
      
         for (int i=row-1; i>0; i++)
         	delete[] *(data+i);
			delete[] data;

         row = rhs.row;
         col = rhs.col;

         data = new T*[row];
         for (int i=0; i<row; i++)
         {
         	*(data+i) = new T[col];
            memcpy(*(data+i),*(rhs.data+i), sizeof(T)*col);
         }
       }
         return *this;
      }

   	T& operator()(int rowIndex, int colIndex)
      {
      	try{
      		if (rowIndex < 0 || colIndex < 0 || rowIndex >= row || colIndex >= col)
         	throw IndexOutOfBoundsException();
         else
         	return *(*(data+rowIndex)+colIndex);
		}
		catch(IndexOutOfBoundsException &e){
      		e.what();
	  	}
      }
      
      
      int getRow() {return row;}
      int getCol() {return col;}

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
};
int main() {
	
	int box = 0;
	DynamicSafe2DArray<int> arr(9,9);
	int flag[9]={0,0,0,0,0,0,0,0,0}; 
	
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cin>>arr(i,j);
		}
	}
	
	for(int i=0;i<9;i++){
		arr(8,i)=0;
	}
	
	for(int i=0;i<9;i++){
		arr(i,8)=0;
	}
	
	
	
	

	for(int i=0;i<8;i++){
		box=0;
		
		
		
		for(int k=0;k<9;k++){
			
			flag[(arr(i,k))-1]=1;
			
		}
		
		
	
		
		for(int k=0;k<9;k++){
			if(flag[k]==0){
				box=k+1;
				break;
			}
		}
			
		
		arr(i,8)=box;
		
		
		
		
		
		for(int k=0;k<9;k++){
			flag[k]=0;
		}
			
				
	}
	
	
	
	for(int i=0;i<9;i++){
		box=0;
		
		
		
		for(int k=0;k<9;k++){
			
			flag[(arr(k,i)-1)]=1;
			
		}
		
		
	
		
		for(int k=0;k<9;k++){
			if(flag[k]==0){
				box=k+1;
				break;
			}
		}
			
		
		arr(8,i)=box;
		
		
		
		
		
		for(int k=0;k<9;k++){
			flag[k]=0;
		}
		
		
		
				
	}
	

	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<arr(i,j)<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<arr(10,10);

	return 0; 
}