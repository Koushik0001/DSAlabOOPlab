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
    int leafCount_helper(BinaryTreeNode<int>* node){
    if(node == NULL)
        return 0;
    
    if(node->left == NULL and node->right == NULL)
        return 1;
    
    int ans = 0;
    if(node->left != NULL)
        ans += leafCount_helper(node->left);
    
    if(node->right != NULL)
        ans += leafCount_helper(node->right);
    
    return ans;
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
    int leafCount(){
        return leafCount_helper(root);
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

    cout << "The Number of Leaf Nodes are : " << tree->leafCount() << endl;
}