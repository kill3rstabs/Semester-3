#include <iostream>
using namespace std;
template <typename K,typename V>
class HashNode{
	public:
		V value;
		K key;
		HashNode(K k,V v):key(k),value(v){}
};
template <typename K,typename V>
class HashMap{
	private:
		HashNode<K,V>** arr;
		int capacity;
		int size;
		HashNode<K,V>* dummy;
	public:
		HashMap(int c){
			capacity = c;
			size = 0;
			arr = new HashNode<K,V>*[capacity];
			for(int i =0;i<capacity;i++){arr[i]=NULL;}
			dummy = new HashNode<K,V>(-1,-1);
	}
		int hashcode(K key){
			return key%capacity;
		}
		
		void insertNode(K key,V value){
			HashNode<K,V>* temp = new HashNode<K,V>(key,value);
			int hashindex = hashcode(key);
			while(arr[hashindex]!=NULL && arr[hashindex]->key !=key && arr[hashindex]->key!=-1){
				hashindex++;
				hashindex %= capacity;
			}
			if(arr[hashindex]==NULL || arr[hashindex]->key == -1){
				size++;
			}
			arr[hashindex] = temp;
		}
		V deleteNode(int key){
			int hashindex = hashcode(key);
			while(arr[hashindex]!=NULL){
				if(arr[hashindex]->key = key){
					HashNode<K,V> * temp = arr[hashindex];
					arr[hashindex]=dummy;
					size--;
					
					return temp->value;
				}
				hashindex++; // moving to the next location in hashmap
				hashindex %= capacity;
			}
			return -1;
		}
		V search(int key){
			int hashindex = hashcode(key);
			int counter =  0;
			
			while(arr[hashindex]!=NULL){
				if(counter++>capacity){
					return -1;
				}
				if(arr[hashindex]->key == key){
					return arr[hashindex]->value;
				}
				hashindex++;
				hashindex %= capacity;
			}
			return -1;
		}
		int sizeofMap()
    {
        return size;
    }
  
    // Return true if size is 0
    bool isEmpty()
    {
        return size == 0;
    }
		void display()
    {
        for (int i = 0; i < capacity; i++) {
            if (arr[i] != NULL && arr[i]->key != -1)
                cout << "key = " << arr[i]->key
                     << "  value = "
                     << arr[i]->value << endl;
        }
    }

};
int main(){
	HashMap<char,int> * h = new HashMap<char,int>(45);
	h->insertNode('c',4); //key which i need for my hash function to calculate the hashindex // value is value
	h->display();
	cout<<endl<<h->deleteNode('c');
	cout<<endl<<h->sizeofMap();
	return 0;
}
