#include <iostream>
using namespace std;

class Point2D{
    int *x;
    int *y;
    public:
        Point2D();
        Point2D(int a, int b);
//        Point2D(const Point2D &rhs);
//        Point2D& operator=(const Point2D &rhs);
        void display(){
            cout<<endl<<"X: "<<*x;
            cout<<endl<<"Y: "<<*y;
        }
        int get_x()const{
            return *x;
        }
        int get_y() const{
            return *y;
        }
};
Point2D:: Point2D() : x(new int ),y(new int){
	*x= 0;
	*y=0;
}
Point2D:: Point2D(int a, int b):x(new int),y(new int){
    *x = a;
    *y = b;
}
//Point2D :: Point2D(const Point2D &rhs):x(new int),y(new int){
//    *x = rhs.get_x();
//    *y = rhs.get_y();
//}
//Point2D& Point2D:: operator=(const Point2D &rhs){
//    if(this != &rhs){
//        if(x!=0){
//            delete x;
//        }
//        x= new int;
//        *x = rhs.get_x();
//
//        if(y!=0){
//            delete y;
//        }
//        y= new int;
//        *y = rhs.get_y();
//    }
//    return *this;
//}
int main(){
    Point2D p1(3,4);
    Point2D p2;
    p2 = p1; 
    p2.display();

    return 0;
}