#include<iostream>
#include<vector>
using namespace std;



int main()
{
    int n;
    cout<<"ENTER THE SIZE OF ARRAY : ";
    cin>>n;
    vector<int> A(n);
    for(int i=0; i<n; i++)
    {
        cin>>A[i];
    }

}