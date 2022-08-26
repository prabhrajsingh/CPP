#include<iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int new_data)
        {
            data = new_data;
            left = NULL;
            right = NULL;
            cout<<data<<"\t";
        }
};



void preorder(Node *traverse)
{
    if(traverse == NULL)
        return;
    
    cout<<traverse->data<<"\t";
    preorder(traverse->left);
    preorder(traverse->right);

}

void inorder(Node *traverse)
{
    if(traverse == NULL)
        return;
    inorder(traverse->left);
    cout<<traverse->data<<"\t";
    inorder(traverse->right);
}

void postorder(Node *traverse)
{
    if(traverse == NULL)
        return;
    
    postorder(traverse->left);
    postorder(traverse->right);
    cout<<traverse->data<<"\t";
}

int size_of_tree(Node *traverse)
{
    if(traverse == NULL)
    {
        return 0 ;
    }
    else
    {
        return (size_of_tree(traverse->left)  + 1 + size_of_tree(traverse->right));
    }
}

int identical_trees(Node *traverse1, Node *traverse2)
{
    if(traverse1 == NULL && traverse2 == NULL)
        return 1;
    
    if(traverse1 != NULL && traverse2 != NULL)
    {
        return (
                    traverse1->data == traverse2->data &&
                    identical_trees(traverse1->left, traverse2->left) &&
                    identical_trees(traverse1->right, traverse2->right)
               );
    }
    return 0;
}


int main()
{
    cout<<"LEVEL ORDER : \n";
    Node *root2 = new Node(1);
    
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<"\n\nPREORDER : \n";
    preorder(root);
    
    cout<<"\n\nINORDER : \n";
    inorder(root);
    
    cout<<"\n\nPOSTORDER : \n";
    postorder(root);

    cout<<endl<<endl;
    cout<<"SIZE OF TREE 1 : "<<size_of_tree(root);
    cout<<"\nSIZE OF TREE 2 : "<<size_of_tree(root2);

    cout<<endl<<endl<<"TWO TREES IDENTICAL ? :\n";
    
    if(identical_trees(root, root2))
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
}
