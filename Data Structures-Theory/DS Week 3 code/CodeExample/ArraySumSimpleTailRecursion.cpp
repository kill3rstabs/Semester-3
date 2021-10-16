/****************************************************************************
* Author: Muhammad Rafi                                                    *
* Purpose: Recursion Array sum  (Examples)                                 *
* Dated: September 22, 2007                                                *
* Version: 1.0                                                             *                                                 
* Last modified: October 10, 2007                                          *
****************************************************************************/

#include <iostream>

using namespace std;

int ArraySum(int array[], int i)
{
   
   if ( i <= 0 )
   {
      return 0;
   }

   return ArraySum(array, i-1) + array[i-1];
}

int main()
{
   int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
   
   cout << "sum is : " << ArraySum(array, 10) <<  endl;
   
   return 0;
}
