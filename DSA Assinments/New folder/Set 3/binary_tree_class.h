#include<iostream>
#include<queue>
using namespace std;
template<typename t>
class BinaryTreeNode{
    public:
    t data;
    BinaryTreeNode*left;
    BinaryTreeNode*right;
    BinaryTreeNode(t data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};
BinaryTreeNode<int>* take_input_tree_level_wise(){
    int n;
    cout<<"Enter root data\n";
    cin>>n;
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(n);
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int>*front=q.front();
        q.pop();
        int n1,n2;
        cout<<"Enter left data of "<<front->data<<endl;
        cin>>n1;
        cout<<"Enter right data of "<<front->data<<endl;
        cin>>n2;
        if(n1!=-1){
        BinaryTreeNode<int>*newNode1=new BinaryTreeNode<int>(n1);
        front->left=newNode1;
        q.push(front->left);
        }
        if(n2!=-1){
        BinaryTreeNode<int>*newNode2=new BinaryTreeNode<int>(n2);
        front->right=newNode2;
        q.push(front->right);
        }
    }
    return root;
}
void print_tree_level_wise(BinaryTreeNode<int>*root){
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    while(q.size()!=0){
        BinaryTreeNode<int>*front=q.front();
        q.pop();
        cout<<front->data<<" : ";
        if(front->left!=NULL){
            cout<<"L"<<front->left->data<<" ";
            q.push(front->left);
        }
        if(front->right!=NULL){
            cout<<"R"<<front->right->data;
            q.push(front->right);
        }
        cout<<endl;
    }
}