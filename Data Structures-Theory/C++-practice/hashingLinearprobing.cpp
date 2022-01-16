#include <bits/stdc++.h>
using namespace std;
template <typename t,typename T>
class HashNode{
	private:
		t value;
		T key;
	public:
		HashNode(T k,t v):key(k),value(v){}
		template <typename K,typename V> friend class HashMap;
};
template <typename K,typename V>
class HashMap{
	private:
		HashNode<K,V> **arr;
		int capacity;
		int size;
		HashNode<K,V> *dummy;
	public:
		HashMap(int c){
			capacity = c;
			size = 0;
			arr = new HashNode<K,V>*[capacity];
			for(int i=0;i<capacity;i++){
				arr[i] = NULL;
			}
			dummy = new HashNode<K,V>(-1,-1);
		}
		int hashFunc(int key){
			return key%capacity;
		}
		void insertItem(K key,V value){
			HashNode<K,V> *temp = new HashNode<K,V>(key,value);
			int hashindex = hashFunc(key);
			while(arr[hashindex]!=NULL && arr[hashindex]->key != key && arr[hashindex]->key !=-1){
				hashindex++;
				hashindex %= capacity;
			}
			if(arr[hashindex]==NULL || arr[hashindex]->key==-1){
				size++;
			}
			arr[hashindex]= temp;
		}
		V deleteindex(K key){
			int hashindex= hashFunc(key);
			while(arr[hashindex]!=NULL){
				if(arr[hashindex]->key == key){
					HashNode<K,V> * temp  = arr[hashindex];
					size--;
					arr[hashindex]== dummy;
					return temp->value;
				}
				hashindex++;
				hashindex%= capacity;
			}
			return NULL;
		}
		V search(int key){
			int hashindex = hashFunc(key);
			int counter = 0;
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
		}
		int getsize(){
			return size;
		}
		bool isEmpty(){
			return size==0;
		}
		void display(){
			for(int i=0;i<capacity;i++){
				if(arr[i]!=NULL){
					cout<<endl<<"Key: "<<arr[i]->key<<"  Value: "<<arr[i]->value;
				}
			}
		}
};
int main(){
	HashMap<int,int> *h = new HashMap<int,int>(20);
	h->insertItem(1,1);
	h->insertItem(1,4);
	h->display();
//	h->deleteindex(1);
//	h->display();
//	cout<<endl;
	return 0;
}
