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
    BinaryTreeNode<int>* delete_node_helper(int data,BinaryTreeNode<int>* node){
        if(node==NULL){
            return NULL;
        }
        if(node->data>data){
            node->left = delete_node_helper(data,node->left);
            return node;
        }
        else if(node->data<data){
            node->right = delete_node_helper(data,node->right);
            return node;
        }
        else{
            if(node->left==NULL && node->right==NULL){
                delete node;
                return NULL;
            }
            else if(node->left==NULL){
                BinaryTreeNode<int>*temp=node->right;
                node->right=NULL;
                delete node;
                return temp;
            }
            else if(node->right==NULL){
                BinaryTreeNode<int>*temp=node->left;
                node->left=NULL;
                delete node;
                return temp;
            }
            else{
                BinaryTreeNode<int>*rightmin=node->right;
                while(rightmin->left!=NULL){
                    rightmin=rightmin->left;
                }
                int mindata=rightmin->data;
                node->data=mindata;
                node->right=delete_node_helper(mindata,node->right);
                return node;
            }
        }
    }
    int findMin_helper(BinaryTreeNode<int>* root){
        if(root == NULL)
            return INT_MAX;
        
        int m = root->data;
        return min(m, findMin_helper(root->left));
    }

    int findMax_helper(BinaryTreeNode<int>* root){
        if(root == NULL)
            return INT_MIN;
        
        int m = root->data;
        return max(m, findMax_helper(root->right));
    }
    public:
    void insert(int data){
        this->root = insert_helper(data,root);
    }
    void delete_node(int data){
        this->root = delete_node_helper(data,root);
    }
    void print(){
        print_tree_level_wise(root);
    }
    int findMax(){
        return findMax_helper(root);
    }
    int findMin(){
        return findMin_helper(root);
    }
};
int main() {
    BST *tree = new BST();
    int i=0;
    while(i!=6){
        cout<<"Choose a option:\n";
        cout<<"1.insert new node\t2.delete node\t3.print tree\n";
        cout<<"4.generate minimum element\t5.generate maximum element\t6.terminate\n";
        cin>>i;
        switch(i){
            case 1:
            int newNum;
            cout << "Enter the new Number to insert : ";
            cin >> newNum;
            tree->insert(newNum);
            break;
            case 2:
            cout << "b) Enter the data to remove : ";
            int num;
            cin >> num;
            tree->delete_node(num);
            break;
            case 3:
            cout << "The current tree is : \n";
            tree->print();
            cout << endl;
            break;
            case 4:
            cout << "c) The minimum number in tree : " << tree->findMin() << endl;
            break;
            case 5:
            cout << "d) The maximum number in tree : " << tree->findMax() << endl;
            break;
            case 6:
            break;
        }
    }
    return 0;
}