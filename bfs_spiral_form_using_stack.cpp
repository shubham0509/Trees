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

void spiral(node *root)
{
    if(root==NULL)
        return;

    stack<node*>s1;
    stack<node*>s2;

    s1.push(root);

    while(!s1.empty() || !s2.empty())
    {

        while(!s1.empty())
        {
            node *temp;
            temp=s1.top();
            s1.pop();
            cout<<temp->data<<" ";
            if(temp->right)
                s2.push(temp->right);
            if(temp->left)
                s2.push(temp->left);
        }

        while(!s2.empty())
        {
            node *temp;
            temp=s2.top();
            s2.pop();
            cout<<temp->data<<" ";
            if(temp->left)
                s1.push(temp->left);
            if(temp->right)
                s1.push(temp->right);
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

  node *root         = newnode(1);
  root->left         = newnode(2);
  root->right        = newnode(3);
  root->left->left   = newnode(4);
  root->left->right  = newnode(5);
  root->right->left  = newnode(6);
  root->right->right = newnode(7);

  spiral(root);

  return 0;
}





