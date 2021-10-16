#include <iostream>
using namespace std;
void stringPalindrome(char arr[],int n){
    static int count =0,p1 =-1,p2 =n;
    p1++;
    p2--;
    if(p1 == p2){
        if(count == n/2){
            cout<<"It is a palindrome";
        }
        else{
            cout<<"It is not a palindrome";
        }
    }
    else if(arr[p1]==arr[p2]){
        count++;
        stringPalindrome(arr,n);
    }
    else{
        cout<<endl<<"Not a palindrome";
    }
}
int main(){
    char arr[] = "hello";
    stringPalindrome(arr,sizeof(arr));


    return 0;
}