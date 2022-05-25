//
// Created by Jiani Wang on 2021/8/19.
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> record;
        if(root == NULL){
            return res;
        }
        record.push(root);
        while(!record.empty()){
            int level_size = record.size();
            for(int i =0; i< level_size; i++){
                TreeNode* node = record.front();
                record.pop();
                if(i == level_size -1){
                    res.push_back(node->val);
                }
                if(node->left != NULL)
                    record.push(node->left);
                if(node->right != NULL){
                    record.push(node->right);
                }
            }
        }
        return res;
    }
};