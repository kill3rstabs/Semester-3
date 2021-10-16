/****************************************************************************
* Author: Muhammad Rafi                                                    *
* Purpose: Recursion Fibonacci (Examples)                                  *
* Dated: October 02, 2007                                                  *
* Version: 1.0                                                             *                                                 
* Last modified: October 11, 2007                                          *
****************************************************************************/


#include <iostream>

using namespace std;

int fib(int n){

  int return_value=1;
  cout << "Running Fib for n="   << n << endl;
  
  if (n <=1) {  
  return return_value;} 
  else 
  {
  	return_value = fib(n-1)+ fib(n-2);
  }

 cout << "Completing Recursive Function for Fib(" << n << ")" <<endl;
 
 cout << "Retrun Value is "  << return_value <<endl;

 return (return_value);

}


 int main()
  {
    int n;
 
    cout << "Enter a non-negative integer for Fib: ";
    cin >> n;
    cout << "Fib of n=" << n << " is " << fib(n) << endl;  
    return 0;
  }
