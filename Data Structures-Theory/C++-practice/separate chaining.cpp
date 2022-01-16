#include <bits/stdc++.h>
using namespace std;
class Hash{
	int bucket;
	list<int>* table;
	public:
		Hash(int b){
			this->bucket = b;
    		table = new list<int>[bucket];
		}
		int hashFunc(int x) {
        	return (x % bucket);
    	}
		insertItem(int key){
			int index = hashFunc(key);
			table[index].push_back(key);
		}
		void deleteItem(int key){
			int index = hashFunc(key);
			
			for(int i = 0;i<bucket;i++){
				if(table[i] == key){
					table[index].erase(i);
					break;
				}
			}
		}
		void displayHash() {
			for (int i = 0; i < bucket; i++) {
				cout << i;
			    for (auto x : table[i])
			    	cout << " --> " << x;
			    cout << endl;
	  		}
		}
		
};

int main(){
	int a[]= {15,11,27,8,12};
	int n = sizeof(a)/sizeof(a[0]);
	Hash h(7);
	for (int i = 0; i < n; i++)
    	h.insertItem(a[i]); 
 
  	// delete 12 from hash table
  	h.deleteItem(12);
 
	// display the Hash table 
	h.displayHash();
	return 0;
}
