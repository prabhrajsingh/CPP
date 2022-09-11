#include<iostream>
#include<string.h>
#include<vector>

using namespace std;
void solve(int open, int close, string output, vector<string> &ans)
{
    if(close == 0 && open == 0)
        ans.push_back(output);
    if(open != 0)
    {
        string output1 = output;
        output1.push_back('(');
        solve(open-1, close, output1, ans);
    }
    if(close > open)
    {
        string output2 = output;
        output2.push_back(')');
        solve(open, close-1, output2, ans);
    }

}
vector<string> generate(int n)
{
    vector<string> ans;
    int close = n, open = n;
    string output = "";
    solve(open, close, output, ans);
    return ans;
}
int main()
{
    int n;
    cout<<"ENTER THE NUMBER OF PAIRS A BRACKET CAN HAVE : ";
    cin>>n;
    vector<string> ans;
    ans = generate(n);
    cout<<"[";
    for(auto i : ans)
    {
        cout<<i<<"\t";
    }
    cout<<"]";
}