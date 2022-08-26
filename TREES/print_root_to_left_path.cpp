#include<iostream>
#include<vector>
using namespace std;
class Node
{
    public:
        int data;
        Node *left, *right;
        Node(int new_data);
};
Node :: Node(int new_data)
{
    data = new_data;
    left = NULL;
    right = NULL;
}

void print_path(Node *traverse, int path[], int N)
{
    if (traverse == NULL)
    {
        return;
    }

    path[N] = traverse->data;
    N++;

    if(traverse->left == NULL && traverse->right == NULL)
    {
        for(int i=0; i<N; i++)
        {
            cout<<path[i]<<"\t";
        }
        cout<<endl;
    }

    else
    {
        print_path(traverse->left, path, N);
        print_path(traverse->right, path, N);
    }
}
void path_root_to_leaf(Node *traverse)
{
    int path[10000];
    print_path(traverse, path, 0);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout<<"\n\nALL THE PATH FOR ROOT TO LEAF : \n";
    path_root_to_leaf(root);

}