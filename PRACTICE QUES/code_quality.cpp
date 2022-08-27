#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    switch(n%3 && n%5 )
    {
        case 0: cout<<"FIZZBUZZ";
                                break;
        case 1 : cout<<"FIZZ";
                            break;
        case 2: cout<<"BUZZ";
                            break;
        default : cout<<" ";

    }
}