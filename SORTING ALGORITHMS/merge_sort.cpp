#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> &V, int start, int mid, int end)
{
    int i = start, j = mid+1;
    
    int n = V.size();

    vector<int> temp;

    while(i <= mid && j<=end)
    {
        if(V[i] <= V[j])
        {
            temp.push_back(V[i]);
            i++;
        }
        else
        {
            temp.push_back(V[j]);
            j++;
        }
    }
    while(i<=mid)
    {
        temp.push_back(V[i]);
        i++;
    }
    while(j<=end)
    {
        temp.push_back(V[j]);
        j++;
    }

    for(int i=start; i<=end; i++)
    {
        V[i] = temp[i-start];
    }
}

void merge_sort(vector<int> &V, int start, int end)
{
    if(start < end)
    {
        int mid = (start + end)/2;

        merge_sort(V, start, mid);
        merge_sort(V, mid+1, end);

        merge(V, start, mid, end);
    }
}

int main()
{
    int n;
    cout<<"ENTER HOW MANY ELEMENTS : ";
    cin>>n;
    vector<int> V(n,0);
    cout<<"ENTER ELEMENTS : "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>V[i];
    }
    cout<<"UNSORTED : "<<endl;
    for(int i:V)
    {
        cout<<i<<"\t";
    }
    cout<<endl<<endl<<endl;

    merge_sort(V, 0, n-1);

    cout<<"SORTED : "<<endl;
    for(int i:V)
    {
        cout<<i<<"\t";
    }
}