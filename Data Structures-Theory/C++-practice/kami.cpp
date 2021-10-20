#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node* next;
		
		node()
		{
			data = 0;
			next = NULL;
		}
		
		node(int d)
		{
			data = d;
			next = 0;
		}
};

class SLL{
	
		public:
			node* Head;
		
			SLL()
			{
				Head=NULL;
			}
			
			void appendNode(int d)
			{
				node* temp = Head;
				node* newNode = new node(d);
				
				if(Head==NULL)
				{
					Head = newNode;
					return;
				}
				else
				{
					//head ko point karao newnode pr or new node k next ko point karao temp pr bec temp is pointing where head was pointing before(1st node)
					Head=newNode;
					newNode->next = temp;
					temp = Head;
				}
			}
			
			void display()
			{
				node* temp = Head;
			
				while(temp != NULL)
				{
					cout << temp->data<<"->";
					temp = temp->next;
				}
				cout<<"NULL";
			}	
};

int main()
{
	SLL ob1;
	ob1.appendNode(3);
	ob1.appendNode(2);
	ob1.display();
}
