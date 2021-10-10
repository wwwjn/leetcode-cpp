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
    unordered_map<TreeNode*, int> depth;
    int maxDepth= 0;
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {

        dfs(root, 0);
        // find common parent
        return findCommonParent(root);
    }
    void dfs(TreeNode* node, int d){
        if(node != NULL){
            depth.insert({node, d});
            if(d > maxDepth) maxDepth = d;
            dfs(node->left, d+1);
            dfs(node->right, d+1);
        }
    }
    TreeNode* findCommonParent(TreeNode* root){
        if(root == NULL || depth[root] == maxDepth)
            return root;
        TreeNode* left = findCommonParent(root->left);
        TreeNode* right = findCommonParent(root->right);
        if(left != NULL && right == NULL){
            return left;
        }else if(left == NULL && right != NULL){
            return right;
        }else if(left != NULL && right != NULL){
            return root;
        }else return NULL;
    }
};