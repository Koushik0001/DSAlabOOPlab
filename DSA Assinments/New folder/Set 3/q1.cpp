#include "binary_tree_class.h"
void preorder(BinaryTreeNode<int>*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(BinaryTreeNode<int>*root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    return;
}
void inorder(BinaryTreeNode<int>*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    BinaryTreeNode<int>*root=take_input_tree_level_wise();
    cout<<"Preorder-> "; 
    preorder(root);
    cout<<"\nInorder-> "; 
    inorder(root);
    cout<<"\nPostorder-> "; 
    postorder(root);
    cout<<endl;
    delete root;
}