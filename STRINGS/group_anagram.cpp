#include<iostream>
#include<unordered_map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<typeinfo>
 
using namespace std;

void group_anagram(vector<string> &strs, vector<vector<string>> &ans)
{
    unordered_map<string, vector<string>> umap;
    for(string i : strs)
    {
        string temp = i;
        sort(temp.begin(), temp.end());
        umap[temp].push_back(i);
    }

    for(auto i:umap)
    {
        ans.push_back(i.second);
    }
}
int main()
{
    vector<string> strs = {"eat", "ate", "tea", "tan", "nat", "bat"};
    vector<vector<string>> ans;
    group_anagram(strs, ans);
    cout<<"[";
    for(auto i : ans)
    {
        cout<<"[";
        for(auto j : i)
        {
            cout<<" "<<j<<" ";
        }
        cout<<"]";
    }
    cout<<"]";
}