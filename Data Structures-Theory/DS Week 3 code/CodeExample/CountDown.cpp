/****************************************************************************
* Author: Muhammad Rafi                                                    *
* Purpose: Recursion CountDown  (Examples)                                 *
* Dated: October 02, 2007                                                  *
* Version: 1.0                                                             *                                                 
* Last modified: October 11, 2007                                          *
****************************************************************************/


#include <iostream>

using namespace std;

int CountDown(int n){

  int return_value=1;
  cout << "Running CountDown for n="   << n << endl;
  
  if (n < 1) {  
  return return_value;} 
  else 
  {
  	return_value = CountDown(n-1);
  }

 cout << "Completing Recursive Function for CountDown(" << n << ")" <<endl;
 
 return (return_value);

}


 int main()
  {
    int n;
 
    cout << "Enter a non-negative integer for CountDown: ";
    cin >> n;
    cout << "CountDown of n=" << n << " is " << CountDown(n) << endl;  
    return 0;
  }
