#include<iostream>
#include<vector>
using namespace std;


void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;    
}

int main()
{
    int n;
    cout<<"ENTER HOW MANY ELEMENTS : ";
    cin>>n;

    vector<int> V(n,0);
    cout<<"ENTER ELEMENTS : ";

    for(int i=0; i<n; i++)
    {
        cin>>V[i];
    }
    
}