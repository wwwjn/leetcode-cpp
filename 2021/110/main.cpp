#include <iostream>

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        if(root->left== NULL && root->right != NULL){
            if(root->right->left != NULL || root->right->right != NULL)
                return false;
            else return true;
        }
        else if(root->left!= NULL && root->right==NULL){
            if(root->left->left !=NULL || root->left->right!=NULL)
                return false;
            else return true;
        }
        else{
            bool height = false;
            int t = treeDepth(root->left) - treeDepth(root->right);
            if(t<=1 && t>=-1)
                height = true;
            if(!height)
                return false;
            else
                return isBalanced(root->left) && isBalanced(root->right);
        }

    }
    int treeDepth(TreeNode* root){
        if(root == NULL) return 0;
        else if(root->left == NULL && root->right!=NULL) return 1 + treeDepth(root->right);
        else if(root->left != NULL && root->right==NULL) return 1+ treeDepth(root->left);
        else return 1+max(treeDepth(root->left), treeDepth(root->right));
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
