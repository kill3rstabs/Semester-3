#include<iostream>
using namespace std;

class Node{
	public:
		Node* next;
		int data;
		
		Node()
		{
			next=NULL;
			data=0;
		}
		
		Node(int d)
		{
			next=NULL;
			data=d;
		}
};

class sll{
	public:
		Node* Head;
	
		
		
		sll()
		{
			Head = NULL;
		}
		
		void insertinBW(int d, int k)
		{
			int count = 0;
			Node* temp = Head;
//			Node* current;
			Node* newNode = new Node(d); //parameterized constructor called
			
			while(count!=k)
			{
				temp = temp->next;
				count++;
			}
			
//			if(count==k)
//			{
//				newNode->next=temp->next;
//				temp->next = newNode;
//				cout << "\n\nSuccessfully inserted.";
//			}
//			else
//			{
//				cout << "\n\noperation unsuccessful";
//			}
		}
};


int main()
{
	sll n;
	n.insertinBW(2,1);
}
