#include <iostream>

using namespace std;

void input(){
	
    
}
class Node{
    friend class list;
    int cof;
    char var;
    int expo;
    Node* next;
    public:
        Node(int cof, char var, int expo){
            this->cof=cof;
            this->var=var;
            this->expo=expo;
            this->next=NULL;
        }
};

class list{
  Node* head;
  
  public:
    list(){head=NULL;}
    
    void add_node(int cof, char var, int expo){
        Node* new_node= new Node(cof,var,expo);
        
        if(head==0){
            head=new_node;
        }
        else{
            Node* curr=head;
            while(curr->next!=0){
                curr=curr->next;
            }
            curr->next=new_node;
        }
    }
    
    void addition(list& L2){
        Node* curr=this->head;
        Node* temp=L2.head;
        bool flag= false;
        while(curr!=0){
            temp=L2.head;
            flag=false;
            while(temp!=0){
            if(curr->expo==temp->expo && curr->var==temp->var){
                temp->cof=curr->cof+temp->cof;
                flag=true;
                break;
            }
            temp=temp->next;
            }
            if(flag==false){
                L2.add_node(curr->cof,curr->var,curr->expo);
            }
            curr=curr->next;
    }
    	L2.sort();
        L2.display();
}
	int count_node(){
		int count=0;
		Node* curr=head;
		while(curr!=0){
			count++;
			curr=curr->next;
		}
		return count;
	}
    void copy(const list &original){
		
//		 size = original.size;
		 Node *firstPtr = 0;
		 Node*ptr = original.head;
		 Node *newPtr, *lastPtr;
		 while (ptr != 0) {
		 // create a new node with the value in it.
//		 newPtr = new Node();
//		 assert(newPtr != 0);
		 if(firstPtr == 0)
		 firstPtr = newPtr; // first node
		 else
//		 lastPtr->nextPtr = newPtr; // set up last link
		 lastPtr = newPtr; // save last ptr
//		 ptr = ptr->nextPtr; // move up ptr 
	}}
    void display(){
        Node* curr=head;
        cout<<endl;
        cout<<count_node()<<endl;
        while(curr!=0){
            
			cout<<curr->cof;
            cout<<" "<<curr->var;
            cout<<" "<<curr->expo;
			cout<<endl;
			curr=curr->next;
    }
}
void sort(){
		Node* curr=head;
		Node* temp;
		Node* temp2;
		int tempvar=0;
		char tempchar;
		while(curr!=0){
			temp=curr->next;
			while(temp!=0){
				
				if(curr->expo>temp->expo){
					tempvar=curr->expo;
					curr->expo=temp->expo;
					temp->expo=tempvar;

					tempchar=curr->var;
					curr->var=temp->var;
					temp->var=tempchar;

					
					tempvar=curr->cof;
					curr->cof=temp->cof;
					temp->cof=tempvar;					
				}
				temp=temp->next;	
			}
			curr=curr->next;
			}
			
			curr=head;
			temp=curr->next;
			while(curr!=0){
			temp=curr->next;
				while(temp!=0){
				
				if(curr->var>temp->var){
					tempvar=curr->expo;
					curr->expo=temp->expo;
					temp->expo=tempvar;

					tempchar=curr->var;
					curr->var=temp->var;
					temp->var=tempchar;

					
					tempvar=curr->cof;
					curr->cof=temp->cof;
					temp->cof=tempvar;					
				}
				temp=temp->next;	
			}
			curr=curr->next;
			}
		}        
    
};
int main() {
	int n,cof,e;
    char var;
    list L1,L2;
	cin>>n;
    for(int i=0; i<n; i++){
    cin>>cof;
    cin>>var;
    cin>>e;
    L1.add_node(cof,var,e);
    }
    cout<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
    cin>>cof;
    cin>>var;
    cin>>e;
    L2.add_node(cof,var,e);
    }

    L1.addition(L2);
    
	return 0; 
}
