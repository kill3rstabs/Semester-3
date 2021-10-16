#include <iostream>
using namespace std;
class Complex{
	private:
		int x;
		int y;
	public:
		Complex(){
		}
		Complex(int x,int y){
			this->x=x;
			this->y=y;
		}
		void display(){
			cout<<"X: "<<x;
			cout<<"Y: "<<y;
		}
		friend Complex operator+(Complex &,Complex &);
};
Complex operator+(Complex &c1,Complex &c2){
	Complex temp;
	temp.x = c1.x +c2.x;
	temp.y = c1.y +c2.y;
	return temp; 
}
int main(){
	Complex c1(3,4);
	Complex c2(4,5);
	Complex c3;
	c3 = c1 +c2;
	c3.display();
	return 0;
}





















