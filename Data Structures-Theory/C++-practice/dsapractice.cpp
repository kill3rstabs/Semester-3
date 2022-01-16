#include <bits/stdc++.h>
using namespace std;
class IndexOutofBoundException:public exception{
	public:
		virtual const char* what() const throw(){
			
			return "Array index out of bound";
		}
};
class DynamicSafeArray{
	private:
		int** data;
		int row,col;
	public:
		DynamicSafeArray(int r,int c):row(r),col(c){
			data = new int*[row]; // 1. making pointer of rows
			for(int i=0;i<row;i++){
				*(data+i) = new int[col];
				memset(*(data+i),0,sizeof(int)*col);
			}
		}
		void display(){
			for(int i=0;i<row;i++){
				for(int j=0;j<col;j++){
					cout<<data[i][j]<<" ";
				}
				cout<<endl;
			}
			
		}
		int& operator()(int r,int c){
			try{
				if(r<0 || c<0 || c>col || r>row){
					throw IndexOutofBoundException();
				}
			}
			catch(IndexOutofBoundException &e){
				cout<<e.what();
			}
			return *(*(data+r)+c);
		}
		DynamicSafeArray& operator=(const DynamicSafeArray &rhs){
			if(this!=&rhs){
				for(int i=row-1;i>=0;i--){
					if(*(data+i)!=0){
						delete [] *(data+i);
					}
					*(data+i) =0;
				}
				delete []data;
				data =0;
				//copying part
				this->row = rhs.row; // check self reference delete the memory than copy
				this->col = rhs.col;
				data = new int*[row];
				for(int i=0;i<row;i++){
					*(data+i) = new int[col];
					memcpy(*(data+i),*(rhs.data+i),sizeof(int)*col);
				}
			}
			
		}
};
int main(){
	DynamicSafeArray d1(4,4);
	
	d1(0,0)=3;
	d1.display();
	return 0;
}
