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

void inorder(node *root)
{
    if(root==NULL)
        return;

    stack <node*> s;

    while(1)
    {
        if(root!=NULL)
        {
            s.push(root);
            root=root->left;
        }
        else
        {
            if(s.empty())
                break;
            else
            {
                root=s.top();
                cout<<root->data<<" ";
                s.pop();
                root=root->right;
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

  inorder(root);

  return 0;
}
