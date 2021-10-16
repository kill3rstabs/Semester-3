#include <iostream>
using namespace std;

class Number{
	private:
		int size;
		int *var1;
		int *var2;
	public:
		Number(){
			
		}
		Number(int size,int v1,int v2){
			this->size = size;
			var1 = new int;
			*var1 = v1;
			var2 = new int;
			*var2 = v2;
		}
//		Number(int size,int v1,int v2){
//			this->size = size;
//			var1 = v1;
//			var2 = v2;
//		}
		Number(Number &obj){
			var1 = new int;
			*var1 = *obj.var1;
			var2 = new int;
			*var2 = *obj.var2;
		}
		void display(){
			cout<<endl<<"Size: "<<size;
			cout<<endl<<"Var1: "<<*var1;
			cout<<endl<<"Var2: "<<*var2;
		}
}; 
int main(){
	Number n(3,3,2);
	Number n1;
	n1=n;
	n.display();
	n1.display();
	return 0;
}