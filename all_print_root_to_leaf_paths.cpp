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

void print_path_rec(node *root,int arr[],int len);
void print_arr(int arr[],int len);

void print_paths(node *root)
{
    int arr[1000];
    print_path_rec(root,arr,0);
}

void print_path_rec(node *root,int arr[],int len)
{
    if(root==NULL)
        return;

    arr[len]=root->data;
    len++;

    if(root->left==NULL && root->right==NULL) //leaf node then print the path
        print_arr(arr,len);

    else
    {
        print_path_rec(root->left,arr,len);
        print_path_rec(root->right,arr,len);
    }
}

void print_arr(int arr[],int len)
{
    cout<<"Path: ";
    for(int i=0 ; i<len ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
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
  root->right->left->left  = newnode(6);

  print_paths(root);

  return 0;
}




