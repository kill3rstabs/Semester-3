/***************************************************************************
* Author: Nashit Budhwani                                                  *
* Purpose: ArrayStack as a wrapper on DyanmicSafeOneDimensionalArray       *
* Dated: November 20, 2021                                                 *
* Version: 1.0   wrapper-Implementations                                   *                                                 
* Last modified: November 20, 2021                                         *
****************************************************************************/
#include <iostream>
#include <Bits/stdc++.h>
using namespace std;
//Dynmaic Safe Array class 
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
//Array wrapper class Stack
template <class T>
class Stack{
	private:
		DynamicSafeArray<T> * stackData;
		int top;
		int max;
	public:
		Stack(int Size=0){
		cout<<"Constructor of Array Stack"<<endl;
		stackData = new DynamicSafeArray<T>(Size) ;
		top = -1 ;
		max = Size ;
	}
	bool isEmpty(){
		if (top == -1)
		 return true ;
		else 
		 return false ;  
	}
		~Stack(){
			cout<<"Destructor called";
			if(stackData){
				delete stackData;
				top = -1;
				max = 0;
			}
		}
		bool isFull(){
			if(top>max){
				return true;
			}
			return false;
		}
		void push(T d){
			if (stackData->getSize() > top){
			top++ ;
			stackData->operator[](top) = d ;
		}
		else cout<<"Stack is Full"<<endl;
		}
		T pop(){
			T data;
			if(!isEmpty()){
				data = stackData->operator[](top);
				top--;
				return data;
			}
		}
		int getTop(){return top;}
		T peek(){
			T data;
			if(!isEmpty()){
				data = stackData->operator[](top);
				return data;
			}
		}
		
};

int isOperand(char x){
	if(x=='+' || x=='-' || x=='/' || x=='*'){
		return 0;
	}
	else{
		return 1;
	}
}
int pre(char x){
	if(x=='+' || x=='-'){
		return 1;
	}
	if(x== '/' || x== '*'){
		return 2;
	}
	return 0;
}
string convert(string infix){
	Stack<char> st(infix.size());
	string postfix;
	int i=0,j=0;
	while(infix[i]!='\0'){
		if(isOperand(infix[i])){
			postfix[j++]=infix[i++];
		}
		else{
			if(pre(infix[i])>pre(st.peek())){
				st.push(infix[i]);
			}
			else{
				postfix[j++]= st.pop();
			}
		}
	}
	while(!st.isEmpty()){
		postfix[j++] = st.pop();
	}
	postfix[j]='\0';
}
int main(){
	Stack<char> s(10);
	cout<<s.peek()<<endl;
	string str;
	getline(cin>>ws,str);
	cout<<endl<<convert(str)<<endl;
	
	
	
	
	return 0;
}
