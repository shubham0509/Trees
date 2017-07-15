#include<iostream>
#include<stack>

using namespace std;

class node
{
   public:
       int data;
       node* left;
       node* right;
};

int size(node *root)
{
    if(root==NULL)
        return 0;
    int lsize=size(root->left);
    int rsize=size(root->right);
    return (lsize+rsize+1);
}

node* newnode(int data)
{
  node* root = new node;
  root->data = data;
  root->left = NULL;
  root->right = NULL;

  return root;
}

int main()
{

  node *root        = newnode(1);
  root->left        = newnode(2);
  root->right       = newnode(3);
  root->left->left  = newnode(4);
  root->left->right = newnode(5);

  int s=size(root);

  cout<<"Size of the tree is: "<<s<<endl;

  return 0;
}


