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

void morris_traversal(node *root)
{
    node *curr,*pre;
    if(root==NULL)
        return;
    curr=root;
    while(curr!=NULL)
    {
        if(curr->left==NULL)
        {
            cout<<curr->data<<" ";
            curr=curr->right;
        }
        else
        {
            pre=curr->left;

            while(pre->right!=NULL && pre->right!=curr)
                pre=pre->right;

            if(pre->right==NULL)
            {
                pre->right=curr;
                curr=curr->left;
            }

            else
            {
                pre->right=NULL;
                cout<<curr->data<<" ";
                curr=curr->right;
            }
        }
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

  node *root        = newnode(1);
  root->left        = newnode(2);
  root->right       = newnode(3);
  root->left->left  = newnode(4);
  root->left->right = newnode(5);

  morris_traversal(root);

  return 0;
}

