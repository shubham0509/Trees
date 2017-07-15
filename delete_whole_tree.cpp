// use of postorder traversal because we need to delete the root's children first before the root itself
// in postorder traversal left->right->parent so it is used to delete the whole tree

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

void delete_tree(node *root)
{
    if(root==NULL)
        return;
    delete_tree(root->left);
    delete_tree(root->right);

    cout<<"Deleting node: "<<root->data<<endl;
    delete root;
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

  delete_tree(root);

  root=NULL;

  cout<<"Tree is Deleted."<<endl;

  return 0;
}



