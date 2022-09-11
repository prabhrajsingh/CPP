#include<iostream>
#include<string.h>
#include<sstream>
using namespace std;
int main()
{
    string s;
    cout<<"ENTER THE STRING : ";
    getline(cin, s);
    int n = s.size();
    int start  = 0,  end = n-1;
    int flag = 0;
    while(start < end)
    {
        while(isalnum(s[start]) == false  && start < end)
            start++;
        while(isalnum(s[end]) == false && start < end)
            end--;
        
        if(tolower(s[start]) != tolower(s[end]))
        {
            flag = 0;
            break;
        }
        start++;
        end--;
        flag = 1;
    }
    if(flag == 1)
        cout<<"YES";
    else if(flag == 0)
        cout<<"NO";
}

/* this is one way 
other being 

first check if the string is valid or not that is it should not contain any other characters other than alphabets or numbers
create a temporary string to put that valid string into this string
then make it lowercase 
then simply check for palindrome as it was a single word.
*/
