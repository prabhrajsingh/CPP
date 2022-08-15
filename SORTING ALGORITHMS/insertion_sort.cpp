#include<iostream>
#include<vector>
using namespace std;

vector<int> insertion_sort(vector<int> &V)
{
    int n = V.size();
    int min=0, j=0;
    for(int i=1; i<n; i++)
    {
        min = V[i];
        j = i-1;

        while(j >= 0 && V[j] > min)
        {
            V[j+1] = V[j];
            j--;
        }
        V[j+1] = min;
    }
    return V;

}

int main()
{
    int n;
    cout<<"ENTER THE SIZE OF ARRAY/VECTOR : ";
    cin>>n;
    vector<int> V(n,0);
    cout<<"ENTER ELEMENTS : ";
    for(int i=0; i<n; i++)
    {
        cin>>V[i];
    }
    cout<<endl<<endl;
    cout<<"UNSORTED : \n";
    for(int i:V)
    {
        cout<<i<<"\t";
    }
    cout<<endl<<endl;
    V = insertion_sort(V);
    cout<<"SORTED : \n";
    for(int i:V)
    {
        cout<<i<<"\t";
    }
}