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

void increment(node *root,int diff)
{
    if(root->left!=NULL)
    {
        root->left->data=root->left->data+diff;
        increment(root->left,diff);
    }
    else if(root->right!=NULL)
    {
        root->right->data=root->right->data+diff;
        increment(root->right,diff);
    }
}

void convert_tree(node *root)
{
    if((root==NULL) || ((root->left==NULL)&&(root->right==NULL)))
        return;

    int ldata=0,rdata=0;

    convert_tree(root->left);
    convert_tree(root->right);

    if(root->left!=NULL)
        ldata=root->left->data;
    if(root->right!=NULL)
        rdata=root->right->data;

    int diff=(ldata+rdata)-(root->data);

    if(diff>0)
        root->data=root->data+diff;
    if(diff<0)
        increment(root,-diff);

}

void inorder(node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

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

  struct node *root = newNode(50);
  root->left        = newNode(7);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left  = newNode(1);
  root->right->right = newNode(30);

  cout<<"Inorder traversal of the tree.. before conversion ..: ";
  inorder(root);

  cout<<endl;

  convert_tree(root);

  cout<<"Inorder traversal after the conversion..: ";
  inorder(root);

  cout<<endl;

  return 0;
}





