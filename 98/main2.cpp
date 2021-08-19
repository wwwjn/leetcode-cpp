//
// Created by Jiani Wang on 2021/8/17.
//

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
    bool isValidBST(TreeNode* root) {
        //return bfs(root, LONG_MIN, LONG_MAX);
        return inorderTraverse(root);
    }
    // root的值是否在lower，upper中
    bool bfs(TreeNode* root, long lower, long upper){
        // the value in (lower, upper)
        if(root == NULL) return true;
        if(root->val > lower && root->val < upper)
            return bfs(root->left, lower, root->val) && bfs(root->right, root->val, upper);
        else
            return false;
    }
    bool inorderTraverse(TreeNode* root){
        if(root == NULL){
            return true;
        }
        // 中序遍历的非递归写法
        stack<TreeNode*> record;
        TreeNode* ptr = root;
        long number = LONG_MIN;
        while(!record.empty() || ptr != NULL){
            while(ptr != NULL){
                record.push(ptr);
                ptr = ptr->left;
            }
            // pop
            ptr = record.top();
            record.pop();
            if(ptr->val <= number)
                return false;
            number = ptr->val;
            ptr = ptr->right;
        }
        return true;
    }
};