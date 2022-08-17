#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void heapify(vector<int> &V, int n,  int i)
{
  
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && V[left] > V[largest])// If left child is larger than root
    {
        largest = left;
    }

    if(right < n && V[right] > V[largest])
    {
        largest = right;
    }
    if(largest != i)
    {
        swap(V[i], V[largest]);
        heapify(V, n, largest);
    }
}

void heap_sort(vector<int>&V)
{
    int n = V.size();

    for(int i=n/2 - 1; i>=0; i--)
    {
        heapify(V, n, i);
    }

    for(int i=n-1; i>=0; i--)
    {
        swap(V[0], V[i]);
        heapify(V, i, 0);
    }
}

int main()
{
    int n;
    cout<<"ENTER HOW MANY ELEMENTS : ";
    cin>>n;

    vector<int> V(n);
    cout<<"ENTER ELEMENTS : \n";
    for(int i=0; i<n; i++)
    {
        cin>>V[i];
    }
    cout<<"\nUNSORTED : \n";
    for(int i:V)
    {
        cout<<i<<"\t";
    }

    heap_sort(V);

    cout<<"\nSORTED : \n";
    for(int i:V)
    {
        cout<<i<<"\t";
    }
}