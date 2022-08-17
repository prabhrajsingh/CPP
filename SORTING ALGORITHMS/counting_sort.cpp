#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<int> counting_sort(vector<int> &V)
{  
    int n = V.size();

    vector<int> output(n+1);  

    int max = *max_element(V.begin(), V.end());  

    vector<int> count(max+1,0); 
   
    for (int i = 0; i < n; i++)
    {  
        count[V[i]]++;  
    }
   
    for(int i = 1; i<=max; i++)   
    {
        count[i] += count[i-1]; 
    }
   
    for (int i = n - 1; i >= 0; i--) 
    {
        output[count[V[i]] - 1] = V[i];  
        count[V[i]]--;
    }  
   
    for(int i = 0; i<n; i++) 
    {
        V[i] = output[i]; 
    } 
    return V;
}  

int main()
{
    int n;
    cout<<"ENTER HOW MANY ELEMENTS : ";
    cin>>n;
    vector<int> V(n);

    cout<<"ENTER THE ELEMENTS : \n";
    for(int i=0; i<n; i++)
    {
        cin>>V[i];
    }
    cout<<"\nUNSORTED : \n";
    for(int i:V)
    {
        cout<<i<<"\t";
    }
    cout<<endl<<endl<<endl;

    V = counting_sort(V);

    cout<<"\nSORTED : "<<endl;
    for(int i:V)
    {
        cout<<i<<"\t";
    }

}