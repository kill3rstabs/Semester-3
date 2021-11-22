/***************************************************************************
* Author: Muhammad Rafi                                                    *
* Purpose: LinkedStack as a wrapper on Singly Linked List                  *
* Dated: October 20, 2007                                                  *
* Version: 1.2   wrapper-Implementations                                   *                                                 
* Last modified: October 23, 2007                                          *
****************************************************************************/


#include <iostream>

using namespace std ;

// Node class as per discussion from the lecture 
template <class T>
class Node{
    public :
		T Data ;
		Node *Next ;
	    Node() : Next(0)
		{ }	
		Node(T d , Node *n = 0) : Data(d) , Next(n)
		{ }
		Node(const Node &n)
		{
			this->Data = n.Data ;
			this->Next = n.Next ;
		}
		
};

// SinglyLinkedList class as per discussion from the lectures
// template implementation along with some important functions 
// Sample class 

template <class T>
class SinglyLinkedList{
	private :
		Node<T> *Head ;
		void DeleteAll()
	    {
	  	 Node<T> *current = Head ;
	  	 Node<T> *temp = current ;
	  	 while (current != 0)
	  	 {
	  		current = current->Next ;
	  		temp = Head ;
	  		delete temp ;
	  		Head = current ;
		  }
	   }
	public :
	  SinglyLinkedList() : Head(0)
	  {  }
	  SinglyLinkedList (const SinglyLinkedList &rhs)
	  {
	  
	  	Node<T> *current = rhs.Head ;
	  	Head = 0 ;
	  	Node<T> *Last = Head ;
	  	while (current != 0)
	  	{
	  		Node<T> *temp = new Node<T>(current->Data) ;
	  		if (Head == 0)
			{
			  	Head = temp ;
			  	Last = Head ;
			}
			else
			{
			    Last->Next = temp ;
			    Last = temp ;
			} 
			current = current->Next ;
		  }
	  }
	 
