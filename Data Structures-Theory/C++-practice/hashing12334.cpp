
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Hashing{
	private:
	
		int size;
		list<string> *table;
	public:
		Hashing(int s):size(s){
			table = new list<string>[size];
			
			
		}
		int hashFunc(string k){
			int key =0;
			for(int i=0;k[i]!='\0';i++){
				
				key += k[i];
				key += 2+2+7+4; // roll_num
			}
			return key%size;
		}
		void insertIntoTable(string k){
			int index = hashFunc(k);
			list<string>::iterator it;
			it=find(table[index].begin(), table[index].end(),k);
			if(it!=table[index].end()){
				cout<<endl<<"You already memorised ["<<k<<"] earlier!";
				return;
				
			}
			
			table[index].push_back(k);
			cout<<endl<<"New word added onto the table";
		}
		void display(){
			for(int i=0;i<size;i++){
				cout<<endl<<i;
			    list<string>::iterator it;
			    for(it = table[i].begin();it!=table[i].end();it++){
			    	cout<<"-->"<<*it;
				}
			  
			}
		}
};
int main(){
	Hashing h1(20);
	h1.insertIntoTable("Kindness");
	h1.insertIntoTable("Politeness");
	h1.insertIntoTable("Understandable");
	h1.insertIntoTable("Empathy");
	h1.insertIntoTable("Appreciate");
	h1.insertIntoTable("Appreciate");
	h1.insertIntoTable("Understandable");
	h1.display();
	return 0;
}
