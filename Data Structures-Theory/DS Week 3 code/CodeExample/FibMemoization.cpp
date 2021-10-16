/****************************************************************************
* Author: Muhammad Rafi                                                    *
* Purpose: Recursion Fibonacci with memoization (Examples)                 *
* Dated: October 02, 2007                                                  *
* Version: 1.0                                                             *                                                 
* Last modified: October 11, 2007                                          *
****************************************************************************/


#include <iostream>
#include<time.h>
#include<math.h>

using namespace std;

#define MAX 100

long int lookup_table[MAX]={0};

int fib_mem(int n){

 if (lookup_table[n]==0)
   {
      //cout << "Running Fib for n="   << n << endl;
       if ((n <= 1))
	   lookup_table[n]=1; 
	   else
	   {
       //cout << "Completing Recursive Function for Fib(" << n << ")" <<endl;
	   lookup_table[n]= fib_mem(n-1)+fib_mem(n-2);
       } 
       
   }
   //cout << "Retrun Value is "  << lookup_table[n] <<endl;
   return lookup_table[n];
}


 int main()
  {
    int n;
 
    cout << "Enter a non-negative integer for Fib: ";
    cin >> n;
    
    clock_t t1;
    t1=clock();
    cout << "Fib of n=" << n << " is " << fib_mem(n) << endl;  
    t1= clock()-t1;
    cout<< "Time: " << ((float) t1)/ CLOCKS_PER_SEC << endl;
    return 0;
  }