	  void InsertAtFront(T d)
	  {
	     Node<T> *temp = new Node<T>(d) ;
		 if (Head == 0)
		  Head = temp ;
		 else 
		 {
		 	temp->Next = Head ;
		 	Head = temp ;
		 } 	
	  }
	  void DeleteFromFront()
	  {
	  	Node<T> *temp = Head ;
	  	Head = Head->Next ;
	  	delete temp ;
	  }
	  void InsertAtLast(T d)
	  {
	  	Node<T> *temp = new Node<T>(d) ;
	  	Node<T> *current = Head ;
	  	if (Head == 0)
	  	 Head = temp ;
	  	else {
	  		while (current->Next != 0)
	  		{
	  			current = current->Next ;
		    }
			  current->Next = temp ;
			  temp->Next = 0 ;
		} 
	  }
	  void InsertAfterPosition(T d , int p)
	  {
	  	Node<T> *newNode = new Node<T>(d) ;
	  	Node<T> *current = Head ;
	  	int position = 1 ;
	  	while (position != p)
	  	{
	  		current = current->Next ;
			position++ ; 
		}
		newNode->Next = current->Next ;
		current->Next = newNode ;
	  }
	  void RemoveFromLast()
	  {
	  	Node<T> *temp = new Node<T> ;
	  	Node<T> *current = Head ;
	  	while (current->Next->Next != 0)
	  	{
	  		current = current->Next ;
		  }
		 temp = current->Next ;
		 delete temp ;
		 current->Next = 0 ; 
	  }
	  void Display()
	  {
	  	int n = 1 ;
	  	Node<T> *current = Head ;
	  	if (Head == 0)
	  	cout<<"List is empty"<<endl;
	  	else
	  	while (current != 0)
	  	{
	  		cout<<endl<<"Node : "<<n<<endl;
	  		cout<<"Data : "<<current->Data<<endl;
	  		n++ ;
	  		current = current->Next ;
		}
	  }
	  int Size()
	  {
	  	int ListSize = 0 ;
	  	Node<T> *current = Head ;
	  	while (current != 0)
	  	{
	  		current = current->Next ;
	  		ListSize++ ;
		  }
		  return ListSize ;
	  }
	  SinglyLinkedList<T>& SplitHalf()
	  {
	  	Node<T> *OneStep = Head ;
	  	Node<T> *TwoStep = Head ;
	  	if (this->Size()%2 == 0)
		  {
		  	TwoStep = Head->Next ;
	  		while (TwoStep->Next != 0)
	  	    {
	  		 OneStep = OneStep->Next ;
	  		 TwoStep = TwoStep->Next->Next ;
		    }
		    OneStep = OneStep->Next ;
		  }
		else
		{
			while (TwoStep->Next != 0)
	  	    {
	  		 OneStep = OneStep->Next ;
	  		 TwoStep = TwoStep->Next->Next ;
		    }
		}
		SinglyLinkedList<T> *S1 = new SinglyLinkedList();
		S1->Head = OneStep ;
		return *S1 ;  
	  }
	  ~SinglyLinkedList()
	  {
	  	cout<<endl<<"Destuctor"<<endl;
	  	DeleteAll();
	  }
	  SinglyLinkedList<T> & operator = (const SinglyLinkedList<T> &rhs)
	  {
	  	cout<<"Assignment Operator"<<endl;
	  	Node<T> *current = Head ;
	  	Node<T> *temp = current ;
	  	if (this != &rhs)
	  	{
	  		while (current != 0)
	  		{
	  			current = current->Next ;
	  			temp = Head ;
	  			delete temp ;
	  			Head = current ;
			  }
			  
			current = rhs.Head ;
			Head = 0 ;
			temp = 0 ;
			while (current != 0)
			{
				Node<T> *newNode = new Node<T>(current->Data) ;
				if (Head == 0)
				{
					Head = newNode ;
					temp = Head ;
				}
				else 
				{
					temp->Next = newNode ;
					temp = temp->Next ;
				}
				current = current->Next ;
			  }  
		  }
		  return (*this) ;
	  }
	  void Reverse()
	  {
	  	Node<T> *Current = Head ;
	  	Node<T> *Previous = NULL ;
	  	Node<T> *Temp = NULL ;
	  	while (Current != NULL)
	  	{
	  		Temp = Current->Next ;
	  		Current->Next = Previous ;
	  		Previous = Current ;
	  		Current = Temp ;
		}
		  Head = Previous ;
	  }
	  bool CheckPalindrome(SinglyLinkedList<T> &rhs)
	  {
	  	Node<T> *temp = Head ;
	  	Node<T> *rhsTemp = rhs.Head ;
	  	while (temp != NULL && rhsTemp != NULL)
	  	{
	  	  if (temp->Data != rhsTemp->Data)
	  	    return false ;
		   temp = temp->Next ;
		   rhsTemp = rhsTemp->Next ;	   
		}
		return true ;
	  }
	  
	void FindMax()
	{
		T data ;
		Node<T> *current = Head ;
		data = current->Data ;
		while (current->Next != NULL)
		{
			current = current->Next ;
			if (data<current->Data)
			   data = current->Data ;
		}
		cout<<"Data : "<<data<<endl;
	}
	Node<T>& getHead(){
		return *Head ;
	}
};

// LinkedStack as wrapper class 
template <class T>
class LinkedStack{
	private :
		SinglyLinkedList <T> List ;
	public :
	LinkedStack(){ }
	void Push(T data){
		List.InsertAtFront(data) ;
	}	
	void Pop(){
		List.DeleteFromFront() ;
	}
	void display(){
		List.Display() ;
	}
	bool isEmpty(){
		if (List.getHead() == NULL)
		   return true ;
		else return false ;   
	}
};

int main()
{
	LinkedStack <int> L1 ;
	L1.Push(10) ;
	L1.Push(23) ;
	L1.Push(20) ;
	cout << "Display stack :" <<endl;
	L1.display() ;
	cout<<"Pop called"<<endl;
	L1.Pop() ;
	L1.display() ;
}
