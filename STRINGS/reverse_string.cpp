#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    int n = s.size();
    for(int i = n - 1; i>=0; i--)
    {
        cout<<s[i]<<"\t";
    }
    for(int i = 0; i<n/2; i++)
    {
        swap(s[i], s[n-1-i]);
    }
    cout<<endl<<s;


}