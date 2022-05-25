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
    int longestConsecutive(TreeNode* root) {
        int res = 0;
        dfs(root, 1, res);
        return res;
//         if(root->left != NULL && root->right != NULL && root->val == root->left->val - 1 && root->val == root->right->val - 1){
//             return max(longestConsecutive(root->left), longestConsecutive(root->right)) + 1;

//         }
//         else if(root->left != NULL && root->val == root->left->val - 1){
//             return max(longestConsecutive(root->left) + 1, longestConsecutive(root->right));
//         }else if(root->right != NULL && root->val == root->right->val - 1){
//             return max(longestConsecutive(root->right) + 1, longestConsecutive(root->left));
//         }else{
//             int res = max(longestConsecutive(root->left), longestConsecutive(root->right));
//             return max(res, 1);
//         }

    }
    void dfs(TreeNode* root, int len, int& res){
        // 给每个点都标记len
        // res: the longest path in the whole tree
        res = max(len, res);
        // len: the max length to the node root
        if(root->left != NULL){
            if(root->left->val == root->val + 1)
                dfs(root->left, len+1, res);
            else
                dfs(root->left, 1, res);
        }
        if(root->right != NULL){
            if(root->right->val == root->val + 1)
                dfs(root->right, len+1, res);
            else
                dfs(root->right, 1, res);
        }
    }
};