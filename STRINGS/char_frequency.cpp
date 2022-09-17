#include<iostream>
#include<string.h>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<sstream>
using namespace std;
int main()
{
    string s;
    cout<<"ENTER THE STRING :" ;
    getline(cin,s);
    int n = s.size();
    cout<<s<<endl;
    vector<int> freq(n, 0);
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(s[i] == s[j])
            {
                freq[j]++;
            }
        }
    }
    for(int i : freq)
    {
        cout<<i;
    }

    s = "this is a trial test that this sentence is deing done for and for that i am writing this test";
    unordered_map<string, int> mpp;
    // for(int i = 0; i<n; i++ )
    // {
    //     mpp[s[i]]++;
    // }
    string word, revstring = " ";
    stringstream ss(s); 
    cout<<endl;
    while(ss >> word)
    {
        cout<<word<<endl;
        revstring = word + " " + revstring;
        mpp[word]++;
    }
    cout<<endl;
    cout<<"REVERSE SENTENCE BUT KEEPING THE WORDS SAME  : "<<revstring<<endl;
    cout<<"\n\nDUPLICATES : \n";
    for(auto i : mpp)
    {
        //if(i.second > 1)
        //{
            cout<<i.first<<" : "<<i.second<<endl;
        //}
    }

}
