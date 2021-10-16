#include <iostream>

using namespace std;

class node
{	
	public:
	    int data;
	    node *next;
	    node():next(0){}
	    node(int d):data(d),next(0){
	    	
		}

};

class linked_list
{
private:
    node *head,*tail;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
	        tail->next = tmp;
            tail = tail->next;
        }
    }
    void display(){
    	node *temp = head;
    	
    	while(temp!=NULL){
    		cout<<temp->data<<"->";
    		temp = temp->next;
		}
		cout<<"Null";
	}
	void insertAtHead(int d){
			node *temp;
			node *n=new node(d);
			
			temp=head;
			
			head=n;
			head->next=temp;
			
	}
	void insertAtTail(int d){
		node *temp;
		node *n = new node(d);
		
		temp = tail;
		tail = n;
		tail->next = temp;
	}
	
	
};

int main()
{
//	
    linked_list a;
    a.add_node(1);
    a.add_node(2);
    a.add_node(3);
    a.add_node(4);
    a.add_node(5);
	a.insertAtHead(7);
	a.insertAtTail(9);
    a.display();
    return 0;
}
