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

int count_leaf_nodes(node *root)
{
    if(root==NULL)
        return 0;

    if(root->left==NULL && root->right==NULL)
        return 1;
    else
    {
        int lcount=count_leaf_nodes(root->left);
        int rcount=count_leaf_nodes(root->right);
        return (lcount+rcount);
    }
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

  node *root         = newnode(1);
  root->left         = newnode(2);
  root->right        = newnode(3);
  root->left->left   = newnode(4);
  root->left->right  = newnode(5);
  root->right->left  = newnode(6);
  root->right->right = newnode(7);

  int n=count_leaf_nodes(root);

  cout<<"No. of the leaf nodes is: "<<n<<endl;

  return 0;
}



