#include <iostream>

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // return the new root of the tree
        if(root == NULL) return NULL;
        if(root->val > key){
            root->left = deleteNode(root->left, key);
            return root;
        }
        else if(root->val < key){
            root->right = deleteNode(root->right, key);
            return root;
        }

        else {    // if(root->val == key)
            TreeNode* delNode = root;
            // find the node with max value in left subtree;
            if(delNode->left == NULL){
                return delNode->right;
            }else{
                TreeNode* replNode = delNode->left;
                TreeNode* replparent = delNode;
                while(replNode->right != NULL){
                    replparent = replNode;
                    replNode = replNode->right;
                }
                if(replparent == delNode){
                    replNode->right = delNode -> right;
                    return replNode;
                }else{
                    replparent->right = replNode->left;
                    replNode->left = delNode->left;
                    replNode->right = delNode -> right;
                    return replNode;
                }
            }
        }
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
