#include <iostream>

using namespace std;

int rec(int n) 
{
    int returnValue;

    if (n == 1 || n == 2) 
    {
        returnValue = 1;
    } 
    else 
    {
        cout<<n<<" ";
        rec(n-1) + rec(n-2);
    }

    return returnValue;
}


int main()
{
    int i=7;

    rec(i);
}


