#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<unordered_set>

using namespace std;

// int longestsubstringlength(string s)
// {
//     int n = s.size();
//     int start = 0, traverse = 0, ans = 0;
//     unordered_set<char> set;
//     while(traverse < n)
//     {
//         if(set.find(s[traverse]) == set.end())
//         {
//             set.insert(s[traverse++]);
//             ans = max(ans, traverse - start);
//         }
//         else
//         {
//             set.erase(s[start++]);
//         }
//     }
//     return ans;
// }
int longestsubstringlength(string s)
{
    int n = s.size();
    vector<int> dict(256, -1);
    int maxlen = 0 , start = -1;
    int first=0;
    for(int i=0; i<n; i++)
    {
        if(dict[s[i]] > start)
        {
            start = dict[s[i]];
        }
        dict[s[i]] = i;
        maxlen = max(maxlen, i - start);
    }
    return maxlen;
}
int main()
{
    string s;
    cout<<"ENTER THE STRING : ";
    getline(cin, s);
    int n = s.size();
    cout<<endl;
    cout<<longestsubstringlength(s);
    

}