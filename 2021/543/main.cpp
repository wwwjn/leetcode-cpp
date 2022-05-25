#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int res1 = depth(root->left) + depth(root->right);
        int res2 = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
        return max(res1, res2);
    }
    int depth(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return max(depth(root->left), depth(root->right)) + 1;
    }
};