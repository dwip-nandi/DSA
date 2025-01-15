#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;

    node(int n)
    {
        data = n;
        left = nullptr;
        right = nullptr;
    }
};
node *root = nullptr;

insert(node *root, int n){
    if(n<=root->data){
        if(root->left==nullptr){
           root->left = new node(n);
        }else{
            insert(root->left,n);
        }
    }
    else if(n>root->data){
        if(root->right==nullptr){
            root->right=new node(n);
        }else{
            insert(root->right,n);
        }
    }
}
void inorder(node *root){
    if(root==nullptr) return ;
    else{
        inorder(root->left);
        cout<<root->data<<' ';
        inorder(root->right);
    }
}
void preorder(node *root){
    if(root==nullptr)return ;
    else{
        cout<<root->data<<' ';
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node *root){
    if(root==nullptr)return ;
    else{
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<' ';
    }
}
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(root==nullptr){
            root = new node(x); 
        }else{
            insert(root,x);
        }
    }

    cout<<"Inorder Traversing :";
    inorder(root);
    cout<<endl;
    cout<<"Pre order Traversing :";
    preorder(root);
    cout<<endl;
    cout<<"Post Order Traversing :";
    postorder(root);
    cout<<endl;
}