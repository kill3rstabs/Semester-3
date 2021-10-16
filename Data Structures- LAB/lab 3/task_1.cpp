#include <iostream>

using namespace std;

int tri(int i)
{
	if (i<=1)
	{
		return 1;
	}
	else
	{
		// cout<<i<<" ";
		return i+tri(i-1);
	}
}

int main(int argc, char const *argv[])
{
	int n;

	cout<<"Enter the num of terms you want : ";
	cin>>n;

	for(int i=1; i<=n; i++)
	{
		cout<<tri(i)<<" , ";
	}
	return 0;
}