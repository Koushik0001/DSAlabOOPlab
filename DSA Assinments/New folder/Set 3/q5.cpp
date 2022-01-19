#include"binary_tree_class.h"

#include <cstdlib>
class Pair2{
    public:
    bool balance;
    int height;
};

Pair2 helper(BinaryTreeNode<int>* root){
    if(root == NULL){
        Pair2 now;
        now.balance = true;
        now.height = 0;
        return now;
    }
    
    Pair2 leftAns = helper(root->left);
    Pair2 rightAns = helper(root->right);
    
    if(leftAns.balance && rightAns.balance)
    {
        if(abs(leftAns.height - rightAns.height) <= 1)
        {
            Pair2 smallAns;
            smallAns.balance = true;
            smallAns.height = 1+max(leftAns.height, rightAns.height);
            return smallAns;
        }
        
        else{
            Pair2 or_kya_kare;
            or_kya_kare.height = 1+max(leftAns.height, rightAns.height);
            or_kya_kare.balance = false;
            return or_kya_kare;
        }
    }
    
    else{
        	Pair2 or_kya_kare;
            or_kya_kare.height = 1+max(leftAns.height, rightAns.height);
            or_kya_kare.balance = false;
            return or_kya_kare;
    }
}

void printLevelWiseBT(BinaryTreeNode<int>* root){
    if(root == NULL)
        return;
    
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        BinaryTreeNode<int>* frontNode = q.front();
        q.pop();
        cout << frontNode->data << " :";

        if(frontNode->left != NULL){
            cout << " L: "<< frontNode->left->data;
            q.push(frontNode->left);
        }

        else if(frontNode->left == NULL){
            cout << " L: -1";
        }

        if(frontNode->right != NULL){
            cout <<",R : " <<  frontNode->right->data << " ";
            q.push(frontNode->right);
        }

        else if(frontNode->right == NULL){
            cout << ",R: -1";
        }

        cout << endl;
    }
}

bool isAVL(BinaryTreeNode<int>* root){
    Pair2 ans = helper(root);
    return ans.balance;
}


int findHeight(BinaryTreeNode<int>* root){
    if(root == NULL)
        return 0;
    
    int h1 = findHeight(root->left);
    int h2 = findHeight(root->right);

    return max(h1, h2) + 1;
}

BinaryTreeNode<int>* makeAVL(BinaryTreeNode<int>* root){
    if(root == NULL)
		return NULL;

    BinaryTreeNode<int>* leftAns = makeAVL(root->left);
	root->left = leftAns;

    BinaryTreeNode<int>* rightAns = makeAVL(root->right);
    root->right = rightAns;

	int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
	
	if((leftHeight - rightHeight) > 1)
	{
		BinaryTreeNode<int>* temp1 = root->left;
		root->left = NULL;

		if(temp1->right == NULL)
			temp1->right = root;

		else
		{
			BinaryTreeNode<int>* temp2 = temp1->right;
			temp1->right = NULL;
			temp1->right = root;
			root->left = temp2;
		}

		return temp1;
	}

	else if((rightHeight - leftHeight) > 1)
	{
		BinaryTreeNode<int>* temp1 = root->right;
		root->right = NULL;

		if(temp1->left == NULL)
			temp1->left = root;

		else
		{
			BinaryTreeNode<int>* temp2 = temp1->left;
			temp1->left = NULL;
			temp1->left = root;
			root->right = temp2;
		}
        
		return temp1;
	}

	else
		return root;
}

int main(){
    cout << "Give the Input of a BST levelwise : " << endl;
    BinaryTreeNode<int>* root = take_input_tree_level_wise();

    cout << ((isAVL(root) ? "AVL tree" : "NOT AVL tree")) << endl;
    cout << endl;

    if(!isAVL(root)){
        cout << endl << "As it is not a AVL tree : Making it AVL by passing the root node in function : " << endl;
        BinaryTreeNode<int>*newRoot =  makeAVL(root);
        cout << "Now the given tree is an : ";
        cout << ((isAVL(newRoot) ? "AVL tree" : "NOT AVL tree")) << endl;

        cout << "The tree is : " << endl;
        printLevelWiseBT(newRoot);
        
    }
    return 0;
}