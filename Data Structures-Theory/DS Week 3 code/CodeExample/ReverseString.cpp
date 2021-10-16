#include <iostream>



using namespace std;

void Reverse(const string& s);

int main()
{
    string str;
    cout << " Enter an string to reverse:  " << endl;
    getline(cin, str);
    Reverse(str);
    return 0;    
}

void Reverse(const string& str)
{
    size_t countChar = str.size();

    if(countChar == 1)
       cout << str << endl;
    else
    {
       cout << str[countChar - 1];
       Reverse(str.substr(0, countChar - 1));
    }
}
