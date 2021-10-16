#include <iostream>
using namespace std;

class DynamicSafe2DArray{
	private:
		int row;
		int col;
		int *data;
	public:
		DynamicSafe2DArray():row(0),col(0),data(0){}
		DynamicSafe2DArray(int r,int c):row(r),col(c),data(new int [r*c]){}
		DynamicSafe2DArray(const DynamicSafe2DArray &rhs):row(rhs.row),col(rhs.col){
			data = new int [row*col];
			memcpy(this->data,rhs.data,row*col*sizeof(int));
		}
//		DynamicSafe2DArray(const DynamicSafe2DArray& rhs){
//			row = rhs.row;
//			col = rhs.col;
//			data = new int[col*row];
//			for(int i=0;i<row;i++){
//				for(int j=0;j<col;j++){
//					*(data+((i*col)+j))=*(rhs.data+((i*col)+j));
//				}
//				
//			}
//		}
		
};
int main(){
	DynamicSafe2DArray arr(3,2);
	DynamicSafe2DArray arr2;
	arr2 = arr;
	
}
