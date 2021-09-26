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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        if(root->left == NULL && root->right == NULL){
            vector<int> tmp;
            tmp.push_back(root->val);
            res.push_back(tmp);
            return res;
        }
        vector<vector<int>> left = findLeaves(root->left);
        vector<vector<int>> right = findLeaves(root->right);
        int i=0;
        while(i < left.size() || i < right.size()){
            vector<int> vec1, vec2;
            if(i < left.size()) vec1 = left[i];
            if(i < right.size()) vec2 = right[i];
            vec1.insert(vec1.end(), vec2.begin(), vec2.end());
            res.push_back(vec1);
            i++;
        }
        vector<int> tmp;
        tmp.push_back(root->val);
        res.push_back(tmp);
        return res;
    }
};