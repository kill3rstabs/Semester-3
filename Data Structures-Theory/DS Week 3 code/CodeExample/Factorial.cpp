/****************************************************************************
* Author: Muhammad Rafi                                                    *
* Purpose: Recursion Factorial (Examples)                                  *
* Dated: September 22, 2007                                                *
* Version: 1.0                                                             *                                                 
* Last modified: October 10, 2007                                          *
****************************************************************************/


#include <iostream>

using namespace std;

  int factorial(int n)
  {
    int return_value;
    cout << "Factorial(" << n << ")\n"; 
    if (n == 0) {
      return_value = 1;
    } else {
      return_value = n * factorial(n-1);
    }
    cout << "Factorial(" << n << ") is returning " << return_value << endl;  
    return return_value;
  }

int main()
  {
    int n;
 
    cout << "Enter a non-negative integer: ";
    cin >> n;
    cout << "Factorial of " << n << " is " << factorial(n) << endl;  
    return 0;
  }
