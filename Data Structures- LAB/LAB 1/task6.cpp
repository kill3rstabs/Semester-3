#include<iostream>
#include<conio.h>
using namespace std;

class Animal{
private:
    int age;
    string type;
    string breed;
public:
    string name;
    int getAge(void){return age;}
    string getType(void){return type;}
    string getBreed(void){return breed;}
    void setAge(int age){this->age=age;}
    void setType(string type){this->type=type;}
    void setBreed(string breed){this->breed=breed;}
};

void sortingFunc(Animal*ptr){
    cout<<"Press a Key to Sort in Order:"<<endl;
    getch();
    for(int i=0;i<5;i++){
            for(int j=i+1;j<5;j++){
                string temp;
                if((ptr+i)>(ptr+j)){
                temp=(ptr+i)->name;
                (ptr+i)->name=(ptr+j)->name;
                (ptr+j)->name=temp;
                }
            }
        }
    for(int i=0;i<5;i++){
        cout<<(ptr+i)->name<<endl;
    }
}

int main(int argc,char*argv[]){
    Animal *ptr;
    ptr=new Animal[5];
    cout<<"Enter 5 Names:"<<endl;
    for(int i=0;i<5;++i){
        cin>>(ptr+i)->name;
    }
    sortingFunc(ptr);
    return 0;
}
