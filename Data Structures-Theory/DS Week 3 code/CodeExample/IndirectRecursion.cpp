/****************************************************************************
* Author: Muhammad Rafi                                                    *
* Purpose: Recursion - Indirect recursion  (Examples)                      *
* Dated: September 22, 2007                                                *
* Version: 1.0                                                             *  
* Purpose: Showing how indirect recursion can be used.                     *                  
* Last modified: October 10, 2007                                          *
****************************************************************************/
#include<iostream>

using namespace std;

int Fun1(int &n); // called from main  and called fun 2
int Fun2(int &n); // fun2 call fun 1 

int Fun1(int & n)
{
	if (n <= 20) // do not invoke Fun 2 once n reaches 20
	{
	
	 cout<< n << endl;
	 n++;
	 Fun2(n);
    }
    else return 0;
}

int Fun2(int & n)
{
	if (n <= 20) // do not invoke Fun1 once n reaches 20
	{
	
	 cout<< n << endl;
	 n++;
	 Fun1(n);
    }
    else return 0;
}


int main(){
	
	int a=1;
	
	Fun1(a);
	
	system("pause");
	return 0;

}
