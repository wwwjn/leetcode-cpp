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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    unordered_map<TreeNode*, TreeNode*> parent;
    queue<TreeNode*> record;

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root, NULL);
        record.push(target);
        unordered_set<TreeNode*> visited;
        findDistanceK(target, k, visited);
        vector<int> res;
        while(!record.empty()){
            TreeNode* cur = record.front();
            res.push_back(cur->val);
            record.pop();
        }
        return res;

    }
    void findDistanceK(TreeNode* node, int k, unordered_set<TreeNode*>& visited){
        if(k == 0){
            return;
        }
        // k >= 1
        findDistanceK(node, k-1, visited);
        int s = record.size();
        for(int i = 0; i< s; i++){
            TreeNode* cur = record.front();
            record.pop();
            visited.insert(cur);
            // add those node with distance 1 from 'cur'
            if(cur->left != NULL && visited.find(cur->left) == visited.end())
                record.push(cur->left);
            if(cur->right != NULL && visited.find(cur->right) == visited.end())
                record.push(cur->right);
            if(parent[cur] != NULL && visited.find(parent[cur]) == visited.end())
                record.push(parent[cur]);
        }
        return;
    }
    void dfs(TreeNode* root, TreeNode* p){
        if(root == NULL) return;
        dfs(root->left, root);
        parent.insert(make_pair(root, p));
        dfs(root->right, root);
    }
};