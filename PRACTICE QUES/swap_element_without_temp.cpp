#include<iostream>
using namespace std;
int main()
{
    int a, b;
    cout<<"ENTER THE NUMBER - 1 : ";
    cin>>a;
    cout<<"ENTER THE NUMBER - 2 : ";
    cin>>b;
    cout<<endl<<endl<<a<<"\t"<<b<<endl;
    a = a + b;
    b = a - b;
    a = a - b;
    cout<<a<<"\t"<<b;
}