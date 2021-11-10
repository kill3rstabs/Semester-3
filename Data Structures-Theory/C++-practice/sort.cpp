#include <iostream>
#include <string> //To avail string functions
using namespace std;

int main(){
  string str;
  char temp;
  cout << "Enter the string to be sorted: ";
  getline(cin, str);
  int len = str.length();
  cout << "\n String before sorting: " << str << " \n";

  for (int i = 0; i < len; i++){

    for (int j = 0; j < len - 1; j++){
      if (str[j] > str[j + 1]){ //if j has larger ascii value than the next,

        //swapping the prev and next characters

        temp = str[j];
        str[j] = str[j + 1];
        str[j + 1] = temp;
      }
    }
  }

  cout << "\n String after sorting: " << str << " \n";
  return 0;
}
