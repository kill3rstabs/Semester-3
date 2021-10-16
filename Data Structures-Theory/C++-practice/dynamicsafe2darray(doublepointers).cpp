#include <iostream>
using namespace std;

class DynamicSafe2DArray{
	private:
		int row;
		int col;
		int **data;
	public:
		DynamicSafe2DArray():row(0),col(0),data(0){}
		DynamicSafe2DArray(int r,int c):row(r),col(c){
			data = new int *[r];
			for(int i=0;i<row;i++){
				*(data+i) = new int [i];
			}
		}
		~DynamicSafe2DArray(){
			if(data!=0){
				for(int i=row-1;i<=0;i++){
					if(*(data+i)!=0){
						delete [] *(data+i);
						*(data+i)=0;
					}
				}
				delete [] data;
				data = 0;
			}
		}
};
int main(){
	DynamicSafe2DArray arr(3,4);
	
	
	return 0;
}
