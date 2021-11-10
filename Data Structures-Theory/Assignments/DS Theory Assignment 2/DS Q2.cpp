#include <iostream>
using namespace std;
class Node{
	private:
		string word;
		char done;
		Node * next;
		Node* prev;
	public:
		Node(string w):word(w),next(0),prev(0),done(' '){}
		friend class DLL;
};
class DLL{
	private:
		Node* head;
	public:
		DLL():head(0){}
		void addNode(string w){
			Node* temp = head;
			Node* n = new Node(w);
			if(head==NULL){
				head=n;
				return;
			}
			while(temp!=NULL){        //check before inserting any dupliacte value
				if(temp->word==w){
					return;
				}
				temp=temp->next;
			}
			temp=head;
			while(temp->next!=NULL){
				temp = temp->next;
			}
			temp->next = n;
			n->prev = temp;
		}
		void copy(DLL A) {
		Node *temp = A.head ;
		while (temp != NULL) {
			addNode(temp->word) ;
			temp = temp->next ;
		}
	}
		void display(){
			sort();
			Node* temp = head;
			while(temp!=NULL){
				cout<<temp->word<<endl;
				temp = temp->next;
			}
			
		}
		void uniqueWords(DLL &l2){
			
			DLL l3;
			
			int count=0;
			Node * temp = head;
			
			while(temp!=NULL){
				Node* temp2 = l2.head;
				while(temp2->next!=NULL){
					if(temp->word == temp2->word && temp2->done != 'y'){
						
						count++;
					}
					if(count >= 2){
						temp2->done ='y';
						if(count == 2)
						l3.addNode(temp->word);
					}
					temp2 = temp2->next;
				}
				count = 0;
				temp = temp->next;
			}
			l3.display();
		}
		void sort()
{
    int swapped, i;
     Node *ptr1;
     Node *lptr = NULL;
  
    /* Checking for empty list */
    if (head == NULL)
        return;
  
    do
    {
        swapped = 0;
        ptr1 = head;
  
        while (ptr1->next != lptr)
        {
            if (ptr1->word > ptr1->next->word)
            {
                swap(ptr1->word, ptr1->next->word);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}
 
};
int main(){
	DLL L,L2;
	string s;	
	for(int i=0;i<12;i++){
		cin>>s;
		L.addNode(s);
	}
	
	L.display();
	
	return 0;
}

