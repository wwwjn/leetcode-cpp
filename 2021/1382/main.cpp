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
    vector<int> val;
public:
    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }
        inorder(root->left);
        val.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* build(vector<int> val, int l, int r){
        // build from [l..r]
        if(l > r)
            return NULL;
        if(l == r)
            return new TreeNode(val[l]);
        int mid = (l+r)/2;
        TreeNode* ret = new TreeNode(val[mid]);
        ret->left = build(val, l, mid-1);
        ret->right = build(val, mid+1, r);
        return ret;
    }


    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return build(val, 0, val.size()-1);
    }
};
