#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
void string_sub_string()
{
    string s1 = "abcdefbcdbcdefgbcd";
    string s2 = "bcd";
    int n = s1.size();
    int m = s2.size();
    int ans = 0;
    for(int i=0; i<= n - m; i++)
    {
        int j;
        for(j = 0; j<m; j++)
        {
            if(s1[i+j] !=  s2[j])
                break;
        }
        if(j == m)
        {
            ans++;
        }
    }
    cout<<ans<<endl<<endl;
}
int sum_of_number(int n)
{
    int sum = 0;
    while (n != 0) 
    {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;

}
void array_elements_sum()
{
    vector<int> V;
    int j = 0;
    for(int i=100; i<131; i++)
    {
        V.push_back(i);
        cout<<V[j]<<"\t";
        j++;
    }

    cout<<endl<<endl;
    int totalsum = 0;
    for(int i=0; i<V.size(); i++)
    {
        cout<<sum_of_number(V[i])<<"\t";
        totalsum += sum_of_number(V[i]);
    }
    cout<<endl;
    cout<<"TOTAL SUM : " <<totalsum<<endl;
}
int main()
{
    string_sub_string();
    array_elements_sum();
}