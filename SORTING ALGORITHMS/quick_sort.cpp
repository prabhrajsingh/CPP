#include<iostream>
#include<vector>
using namespace std;



int partition(vector<int> &V, int start, int end)
{
    int pivot = V[end];

    int i = start - 1;

    for(int j = start; j <= end - 1; j++)
    {
        if(V[j] < pivot)
        {
            i++;
            int temp = V[i];
            V[i] = V[j];
            V[j] = temp;

        }
    }

    int temp = V[i+1];
    V[i+1] = V[end];
    V[end] = temp;

    return (i+1);
}

void quick_sort(vector<int> &V, int start, int end)
{
    if(start < end)
    {
        int partitioning_index = partition(V, start, end);

        quick_sort(V, start, partitioning_index - 1);
        quick_sort(V, partitioning_index +1, end);
    }

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
    cout<<"UNSORTED : \n";
    for(int i:V)
    {
        cout<<i<<"\t";
    }
    cout<<endl<<endl;
    quick_sort(V, 0, n-1);
    cout<<"SORTED : \n";
    for(int i:V)
    {
        cout<<i<<"\t";
    }

    
}