#include<iostream>
#include<string>
using namespace std;

int set_value(char s)
{
    if(s=='I')
        return 1;
    if(s=='V')
        return 5;
    if(s=='X')
        return 10;
    if(s=='L')
        return 50;
    if(s=='C')
        return 100;
    if(s=='D')
        return 500;
    if(s=='M')
        return 1000;
    return -1;
}
int main()
{
    string s;
    cout<<"ENTER THE NUMBER IN ROMAN : ";
    getline(cin, s);

    int ans = 0;

    for(int i=0; i<s.size(); i++)
    {
        int temp1 = set_value(s[i]);

        if(i+1 < s.size())
        {
            int temp2 = set_value(s[i+1]);

            if(temp1 >= temp2)
            {
                ans = ans + temp1;
            }
            else
            {
                ans = ans + temp2 - temp1;
            }
        }
        else
        {
            ans = ans + temp1;
        }
    }
    cout<<endl<<"INTEGER : "<<ans;
}