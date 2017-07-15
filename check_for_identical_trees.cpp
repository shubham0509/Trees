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

bool check(node *root1,node* root2)
{
    if(root1==NULL && root2==NULL)
        return true;

    if(root1!=NULL && root2!=NULL)
    {
        if((root1->data==root2->data) && (check(root1->left,root2->left)) && (check(root1->right,root2->right)))
            return true;
    }

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

    node *root1 = newNode(1);
    node *root2 = newNode(1);

    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left  = newNode(4);
    root1->left->right = newNode(5);

    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);

    if(check(root1, root2))
        cout<<"Both trees are identical.";
    else
        cout<<"Trees are not identical.";

    return 0;
}


