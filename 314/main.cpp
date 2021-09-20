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
    map<int, vector<int>> record;
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        levelOrder(root);
        vector<vector<int>> res;
        for(auto r = record.begin(); r!= record.end(); ++r){
            res.push_back(r->second);
        }
        return res;
    }

    // void preorder(TreeNode* node, int idx){
    //     if(node == NULL) return;
    //     // visit node
    //     if(record.find(idx) != record.end()){
    //         record[idx].push_back(node->val);
    //     }else{
    //         vector<int> tmp;
    //         tmp.push_back(node->val);
    //         record.insert({idx, tmp});
    //     }
    //     preorder(node->left, idx-1);
    //     preorder(node->right, idx+1);
    // }
    void levelOrder(TreeNode* root){
        if(root == NULL)
            return;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int idx = q.front().second;
            q.pop();
            if(record.find(idx) != record.end()){
                record[idx].push_back(node->val);
            }else{
                vector<int> tmp;
                tmp.push_back(node->val);
                record.insert({idx, tmp});
            }
            if(node->left != NULL)
                q.push({node->left, idx-1});
            if(node->right != NULL)
                q.push({node->right, idx + 1});
        }
    }
};