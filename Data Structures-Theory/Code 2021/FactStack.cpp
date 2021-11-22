/***************************************************************************
* Author: Muhammad Rafi                                                    *
* Purpose: Simulation of Recursion for Factorial                           *
* Dated: November 08, 2007                                                 *
* Version: 1.2   Implementation of StackFrame  for Factorial               *                                                 
* Last modified: November 10, 2007                                         *
****************************************************************************/

#include<iostream>
#include<stack>


using namespace std;

class StackFrame{
	
	
	private:
		int parameter;
		int result;
		
	public:
	 StackFrame(): parameter(0), result(0){}
	 StackFrame(int p, int r): parameter(p), result(r){}
	 StackFrame(StackFrame & rhs){
	 	
	 	this->parameter= rhs.getParameter();
	 	this->result= rhs.getResult();
	 }
	 
	 StackFrame& operator=(StackFrame & rhs)
	 {
	 	  if (this != &rhs)
	 	  {
	 	  	this->parameter= rhs.getParameter();
	    	this->result= rhs.getResult();
	 	  }
	 	  return (*this);
	 }
	 
	 
	 void setParameter(int p){ parameter=p;  }
	 void setResult (int r)	{ result =r;}
	 int getParameter(void) { return parameter;}
	 int getResult(void) { return result;  }
	 
	
};

int main(){
	
	stack<StackFrame> myStack;
	StackFrame sf;
	
   int n;
   cout<<"Enter n for Factorial:"<<endl;
   cin >> n;
   
   while (n>0) // 5
   {
   	   if (n==1) {
   	   	sf.setParameter(n);
   	    sf.setResult(1);
   	   }
   	   else
   	   {
   	   	sf.setParameter(n); // n= 5
   	   	sf.setResult(0);
   	   	
   	   }
		myStack.push(sf); // 5 //4 //3//2//1
   	    n--;
   	  	
   }
   int results=1;
   while (!myStack.empty()){
   	
   	  sf= myStack.pop();  //1
   	
   	  cout<< sf.getParameter(); //1 //2
   	  cout<< sf.getResult();
   	  results=results*sf.getResult();
   	  cout <<endl;
   	  	
   }
   	
	cout<< "The result of the Factorial(n) is :" << results <<endl;
	
	
	
	
return 0;	
	
}
