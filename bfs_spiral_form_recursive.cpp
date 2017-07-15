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

void bfs_recursive(node *root,int level,bool itr)
{
    if(root==NULL)
        return;

    if(level==1)
        cout<<root->data<<" ";

    else if(level>1)
    {
        if(itr)
        {
            bfs_recursive(root->left,level-1,itr);
            bfs_recursive(root->right,level-1,itr);
        }
        else
        {
            bfs_recursive(root->right,level-1,itr);
            bfs_recursive(root->left,level-1,itr);
        }
    }
}

void bfs(node *root)
{
    bool itr=false;
    int h=height(root);
    for(int i=1 ; i<=h ; i++)
    {
        bfs_recursive(root,i,itr);
        itr=!itr;
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

  bfs(root);

  return 0;
}




