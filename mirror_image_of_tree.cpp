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

void mirror(node *root)
{
    if(root==NULL)
        return;

    mirror(root->left);
    mirror(root->right);

    node *temp;
    temp=root->left;
    root->left=root->right;
    root->right=temp;
}

void inorder(node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
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
  root->left        = newnode(3);
  root->right       = newnode(2);
  root->right->left  = newnode(5);
  root->right->right = newnode(4);

  cout<<"Inorder traversal of tree: ";
  inorder(root);
  cout<<endl;
  mirror(root);
  cout<<"Inorder of Mirror Image of the tree: ";
  inorder(root);

  return 0;
}



