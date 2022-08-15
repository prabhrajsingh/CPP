#include<iostream>
#include<vector>

using namespace std;
class Node 
{
    public:
        int data;
        Node *next;
};
Node *head = new Node();
vector<int> ans;

void insert(int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}

vector<int> conversion()
{
    Node *traverse = head;
    while(traverse != NULL)
    {
        ans.push_back(traverse->data);
        traverse = traverse->next;
    }
    return ans;
}
void display()
{
    for(int i:ans)
    {
        cout<<i<<endl;
    }
}
int main()
{
    int n=0;
    for(int i=1; i<=5; i++)
    {
        insert(i);
        n++;
    }
    conversion();
    for(int i:ans)
    {
        cout<<i<<"\t";
    }
}