#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v1;
    v1.push_back(34);
    cout<<endl<<v1.capacity();
    cout<<endl<<"Size: "<<v1.size();
    cout<<"Vector: "<<v1[0];


    return 0;
}