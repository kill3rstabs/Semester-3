
#include<iostream>
using namespace std;
//Node Object
class Node
{
//public members: data, next
   private:
   	int data;
   	Node *next;
   	int size;
   	public:
Node (){
//initialize both key and data with zero while next pointer with NULL;
     data=0;
     ;
     size++;
}
Node (const int data){
	//assign the data members initialized in default constructor to these arguments.
	 this->data=data;
	 this->next=NULL;
}
friend class SinglyLinkedList;
};

//SinglyLinkedList Object
class SinglyLinkedList
{
	private:
// create head node as a public member
	Node *head;
	public:
//Default Constructor
SinglyLinkedList()
{
//initialize the head pointer will NULL;
   head=NULL;
}
//Parameterized Constructor with node type ‘n’ pointer
SinglyLinkedList (Node* n){
//Assign the head pointer to value of pointer n;
    head=n;
}
void display(){
	Node *temp=head;
	if(temp==NULL){
		cout<<"NO DATA IS PRESENT";
	}
		while(temp!=NULL){
			cout<<temp->data<<"->";
			temp=temp->next;
		}

}
void push(const int data){
	Node *node=new Node(data);
	if(head==NULL){
		node->next=head;
		head=node;
	}
	else{
		Node *temp=head;
		node->next=temp;
		head=node;
//		delete temp;
	}
}
void AtEnd(const int data){
	Node *node=new Node(data);
	if(head==NULL){
		//node->next=head;
		head=node;
	}
	else{
		Node *temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=node;
	}
}

void insertAfter(int o_data, int n_data) {
			// Return if given prev_node is NULL
			Node *temp= head;
		    if (temp == NULL) 
		    { 
		        cout << "The head is pointing to Null"; 
		        return; 
		    }
		    while(temp->data!=o_data){
		    	temp=temp->next;
			}
			// make new node and set its data
	  		Node* new_node = new Node(n_data);
	  		
	  		// assign next node as next of new node
	  		new_node->next = temp->next;
	  		
	  		// assign next of given node as new node
	  		temp->next = new_node;
		}
		
void delete_node(int o_data){
	if (head == NULL) { 
		cout << "The head is pointing to Null"; 
		return; 
	}
	Node *temp= head, *previous;
	while(temp->data!=o_data && temp->next!=NULL ){
		    	previous=temp;
				temp=temp->next;
	}
	
	if(temp->data!=o_data && temp->next!=NULL){
		cout << "The data that you want to delete is NOT Found"; 
		return; 
	}
	
	else{
		previous->next=temp->next;
		delete temp;
	}
	
}

void delete_Lastnode(){
	if (head == NULL) { 
		cout << "The head is pointing to Null"; 
		return; 
	}
	Node *temp= head;
	while(temp->next->next!=NULL ){
				temp=temp->next;
	}
	

		Node *n= temp->next;
		temp->next = NULL;
		delete n;
	
}
void update(int o_data, int n_data) {
			// Return if given prev_node is NULL
			Node *temp= head;
		    if (temp == NULL) 
		    { 
		        cout << "The head is pointing to Null"; 
		        return; 
		    }
		    while(temp->data!=o_data && temp->next!=NULL){
		    	temp=temp->next;
			}
			if(temp->data!=o_data && temp->next==NULL){
				cout << "The Data that has to be updated is NOT Found"; 
		        return; 
			}
            else{
            	temp->data=n_data;
			}
	  		
	  		
}

void modify_Even_Odd(){
	Node *curr=head,*temp;
    int temp_d;
	while(curr!=NULL){
		temp=curr->next;
		while(temp!=NULL){
			if(((curr->data)%2)!=0 && ((temp->data)%2)==0){
				temp_d=curr->data;
				curr->data=temp->data;
				temp->data=temp_d;
			}
			temp=temp->next;
		}
		curr=curr->next;
	}
}
};



int main(){
	SinglyLinkedList N;
	N.AtEnd(9);
	N.AtEnd(11);
	N.AtEnd(8);
	N.AtEnd(12);
	N.insertAfter(9,10);
	N.update(15,13);
	N.display();
	cout<<endl;
	N.modify_Even_Odd();
	N.display();
	cout<<endl;
	N.delete_node(8);
	N.display();
	N.delete_Lastnode();
	N.display();
}
