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

bool check_children_sum(node *root)
{
    if((root==NULL) || ((root->left==NULL) && (root->right==NULL)))
        return true;
    int ldata=0,    rdata=0;
    if(root->left!=NULL)
        ldata=root->left->data;
    if(root->right!=NULL)
        rdata=root->right->data;

    if((root->data==ldata+rdata) && (check_children_sum(root->left)) && (check_children_sum(root->right)))
        return true;
    else
        return false;
}

node* newNode(int data)
{
  node* root = new node;
  root->data = data;
  root->left = NULL;
  root->right = NULL;

  return root;
}

int main()
{

  node *root         = newNode(10);
  root->left         = newNode(8);
  root->right        = newNode(2);
  root->left->left   = newNode(3);
  root->left->right  = newNode(5);
  root->right->right = newNode(2);

  if(check_children_sum(root))
    cout<<"The tree satisfies the children sum property...!!!"<<endl;
  else
    cout<<"The tree doesn't satisfies the children sum property...!!!"<<endl;

  return 0;
}




