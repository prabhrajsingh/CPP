#include<iostream>
#include<vector>

using namespace std;
vector<int> bubble_sort(vector<int>& A)
{
    int n = A.size();

    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(A[j] > A[j+1])
            {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
    return A;

}
int main()
{
    int n;
    cout<<"ENTER THE SIZE OF ARRAY : ";
    cin>>n;

    vector<int> A(n,0);
    cout<<" ENTER THE ELEMENTS : "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>A[i];
    }
    cout<<endl;
    cout<<"UNSORTED : \n";
    for(int i:A)
    {
        cout<<i<<"\t";
    }
    A = bubble_sort(A);
    cout<<endl<<endl<<"SORTED : \n";

    for(int i:A)
    {
        cout<<i<<"\t";
    }
    return 0;
}