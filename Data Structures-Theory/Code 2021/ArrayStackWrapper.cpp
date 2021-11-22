/***************************************************************************
* Author: Muhammad Rafi                                                    *
* Purpose: ArrayStack as a wrapper on DyanmicSafeOneDimensionalArray       *
* Dated: October 20, 2007                                                  *
* Version: 1.2   wrapper-Implementations                                   *                                                 
* Last modified: October 27, 2007                                          *
****************************************************************************/


#include <iostream>
#include <Bits/stdc++.h>

using namespace std ;


// Exception class as per discussion from the lecture 

class Arrayindexoutofbound:public std::runtime_error
{
  public:
  Arrayindexoutofbound():std::runtime_error("Array index out of bound")
  {  }
};


//DyanmicSafeArray class from the lectures 
//template implementations with some handy functions. 
template <class T>
class DynamicSafeArray
{
	private :
		int size ;
		T *Data ;
	public :
	DynamicSafeArray()                                   //Default Constructor
	{
		cout<<"Default constructor"<<endl;
		size = 20 ;
		Data = new T[size] ;
		memset (this->Data , 0 , sizeof(int)*size) ;
	}
	DynamicSafeArray(int s)                             //Parametrized Constructor
	{
		cout<<"Parametrized Constructor"<<endl;
		size = s ;
		Data = new T[size] ;
		memset (this->Data , 0 , sizeof(int)*size) ;
	}
	DynamicSafeArray(const DynamicSafeArray &rhs)      //Copy Constructor
	{    
	    cout<<"Copy Constructor"<<endl;
		this->size = rhs.size ;
		this->Data = new T[size] ;
		memcpy(this->Data,rhs.Data,sizeof(int)*this->size);
	}
	~DynamicSafeArray()                                 //Destructor
	{
		cout<<"Destructor"<<endl;
		if (Data != 0)
		{
			delete [] Data ;
			Data = 0 ;
			size = 0 ;
		}
	}
	DynamicSafeArray operator = (const DynamicSafeArray &rhs)        //Equal to operator overload
	{
		cout<<"Equals to operator overload"<<endl;
		if (this != &rhs)
		{
			delete [] this->Data ;
			Data = 0 ;
			size = 0 ;
			size = rhs.size ;
			Data = new T[size] ;
			memcpy (this->Data , rhs.Data , sizeof(int)*size) ;
		}
		return (*this) ;
	}	
	int getSize()
	{
		return size ;
	}
	T & operator[] (int i)
	{
		return (*(Data+i)) ;
	}
	const T & operator[] (int i) const
	{
		return (*(Data+i)) ;
	}
	void Resize (int nsize)
	{
		if (size != nsize)
		{
			T *temp ;
			temp = new T[size] ;
			for (int i=0 ; i<size ; i++)
			*(temp+i) = *(Data+i) ;
			delete [] Data ;
			Data = 0 ;
	    	Data = new T[nsize] ;
	    	memset(this->Data , 0 , sizeof(int)*nsize) ;
	    	for (int i=0 ; i<nsize ; i++)
	    	*(Data+i) = *(temp+i) ;
	    	size = nsize ;
	    	delete []temp ;
	    	temp = 0 ;
		}
	}
	friend ostream& operator << (ostream &fout , DynamicSafeArray &rhs)
	{
		cout<<"Elements of array are : "<<endl;
		for (int i=0 ; i<rhs.size ; i++)
		{
			cout<<rhs.Data[i]<<" ";
		}
		cout<<endl;
		return (fout) ;
	}
	friend istream & operator >> (istream &infile , DynamicSafeArray &rhs)
	{
		cout<<"Enter array elements : "<<endl;
		for (int i=0 ; i<rhs.size ; i++)
		cin>>rhs.Data[i] ;
		return infile ;
	}	
};

// Wrapper class for stack using DSA one dimenisonal 
template <class T>
class ArrayStack{
	private :
		DynamicSafeArray<T> *StackData ;
		int top ;
		int Max ;
	public :	
	ArrayStack(int Size=0){
		cout<<"Constructor of Array Stack"<<endl;
		StackData = new DynamicSafeArray<T>(Size) ;
		top = -1 ;
		Max = Size ;
	}
	bool isEmpty(){
		if (top == -1)
		 return true ;
		else 
		 return false ;  
	}
	bool isFull(){
		if (top > Max)
		 return true ;
		else
		  return false ; 
	}
	~ArrayStack(){
		cout<<"Destructor of Array Stack"<<endl;
		if (StackData != 0){
			delete StackData ;
			top = -1 ;
			Max = 0 ;
		}
	}
	void Push(T data){
		if (StackData->getSize() > top){
			top++ ;
			StackData->operator[](top) = data ;
		}
		else cout<<"Stack is Full"<<endl;
	}
	T Pop(){
		T data ;
		if (!isEmpty()){
			data = StackData->operator[](top) ;
		    top -- ;
		    return data ;
		}
	}
	T Peek(){
		T data ;
		if (!isEmpty())
		 data = StackData->operator[](top) ;
		 return data ;
	}

};

int main()
{
	int data ;
	ArrayStack <int>Array(5) ;
	Array.Push(10);
	Array.Push(5);
	Array.Push(6);
    cout<<endl<<Array.Peek()<<endl ;
    cout<<Array.Pop()<<endl ;
}
