#include"binary_tree_class.h"
#include<climits>
class BST{
    BinaryTreeNode<int>*root;
    public:
    BST(){
        root=NULL;
    }
    ~BST(){
        delete root;
    }
    private:
    bool search_helper(int data,BinaryTreeNode<int>*node){
        if(node==NULL){
            return 0;
        }
        if(node->data=data){
            return 1;
        }
        if(node->data>data){
            return search_helper(data,node->left);
        }
        if(node->data<data){
            return search_helper(data,node->right);
        }
    }
    BinaryTreeNode<int>* insert_helper(int data,BinaryTreeNode<int>*node){
        if(node==NULL){
            BinaryTreeNode<int>*n=new BinaryTreeNode<int>(data);
            return n;
        }
        
        if(node->data>data){
            node->left = insert_helper(data,node->left);
        }
        else{
            node->right = insert_helper(data,node->right);
        }
        return node;
    }
    public:
    void insert(int data){
        this->root = insert_helper(data,root);
    }
    bool search(int data){
        return search_helper(data,root);
    } 
};
int main(){
    BST *tree = new BST();

    int nodes;
    cout << "Enter the number of nodes : ";
    cin >> nodes;

    cout << "Start entering the numbers to insert nodes : ";
    for(int i = 0; i < nodes; i++){
        int n;
        cin >> n;
        tree->insert(n);
    }

    int num;
    cout << "Enter the element to search for : ";
    cin >> num;

    cout << (tree->search(num) ? "PRESENT" : "NOT PRESENT") << endl;
}