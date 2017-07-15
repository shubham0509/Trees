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

int height(node *root)
{
    if(root==NULL)
        return 0;

    int lheight=height(root->left);
    int rheight=height(root->right);

    if(lheight>rheight)
        return lheight+1;
    else
        return rheight+1;
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

  int h=height(root);

  cout<<"Height of the tree is: "<<h<<endl;

  return 0;
}



