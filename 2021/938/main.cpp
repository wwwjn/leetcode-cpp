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
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int res = 0;
        preorder(root, low, high, res);
        return res;
    }

    void preorder(TreeNode* node, int low, int high, int& res){
        if(node == NULL){
            return;
        }
        // visited 'node'
        if(node->val >= low && node->val <= high){
            res += node->val;
            preorder(node->left, low, high, res);
            preorder(node->right, low, high, res);
        }
        else if(node->val < low){
            preorder(node->right, low, high, res);
        }else{
            preorder(node->left, low, high, res);
        }
    }

};