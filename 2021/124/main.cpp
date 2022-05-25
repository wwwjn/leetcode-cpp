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
    int maxPathSum(TreeNode* root) {
        int cur = INT_MIN;
        maxPath(root, cur);
        return cur;
    }

    int maxPath(TreeNode* root, int& curr){
        // 经过root的最优路径的值？
        // cur : current result
        if(root == NULL){
            return 0;
        }
        int left = maxPath(root->left, curr);
        int right = maxPath(root->right, curr);
        // 左中右，不向上返回。无法递归的情况
        int res1 = max(0, left) + root->val + max(0, right);
        // 从左/右子树经过root到root的父节点，最优。也是向上返回的值
        int res2 = max(0, max(left, right)) + root->val;
        curr = max(curr, max(res1, res2));
        return res2;
    }
};