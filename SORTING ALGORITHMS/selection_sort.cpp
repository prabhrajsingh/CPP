#include<iostream>
#include<vector>
using namespace std;
vector<int> selection_sort(vector<int> &V)
{
    int n = V.size();
    for(int i =0; i<n-1; i++)
    {
        int min_step = i;
        for(int j = i+1; j<n; j++)
        {
            if(V[j] < V[min_step])
            {
                min_step = j;
            }
        }
        int temp = V[min_step];
        V[min_step] = V[i];
        V[i] = temp;
    }
    return V;
}
int main()
{
    int n;
    cout<<"ENTER THE NUMBER OF ELEMENTS : ";
    cin>>n; 
    vector<int> V(n,0);
    cout<<endl;
    cout<<"ENTER THE ELEMENTS : ";
    for(int i=0; i<n; i++)
    {
        cin>>V[i];
    }
    cout<<"\nUNSORTED : \n";
    for(int i:V)
    {
        cout<<i<<"\t";
    }
    cout<<endl<<endl;
    
    V = selection_sort(V);

    cout<<"\nSORTED : \n";
    for(int i:V)
    {
        cout<<i<<"\t";
    }

}