#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int main()
{
    vector<int> V1, V2;
    int k = 1;
    for(int i=0; i<5; i++)
    {
        V1.push_back(k);
        V2.push_back(k);
        k++;
    }

    for(int i : V1)
    {
        cout<<i<<" ";
    }
    cout<<endl<<endl;
    for(int i : V2)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    int j = V1.size()-1;
    int num1 = 0;
    for(int i=0; i<V1.size(); i++)
    {
        num1 = num1 + pow(10, j) * V1[i];
        j--;
    }

    int num2 = 0;
    int p = V2.size() - 1;
    for(int i=0; i<V2.size(); i++)
    {
        num2 = num2 + pow(10, p) * V2[i];
        p--;
    }
    cout<<"RESULT : "<<num1+num2;
}